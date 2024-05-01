#include "../tools.h"
#include <stdlib.h>
#include <jansson.h>
#include <string.h>

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