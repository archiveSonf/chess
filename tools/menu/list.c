#include <stdio.h>
#include "../tools.h"

//Permet de proposer plusieurs options
options select_list(char* q,int nbr_opts,option opts[]){
  int first_row=CurserPos.row+2,
      last_row=first_row+nbr_opts-1;

  start_style(cG,sans_fond);
  draw(1,"++ %s ++", q);
  CurserPos.row+=2;
  start_style(cB,sans_fond);
  draw(1,"%s %s",this,opts[0].txt);
  CurserPos.X-=2;
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
        CurserPos.X-=2;
        end_style();
        break;
      case key_down:
        draw(1,"  %s",opts[CurserPos.row-first_row].txt);
        CurserPos.row=(CurserPos.row==last_row)?first_row:CurserPos.row+1;
        start_style(cB,sans_fond);
        draw(1,"%s %s",this,opts[CurserPos.row-first_row].txt);
        CurserPos.X-=2;
        end_style();
        break;
    }
    choice=CurserPos.row-first_row;
    input=getKey();
  }
  
  CurserPos.row=last_row+1;

  return opts[choice].id;
}

//Permet de proposer la liste de partie
int select_partie(Partie *partie,int nbr_partie){
  int res;
  Partie *curr;
  int keyCode;
  start_style(cG,sans_fond);
  draw(1,"++ Liste des parties ++");
  end_style();
  CurserPos.row+=2;
  CurserPos.col-=4;
  int first_row=CurserPos.row,
    col=CurserPos.col,
    nbr_elems=7>nbr_partie?nbr_partie:7;

  send_msg(MSG_INFO,"Q: Quitter");

  do{
    CurserPos.row=first_row;
    CurserPos.col=col;
    //effacer l'ancienne liste
    for(int i=0;i<nbr_elems;i++){
      draw(1,"                                        ");
      CurserPos.row++;
    }
    CurserPos.row=first_row;

    curr=partie;
    for(int i=0;i<nbr_elems;i++){
      if(i==0){
        CurserPos.col-=2;
        start_style(cB,sans_fond);
        draw(1,"%s id: %d -> %s vs %s",this,curr->id,curr->player1,curr->player2);
        end_style();
        CurserPos.col+=2;
        CurserPos.X-=2;
        res=curr->id;
      }else{
        draw(1,"id: %d -> %s vs %s",curr->id,curr->player1,curr->player2);
      }
      CurserPos.row++;
      curr=curr->next;
    }
    
    do{
      keyCode=getKey();
      switch(keyCode){
        case key_up:
          partie=partie->previous;
          break;
        case key_down:
          partie=partie->next;
          break;
        case 'Q':
          return -1;
      }
    }while(keyCode!=key_enter&&keyCode!=key_up&&keyCode!=key_down);
  }while(keyCode!=key_enter);

  return res;
}