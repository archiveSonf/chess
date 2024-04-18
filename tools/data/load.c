#include <stdlib.h>
#include <jansson.h>
#include <string.h>
#include "../tools.h"


GAME *LoadGame(int id,char *db_file){
  json_t *db_games;
  json_error_t error;
  db_games=json_load_file(db_file,0,&error);
  GAME *game=malloc(sizeof(GAME));
  if(db_games&&json_is_array(db_games)){
    size_t i;
    json_t *value;
    int trouve=0;
    json_array_foreach(db_games,i,value){
      int _id=json_integer_value(json_object_get(value,"id"));
      if(id==_id){
        trouve=1;
        game->id=id;
        game->nombre_de_coup=json_integer_value(json_object_get(value,"nombre_de_coup"));
        
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
        Hit *curr;
        json_array_foreach(hits,j,hit){
          Hit *new_hit=malloc(sizeof(Hit));
          new_hit->numero_coup=json_integer_value(json_object_get(hit,"numero_coup"));
          new_hit->hit=malloc(5*sizeof(Hit));
          memcpy(new_hit->hit,json_string_value(json_object_get(hit,"hit")),5);
          new_hit->note=json_integer_value(json_object_get(hit,"note"));
          if(j==0){
            game->last_hit=new_hit;
            curr=game->last_hit;
          }else{
            curr->previous_hit=new_hit;
            curr=new_hit;
          }
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

        const char *vainqueur=json_string_value(json_object_get(value,"vainqueur"));
        if(strcmp(vainqueur,"null")!=0){
          if(strcmp(vainqueur,j1->pseudo)==0){
            game->vainqueur=j1;
          }else{
            game->vainqueur=j2;
          }
        }
        break;
      }
    }
    if(!trouve){
      game=NULL;
    }
  }else{
    game=NULL;
  }
  json_decref(db_games);
  return game;
}

Partie *LoadGames(char *db_file,int *nb_partie){
  json_t *db_games;
  json_error_t error;
  db_games=json_load_file(db_file,0,&error);
  Partie *partie=malloc(sizeof(Partie));
  if(!db_games||!json_is_array(db_games)){
    partie=NULL;
  }else{
    size_t i;
    json_t *value;
    Partie *curr;
    json_array_foreach(db_games,i,value){
      Partie *new_partie=malloc(sizeof(Partie));
      new_partie->id=json_integer_value(json_object_get(value,"id"));
      new_partie->player1=malloc(20*sizeof(char));
      memcpy(new_partie->player1,json_string_value(json_object_get(json_object_get(value,"player1"),"pseudo")),11);
      new_partie->player2=malloc(20*sizeof(char));
      memcpy(new_partie->player2,json_string_value(json_object_get(json_object_get(value,"player2"),"pseudo")),11);
      if(i==0){
        partie=new_partie;
        partie->next=NULL;
        partie->previous=NULL;
        curr=partie;
      }else{
        curr->next=new_partie;
        new_partie->previous=curr;
        curr=new_partie;
      }
    }
    *nb_partie=(int) i;
    curr->next=partie;
    partie->previous=curr;
  }
  return partie;
}