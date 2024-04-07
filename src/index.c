#include "index.h"
#include <stdio.h>
#include <stdlib.h>
#include "../tools/env.h"
#include "../tools/board/board.h"
#include "../tools/menu/menu.h"
#include <string.h>

void handler(){
  int quit=0;
  do{
    init();
    option opts[5]={
      {run_game,"Lancer une partie"},
      {load_game,"Charger une partie"},
      {analyz_old_game,"Analyser les anciennes parties"},
      {see_scores,"Voir le tableau des scores"},
      {quitter,"Quitter le jeu"}
    };
    CurserPos.row+=3;
    CurserPos.col=4;
    options res=select_list("Menu",5,opts);

    switch(res){
      case run_game:
        init();
        CurserPos.row+=3;
        CurserPos.col=4;
        res=select_bool("Quels types de partie voulez-vous jouer ?",
          (option[2]){{run_game_2,"2 joueurs"},{run_game_ia,"contre IA"}});
        if(res==run_game_2){
          runGame(NULL,&(Joueur){1,"Joueur1",0},&(Joueur){2,"Joueur2",0});
        }else{
          //TODO: algorithme ia
        }
        break;
      case load_game:
        init();
        CurserPos.row+=3;
        CurserPos.col=4;
        res=select_bool("Connaissez vous l'identifiant de la partie ?",
          (option[2]){{load_game_wiht_id,"Oui"},{load_game_select,"Non"}});
        CurserPos.row++;
        int p;
        if(res==load_game_select){
          int nb_partie;
          Partie *partie=LoadGames(BD_GAMES,&nb_partie);
          if(partie==NULL){
            send_msg(MSG_ERROR,"Aucune partie n'a été sauvegardée");
            break;
          }
          init();
          CurserPos.row+=3;
          CurserPos.col=6;
          p=select_partie(partie,nb_partie);
          if(p==-1){
            break;
          }
        }else{
          char id;
          draw(1,"Entrez l'identifiant de la partie à charger :");
          scanf("%s",&id);
          CurserPos.X+=strlen(&id);
          p=atoi(&id);
        }
        GAME *game=LoadGame(p,BD_GAMES);
        if(game==NULL){
          send_msg(MSG_ERROR,"Cette partie n'existe pas");
          break;
        }
        runGame(game,NULL,NULL);
        break;
      case analyz_old_game:
        break;
      case see_scores:
        break;
      case quitter:
        quit=1;
        break;
    }
  }while(!quit);
}

void main(){
  Init();

  handler();

  end();
}