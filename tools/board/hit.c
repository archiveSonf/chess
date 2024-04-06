#include "board.h"
#include "../env.h"
#include <stdlib.h>
#include <jansson.h>
#include <string.h>


joueur player= player1;

void write_hit(char *hit){
  Hit *new_hit=malloc(sizeof(Hit));
  new_hit->player=player;
  player=player==player1?player2:player1;
  new_hit->note=77;//TODO: convertir le coup en note
  new_hit->numero_coup=++Game.nombre_de_coup;
  new_hit->hit=hit;
  new_hit->previous_hit=Game.last_hit;
  Game.last_hit=new_hit;
  
  //Récupère le plateau
  memcpy(Game.plateau,plateau,sizeof(plateau));


  //Rédaction des 7 derniers coups
  CurserPos.row=zone_old_hit_row;
  CurserPos.col=zone_old_hit_col;
  Hit *current_hit=Game.last_hit;
  for (int i=0;i<14;i++){
    if(current_hit!=NULL){
      int num=current_hit->numero_coup;
      if(i==0&&num%2==1){
        CurserPos.col=zone_old_hit_col+19;
        start_style(cW0,sans_fond);
        draw(1,"               ");
        end_style();
      }
      CurserPos.col=zone_old_hit_col+19*(1-num%2);

      start_style(cW0,sans_fond);
      draw(1,"#%d %s ",current_hit->numero_coup,current_hit->hit);
      char* color=cG;
      if(current_hit->note<70&&current_hit->note>=40){
        color=cY;
      }else if(current_hit->note<40){
        color=cR;
      }
      start_style(color,sans_fond);
      draw(0,"%d",current_hit->note);
      end_style();
      current_hit=current_hit->previous_hit;
      if(num%2==1){CurserPos.row++;}
    }else{
      break;
    }
  } 
}

int SaveGame(char *db_file){
  json_t *db_games;
  json_error_t error;
  db_games=json_load_file(db_file,0,&error);
  
  if(!db_games||!json_is_array(db_games)){
    db_games=json_array();
  }else{
    size_t i;
    json_t *value;
    json_array_foreach(db_games,i,value){
      int id=json_integer_value(json_object_get(value,"id"));
      if(id==Game.id){
        json_array_remove(db_games,i);
        break;
      }
    }
  }

  json_t *j1=json_object();
  json_object_set_new(j1,"id",json_integer(Game.players.player1->id));
  json_object_set_new(j1,"pseudo",json_string(Game.players.player1->pseudo));
  json_object_set_new(j1,"score",json_integer(Game.players.player1->score));
  json_t *j2=json_object();
  json_object_set_new(j2,"id",json_integer(Game.players.player2->id));
  json_object_set_new(j2,"pseudo",json_string(Game.players.player2->pseudo));
  json_object_set_new(j2,"score",json_integer(Game.players.player2->score));

  json_t *hits=json_array();
  Hit *current_hit=Game.last_hit;
  while(current_hit!=NULL){
    json_t *hit=json_object();
    json_object_set_new(hit,"numero_coup",json_integer(current_hit->numero_coup));
    json_object_set_new(hit,"hit",json_string(current_hit->hit));
    json_object_set_new(hit,"note",json_integer(current_hit->note));
    json_array_append_new(hits,hit);
    current_hit=current_hit->previous_hit;
  }

  json_t *game=json_object();
  json_object_set_new(game,"id",json_integer(Game.id));
  json_object_set_new(game,"player1",j1);
  json_object_set_new(game,"player2",j2);
  json_object_set_new(game,"nombre_de_coup",json_integer(Game.nombre_de_coup));
  if(Game.vainqueur==NULL){
    json_object_set_new(game,"vainqueur",json_string("null"));
  }else{
    json_object_set_new(game,"vainqueur",json_string(Game.vainqueur->pseudo));
  }
  json_t *plateau=json_array();
  for(int i=0;i<8;i++){
    json_t *row=json_array();
    for(int j=0;j<8;j++){
      json_array_append_new(row,json_integer(Game.plateau[i][j]));
    }
    json_array_append_new(plateau,row);
  }
  json_object_set_new(game,"plateau",plateau);
  json_object_set_new(game,"hits",hits);

  json_array_append_new(db_games,game);

  FILE *db= fopen(db_file,"w");
  if(!db){
    send_msg(MSG_ERROR,"Impossible d'ouvrir le fichier de sauvegarde");
    return 0;
  }

  json_dumpf(db_games,db,JSON_INDENT(2));
  fclose(db);
  json_decref(db_games);
  return 1;
}

