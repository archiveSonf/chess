#include "board.h"
#include "../env.h"
#include <stdlib.h>

joueur player= player1;

void write_hit(char hit[4]){
  Hit *new_hit=malloc(sizeof(Hit));
  new_hit->player=player;
  player=player==player1?player2:player1;
  new_hit->note=7;//TODO: convertir le coup en note
  new_hit->numero_coup=++Game.nombre_de_coup;
  new_hit->hit=hit;
  new_hit->previous_hit=Game.last_hit;
  Game.last_hit=new_hit;

  //Rédaction des 7 derniers coups
  CurserPos.row=zone_old_hit_row;
  CurserPos.col=zone_old_hit_col;
  Hit *current_hit=Game.last_hit;
  for (int i=0;i<14;i++){
    if(current_hit!=NULL){
      CurserPos.col=zone_old_hit_col+14*current_hit->player;
      start_style(cP0,sans_fond);
      draw(1,"#%d %s",current_hit->numero_coup,current_hit->hit);
      end_style();
      current_hit=current_hit->previous_hit;
      if(i%2==1){CurserPos.row++;}
    }else{
      break;
    }
  } 
}

void SaveGame(char hit[4]){
  // TODO: sauvegarder les coups dans un fichier
}