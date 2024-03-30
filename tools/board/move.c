#include "board.h"
#include "move.h"
#include "../style.h"
#include "../small_tools.h"
#include "../env.h"
#include <string.h>

#ifndef ZONE_MOVE 
#define zone_mv_col 10 /*Colonne de la zone de rédaction du mouvement*/
#define zone_mv_row 10 /*Ligne de la zone de rédaction du mouvement*/
#endif

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
  draw(1,"%s%s",_move[0],_move[1]);
  end_style();
  draw(0," %s ",to_from);
  start_style(cBl,sC);
  draw(0,"%s%s",_move[2],_move[3]);
  end_style();
}

int verifInput(int type,int keyCode){
  if(type==0)
    return !(keyCode=='a'||keyCode=='b'||keyCode=='c'||keyCode=='d'||keyCode=='e'||keyCode=='f'||keyCode=='g'||keyCode=='h');
  return !(keyCode==1||keyCode==2||keyCode==3||keyCode==4||keyCode==5||keyCode==6||keyCode==7||keyCode==8);
}

//Effectuer un mouvement
struct Move doMove(enum Joueur joueur){
  int isValide=0;
  char _move[4]="    ";
  struct Move mv;
  output(_move,Neutral);
  for(int i=0;i<5;i++){
    int key;
    if(key<4){
      do{
        key=getKey();
        if(key==backspace){
          i=i-1==-1?0:i-1;
          _move[i]=' ';
          output(_move,Neutral);
        }
      }while(verifInput(i%2,key));
      _move[i]=key;
      output(_move,Neutral);
      if(i==1){
        int _case=plateau[(int)_move[0]-97][(int)_move[1]-1];
        if(_case==cv){
          output(_move,InValid);
          i--;
          //TODO: Afficher un message d'erreur (Case vide)
        }else if(_case%2==joueur){
          output(_move,InValid);
          i--;
          //TODO: Afficher un message d'erreur (Ce n'est pas votre pièce)
        }else{
          output(_move,Valid);
        }
      }
      if(i==3){
        int _to=plateau[(int)_move[0]-97][(int)_move[1]-1];
        int _from=plateau[(int)_move[2]-97][(int)_move[3]-1];
        //TODO: Vérifier si le mouvement est valide
      }
    }else{
      do{
        key=getKey();
        if(key==backspace){
          i=i-1==-1?0:i-1;
          _move[i]=' ';
          output(_move,Neutral);
        }
      }while(key!=key_enter);
      mv=(struct Move){{_move[0]-97,_move[1]},{_move[2]-97,_move[3]}};
    }
  }
  return mv;
}