GAME *LoadGame(int id,char *db_file){
  json_t *db_games;
  json_error_t error;
  db_games=json_load_file(db_file,0,&error);
  GAME *game=malloc(sizeof(GAME));
  if(!db_games||!json_is_array(db_games)){
    game=NULL;
  }else{
    size_t i;
    json_t *value;
    json_array_foreach(db_games,i,value){
      int _id=json_integer_value(json_object_get(value,"id"));
      if(id==_id){
        game->id=_id;
        game->nombre_de_coup=json_integer_value(json_object_get(value,"nombre_de_coups"));

        Joueur *j1=malloc(sizeof(Joueur)),
                *j2=malloc(sizeof(Joueur));
        j1->id=json_integer_value(json_object_get(json_object_get(value,"player1"),"id"));
        memcpy(j1->pseudo,json_string_value(json_object_get(json_object_get(value,"player1"),"pseudo")),sizeof(j1->pseudo));
        j1->score=json_integer_value(json_object_get(json_object_get(value,"player1"),"score"));
        j2->id=json_integer_value(json_object_get(json_object_get(value,"player2"),"id"));
        memcpy(j2->pseudo,json_string_value(json_object_get(json_object_get(value,"player2"),"pseudo")),sizeof(j2->pseudo));
        j2->score=json_integer_value(json_object_get(json_object_get(value,"player2"),"score"));

        game->players.player1=j1;
        game->players.player2=j2;

        json_t *hits=json_object_get(value,"hits");
        size_t j;
        json_t *hit;
        json_array_foreach(hits,j,hit){
          Hit *new_hit=malloc(sizeof(Hit));
          new_hit->numero_coup=json_integer_value(json_object_get(hit,"numero_coup"));
          new_hit->hit=malloc(4*sizeof(char));
          memcpy(new_hit->hit,json_string_value(json_object_get(hit,"hit")),4);
          new_hit->note=json_integer_value(json_object_get(hit,"note"));
          new_hit->previous_hit=game->last_hit;
          game->last_hit=new_hit;
        }

        int plateau[8][8];
        json_t *plateau_json=json_object_get(value,"plateau");
        for(int i=0;i<8;i++){
          json_t *row=json_array_get(plateau_json,i);
          for(int j=0;j<8;j++){
            plateau[i][j]=json_integer_value(json_array_get(row,j));
          }
        }
        memcpy(game->plateau,plateau,sizeof(plateau));

        char *vainqueur=json_string_value(json_object_get(value,"vainqueur"));
        if(strcmp(vainqueur,"null")!=0){
          if(strcmp(vainqueur,j1->pseudo)==0){
            game->vainqueur=j1;
          }else{
            game->vainqueur=j2;
          }
        }else{
          game->vainqueur=NULL;
        }
        break;
      }
    }
  }
  json_decref(db_games);
  return game;
}

Partie *LoadGames(char *db_file){
  json_t *db_games;
  json_error_t error;
  db_games=json_load_file(db_file,0,&error);
  Partie *partie=malloc(sizeof(Partie));
  if(!db_games||!json_is_array(db_games)){
    partie=NULL;
  }else{
    size_t i;
    json_t *value;
    json_array_foreach(db_games,i,value){
      Partie *new_partie=malloc(sizeof(Partie));
      new_partie->id=json_integer_value(json_object_get(value,"id"));
      new_partie->player1=malloc(20*sizeof(char));
      memcpy(new_partie->player1,json_string_value(json_object_get(json_object_get(value,"player1"),"pseudo")),10);
      new_partie->player2=malloc(20*sizeof(char));
      memcpy(new_partie->player2,json_string_value(json_object_get(json_object_get(value,"player2"),"pseudo")),10);
      new_partie->next=partie->next;
      partie->next=new_partie;
    }
  }
} 
