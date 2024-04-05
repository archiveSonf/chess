#include "board.h"
#include "../env.h"
#include <string.h>
#include <stdlib.h>

enum State{
  Valid,
  InValid,
  Neutral
};

//Présentation du move
void output(char _move[4],enum State state){
  CurserPos.row=zone_mv_row;
  CurserPos.col=zone_mv_col;
  char* background=sC;
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
  output(_move,Neutral);
  for(int i=0;i<5;i++){
    char key;
    if(i<4){
      do{
        key=(char)getKey();
        _move[i]=' ';
        output(_move,Neutral);
        if(key==backspace){
          i=i-1==-1?0:i-1;
          _move[i]=' ';
          output(_move,Neutral);
        }
      }while(verifInput(i%2,key));
      _move[i]=key;
      output(_move,Neutral);
      if(i==1){
        int _case=plateau[56-(int)_move[1]][(int)_move[0]-97];
        if(_case==cv){
          output(_move,InValid);
          i--;
          //TODO: Afficher un message d'erreur (Case vide)
        }else if(_case%2!=joueur){
          output(_move,InValid);
          i--;
          //TODO: Afficher un message d'erreur (Ce n'est pas votre pièce)
        }
      }
    }else{
      do{
        key=(char)getKey();
        if(key==backspace){
          i=2;
          _move[3]=' ';
          output(_move,Neutral);
        }
      }while(key!=key_enter&&key!=backspace);
      if(key==key_enter){
        //int _to=plateau[(int)_move[1]-49][(int)_move[0]-97];
        //int _from=plateau[(int)_move[3]-49][(int)_move[2]-97];
        int verif=1;//TODO: Vérifier si le mouvement est valide
        if(verif){
          output(_move,Valid);
          mv=(Move){NULL,
            {(int)_move[0]-97,56-(int)_move[1]},
            {(int)_move[2]-97,56-(int)_move[3]}};
          mv.string=malloc(4*sizeof(char));
          strcpy(mv.string,_move);
        }else{
          output(_move,InValid);
          i=2;
          //TODO: Afficher un message d'erreur (Mouvement invalide)
        }
      }
    }
  }
  return mv;
}
