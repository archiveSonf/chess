#include <stdio.h>
#include "../env.h"
#include "../small_tools.h"
#include "../style.h"
#include "menu.h"

//Permet de proposer plusieurs options
enum options select_list(char* q,int nbr_opts,struct option opts[]){
  CurserPos.row++;
  CurserPos.col=0;
  int first_row=CurserPos.row+2,
      last_row=first_row+nbr_opts-1;
  draw(1,"%s :\n\n", q);
  start_style(cB,sans_fond);
  draw(0,"%s",select);
  draw(0," %s\n",opts[0].txt);
  end_style();
  for(int i=1;i<nbr_opts;i++){
    draw(0,"  %s\n",opts[i].txt);
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
        draw(1,"%s",select);
        draw(0," %s",opts[CurserPos.row-first_row].txt);
        end_style();
        break;
      case key_down:
        draw(1,"  %s",opts[CurserPos.row-first_row].txt);
        CurserPos.row=(CurserPos.row==last_row)?first_row:CurserPos.row+1;
        start_style(cB,sans_fond);
        draw(1,"%s",select);
        draw(0," %s",opts[CurserPos.row-first_row].txt);
        end_style();
        break;
    }
    choice=CurserPos.row-first_row;
    input=getKey();
  }
  
  CurserPos.row=last_row+1;
  CurserPos.col=0;
  return opts[choice].id;
}