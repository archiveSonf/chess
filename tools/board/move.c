#include "board.h"
#include "../env.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

enum State{
  Valid,
  InValid,
  Neutral
};

//Présentation du move
void output(char _move[4],enum State state,joueur j){
  CurserPos.row=zone_mv_row;
  CurserPos.col=zone_mv_col;
  char* background=sP;
  if(j==1){
    background=sC;
  }
  if(state==Valid){
    background=sG;
  }else if(state==InValid){
    background=sR;
  }
  start_style(cBl,background);
  draw(1,"%c%c",_move[0],_move[1]);
  start_style(cB,sans_fond);
  draw(0," %s  ",to_from);
  start_style(cBl,background);
  draw(0,"%c%c",_move[2],_move[3]);
  end_style();
  CurserPos.X-=2;
}

int verifInput(int type,char keyCode){
  if(type==0)
    return !(keyCode=='a'||keyCode=='b'||keyCode=='c'||keyCode=='d'||keyCode=='e'||keyCode=='f'||keyCode=='g'||keyCode=='h');
  return !(keyCode=='1'||keyCode=='2'||keyCode=='3'||keyCode=='4'||keyCode=='5'||keyCode=='6'||keyCode=='7'||keyCode=='8');
}

//Effectuer un mouvement
Move getMove(joueur joueur){
  int isValide=0;
  char _move[4]="    ";
  Move mv;
  output(_move,Neutral,joueur);
  send_msg(MSG_INFO,"Entrez le mouvement");
  for(int i=0;i<5;i++){
    char key;
    if(i<4){
      do{
        key=(char)getKey();
        _move[i]=' ';
        output(_move,Neutral,joueur);
        send_msg(MSG_INFO,"Entrez le mouvement");

        if(key==backspace){
          i=i-1==-1?0:i-1;
          _move[i]=' ';
          output(_move,Neutral,joueur);
          send_msg(MSG_INFO,"Entrez le mouvement");
        }
      }while(verifInput(i%2,key));
      _move[i]=key;
      output(_move,Neutral,joueur);
      send_msg(MSG_INFO,"Entrez le mouvement");
      if(i==1){
        int _case=plateau[56-(int)_move[1]][(int)_move[0]-97];
        if(_case==cv){
          output(_move,InValid,joueur);
          i--;
          send_msg(MSG_ERROR,"Cette case est vide");
        }else if(_case%2!=joueur){
          output(_move,InValid,joueur);
          i--;
          send_msg(MSG_ERROR,"Cette figurine ne vous appartient pas");
        }
      }
    }else{
      do{
        key=(char)getKey();
        if(key==backspace){
          i=2;
          _move[3]=' ';
          output(_move,Neutral,joueur);
          send_msg(MSG_INFO,"Entrez le mouvement");
        }
      }while(key!=key_enter&&key!=backspace);
      if(key==key_enter){
        
        int mvtV = coup_valide(56-(int)_move[1],(int)_move[0]-97,56-(int)_move[3],(int)_move[2]-97);
        int roi_warning=Leroi(56-(int)_move[1],(int)_move[0]-97,56-(int)_move[3],(int)_move[2]-97);
        int checkmate_blanc = echec_et_mat_blanc(56-(int)_move[1],(int)_move[0]-97,56-(int)_move[3],(int)_move[2]-97);
        int checkmate_noir = echec_et_mat_noir(56-(int)_move[1],(int)_move[0]-97,56-(int)_move[3],(int)_move[2]-97);

        if(!mvtV){
          output(_move,InValid,joueur);
          i=2;
          send_msg(MSG_ERROR,"Ce mouvement est invalide");
        }else if(roi_warning){
          output(_move,InValid,joueur);
          i=2;
          send_msg(MSG_ERROR,"Votre roi est en danger !");
        }else if(mvtV && !roi_warning && !checkmate_blanc && !checkmate_noir){
          output(_move,Valid,joueur);
          send_msg(MSG_SUCCESS,"Mouvement valide");
          mv=(Move){NULL,
            {(int)_move[0]-97,56-(int)_move[1]},
            {(int)_move[2]-97,56-(int)_move[3]}};
          mv.string=malloc(4*sizeof(char));
          strcpy(mv.string,_move);
        }
        else if(mvtV && !roi_warning && (checkmate_blanc || checkmate_noir)){
          output(_move,Valid,joueur);
          send_msg(MSG_SUCCESS,"ECHEC ET MAT");
          mv=(Move){NULL,
            {(int)_move[0]-97,56-(int)_move[1]},
            {(int)_move[2]-97,56-(int)_move[3]}};
          mv.string=malloc(4*sizeof(char));
          strcpy(mv.string,_move);
        }
      }
    }
  }
  return mv;
}
