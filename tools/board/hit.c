#include "../tools.h"
#include <stdlib.h>
#include <jansson.h>
#include <string.h>


joueur player= joueur1;

void write_hit(char *hit){
  Hit *new_hit=malloc(sizeof(Hit));
  new_hit->player=player;
  player=player==joueur1?joueur2:joueur1;
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
