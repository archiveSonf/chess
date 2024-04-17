#include <stdio.h>
#include "../env.h"
#include "menu.h"

//Permet de proposer plusieurs options
options select_list(char* q,int nbr_opts,option opts[]){
  int first_row=CurserPos.row+2,
      last_row=first_row+nbr_opts-1;

  start_style(cG,sans_fond);
  draw(1,"++ %s ++", q);
  CurserPos.row+=2;
  start_style(cB,sans_fond);
  draw(1,"%s %s",this,opts[0].txt);
  end_style();
  for(int i=1;i<nbr_opts;i++){
    CurserPos.row++;
    draw(1,"  %s",opts[i].txt);
  }
  CurserPos.row=first_row;

  int choice=0;
  int input=getKey();
  while (input!=key_enter){
    switch(input){
      case key_up:
        draw(1,"  %s",opts[CurserPos.row-first_row].txt);
        CurserPos.row=(CurserPos.row==first_row)?last_row:CurserPos.row-1;
        start_style(cB,sans_fond);
        draw(1,"%s %s",this,opts[CurserPos.row-first_row].txt);
        end_style();
        break;
      case key_down:
        draw(1,"  %s",opts[CurserPos.row-first_row].txt);
        CurserPos.row=(CurserPos.row==last_row)?first_row:CurserPos.row+1;
        start_style(cB,sans_fond);
        draw(1,"%s %s",this,opts[CurserPos.row-first_row].txt);
        end_style();
        break;
    }
    choice=CurserPos.row-first_row;
    input=getKey();
  }
  
  CurserPos.row=last_row+1;

  return opts[choice].id;
}