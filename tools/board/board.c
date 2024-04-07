#include "board.h"
#include "../env.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

GAME Game = {0,{NULL,NULL},0,NULL,NULL,{{}}};
int plateau[8][8];

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
    
void play(joueur j){
  Move mv=getMove(j);
  plateau[mv.from.y][mv.from.x]=plateau[mv.to.y][mv.to.x];
  plateau[mv.to.y][mv.to.x]=cv;
  //TODO: fonction d'évolution du pion
  drawplateau(plateau);
  write_hit(mv.string);
}

void runGame(GAME *game,Joueur *player1,Joueur *player2){
  clearScreen();
  
  if(game==NULL){
    time_t t=time(NULL);
    struct tm tm=*localtime(&t);
    int id=tm.tm_year+tm.tm_mon+tm.tm_mday+tm.tm_hour+tm.tm_min+tm.tm_sec;
    Game.id=id;
    Game.players.player1=player1;
    Game.players.player2=player2;
    Game.nombre_de_coup=0;
    Game.vainqueur=NULL;
    Game.last_hit=NULL;

    int _plateau[8][8]={
	    {ctb, ccb, cfb, cdb, crb, cfb, ccb, ctb},
	    {cpb, cpb, cpb, cpb, cpb, cpb, cpb, cpb},
	    {cv, cv, cv, cv, cv, cv, cv, cv},
	    {cv, cv, cv, cv, cv, cv, cv, cv},
	    {cv, cv, cv, cv, cv, cv, cv, cv},
	    {cv, cv, cv, cv, cv, cv, cv, cv},
	    {cpn, cpn, cpn, cpn, cpn, cpn, cpn, cpn},
	    {ctn, ccn, cfn, cdn, crn, cfn, ccn, ctn}};
    memcpy(plateau,_plateau,sizeof(_plateau));
    memcpy(Game.plateau,plateau,sizeof(plateau));
  }else{
    Game=*game;
    memcpy(plateau,Game.plateau,sizeof(Game.plateau));
    player1=Game.players.player1;
    player2=Game.players.player2;
  }

  //place titre de partie
  CurserPos.col=plateau_col+1;
  CurserPos.row=plateau_row-3;
  start_style(cB,sans_fond);
  draw(1,"Identifiant de partie: %d",Game.id);
  end_style();

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
  CurserPos.col=zone_old_hit_col+15;
  draw(1,"    ");
  start_style(cC,sans_fond);
  draw(0,"%s",player2->pseudo);
  end_style();

  //place la zone des options
  CurserPos.col=zone_options_col;
  CurserPos.row=zone_options_row;
  start_style(cW0,sans_fond);
  draw(1,"Enter: Continuer|valider; Q: Quitter;  R: Recommencer;  S: Sauvegarder");

  //TODO: boucle de jeu
  joueur j=joueur1;
  if(Game.nombre_de_coup%2==1){
    j=joueur2;
  }
  char keyCode;
  int out=0;
  while(!out){
    play(j);
    j=j==joueur1?joueur2:joueur1;
    do{
      keyCode=getKey();
      char _k;
      switch(keyCode){
        case 'Q':
          send_msg(MSG_WARNING,"O: confirmer; N: annuler");
          do{
            _k=getKey();
          }while(_k!='O'&&_k!='N');
          keyCode=key_enter;
          if(_k=='O'){
            out=1;
          }
          break;
        case 'R':
          send_msg(MSG_WARNING,"O: confirmer; N: annuler");
          do{
            _k=getKey();
          }while(_k!='O'&&_k!='N');
          keyCode=key_enter;
          if(_k=='O'){
            runGame(NULL,player1,player2);
          }
          break;
        case 'S':
          send_msg(MSG_WARNING,"O: confirmer; N: annuler");
          do{
            _k=getKey();
          }while(_k!='O'&&_k!='N');
          keyCode=key_enter;
          if(_k=='O'){
            int res=SaveGame(BD_GAMES);
            if(res){
              send_msg(MSG_SUCCESS,"Partie sauvegardée");
            }
          }
          break;
      }
    }while(keyCode!=key_enter);
  }

  //TODO: fin de jeu; lancer le menu
}