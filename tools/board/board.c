#include "board.h"
#include "../env.h"
#include <stdio.h>
#include <time.h>
#include <string.h>

GAME Game = {0,{NULL,NULL},0,NULL,NULL};
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
    draw(0,"%d ",num);
    for (int j=0; j<8;j++){
        drawpion(plateau[i][j], i , j);
    }
    draw(0,"\n");
    num--;
  }
  draw(0,"   a   b   c   d   e   f   g   h \n");
}
    
joueur j = player1;
void play(){
  Move mv=getMove(j);
  plateau[mv.from.y][mv.from.x]=plateau[mv.to.y][mv.to.x];
  plateau[mv.to.y][mv.to.x]=cv;
  drawplateau(plateau);
  write_hit(mv.string);
  j=j==player1?player2:player1;
}

void runGame(GAME *game,Joueur *player1,Joueur *player2){
  clearScreen();
  
  if(game==NULL){
    time_t t=time(NULL);
    struct tm tm=*localtime(&t);
    int id=tm.tm_year+1900+tm.tm_mon+tm.tm_mday+tm.tm_hour+tm.tm_min+tm.tm_sec;
    Game.id=id;
    Game.players.player1=player1;
    Game.players.player2=player2;
    Game.nombre_de_coup=0;
  }else{
    Game=*game;
  }

  //place le tableau  
  drawplateau(plateau);

  //place la zone de move
  CurserPos.col=zone_mv_col-6;
  CurserPos.row=zone_mv_row;
  start_style(cB,sans_fond);
  draw(1,"Move:");
  end_style();

  //place la zone de coup
  CurserPos.col=zone_old_hit_col;
  CurserPos.row=zone_old_hit_row-1;
  start_style(cP,sans_fond);
  draw(1,"%s",player1->pseudo);
  CurserPos.col=zone_old_hit_col+10;
  draw(1,"    ");
  draw(0,"%s",player2->pseudo);
  end_style();

  //TODO: boucle de jeu
  while(1){
    play();
  }


}