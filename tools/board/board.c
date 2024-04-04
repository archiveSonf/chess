#include "board.h"
#include "../env.h"
#include <stdio.h>
#include <time.h>

#ifndef PlateauPosition 
#define plateau_col 0 
#define plateau_row 2 
#endif

int plateau[8][8] = {
	{ctb, ccb, cfb, cdb, crb, cfb, ccb, ctb},
	{cpb, cpb, cpb, cpb, cpb, cpb, cpb, cpb},
	{cv, cv, cv, cv, cv, cv, cv, cv},
	{cv, cv, cv, cv, cv, cv, cv, cv},
	{cv, cv, cv, cv, cv, cv, cv, cv},
	{cv, cv, cv, cv, cv, cv, cv, cv},
	{cpn, cpn, cpn, cpn, cpn, cpn, cpn, cpn},
	{ctn, ccn, cfn, cdn, crn, cfn, ccn, ctn}};

void drawplateau(int plateau[8][8]){
  CurserPos.row = plateau_row;
  CurserPos.col = plateau_col;
  draw(1,"");
  int num = 8;
  for (int i=0; i<8;i++){
    printf("%d ",num);
    for (int j=0; j<8;j++){
        drawpion(plateau[i][j], i , j);
    }
    printf("\n");
    num--;
  }
  printf("   a   b   c   d   e   f   g   h \n");
}
    
	

void initGame(Joueur player1,Joueur player2){
  time_t t=time(NULL);
  //struct tm 
  //struct _Game Game = {1,{player1,player2},0,{},{}};
    
  drawplateau(plateau);
}