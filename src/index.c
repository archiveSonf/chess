#include <stdio.h>
#include <stdlib.h>
#include "../tools/env.h"
#include "../tools/menu/menu.h"
#include "../tools/board/board.h"

void menu(){
  init();
  option opts[5]={
    {run_game,"Lancer une partie"},
    {load_game,"Charger une partie"},
    {analyz_old_game,"Analyser les anciennes parties"},
    {see_scores,"Voir le tableau des scores"},
    {quitter,"Quitter le jeu"}
  };
  CurserPos.row+=2;
  CurserPos.col=4;
  options res=select_list("Menu",5,opts);

  switch(res){
    case run_game:
      init();
      CurserPos.row++;
      CurserPos.col=4;
      res=select_bool("Quels types de partie voulez-vous jouer ?",
        (option[2]){{run_game_2,"2 joueurs"},{run_game_ia,"contre IA"}});
      if(res==run_game_2){
        runGame(NULL,&(Joueur){1,"Joueur1",0},&(Joueur){2,"Joueur2",0});
      }else{

      }
      break;
    case load_game:
      break;
    case analyz_old_game:
      break;
    case see_scores:
      break;
    case quitter:
      //system("ctrl+z");
      break;
  }
}

void main(){
  Init();

  menu();

  end();
}