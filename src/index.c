#include "index.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../tools/tools.h"

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
          char j1[10],j2[10];
          CurserPos.row++;
          draw(1,"Premier joueur, vueillez entrez votre pseudo :");
          scanf("%s",j1);getKey();
          CurserPos.Y++;CurserPos.X=0;
          CurserPos.row++;
          draw(1,"Deuxième joueur, vueillez entrez votre pseudo :");
          scanf("%s",j2);getKey();
          CurserPos.Y++;CurserPos.X=0;
          time_t t=time(NULL);
          struct tm tm=*localtime(&t);
          int id1=tm.tm_min+tm.tm_sec,
            id2=id1+tm.tm_hour;
          Joueur p1={id1,"",0},
            p2={id2,"",0};
          strcpy(p1.pseudo,j1);
          strcpy(p2.pseudo,j2);
          runGame(NULL,&p1,&p2);
        }else{
          send_msg(MSG_WARNING,"Cette option est une idée d'implémentaion future");
          getKey();
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
        GAME *game;
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
          game=LoadGame(p,BD_GAMES);
          if(game==NULL){
            send_msg(MSG_ERROR,"Cette partie n'existe pas");
            getKey();
            break;
          }
        }else{
          int row=CurserPos.row;
          do{
            CurserPos.row=row;
            CurserPos.col=4;
            draw(1,"\033[2KEntrez l'identifiant de la partie à charger : ");
            char _p[4];
            scanf("%s",_p);getKey();
            p=atoi(_p);
            CurserPos.Y++;
            CurserPos.X=0;
            game=LoadGame(p,BD_GAMES);
            if(game==NULL){
              send_msg(MSG_ERROR,"Cette partie n'existe pas");
              getKey();

              send_msg(MSG_INFO,"Souhaitez-vous réessayer ? (O/N)");
              CurserPos.X-=1;
              int r;
              do{
                r=getKey();
              } while (r!='O' && r!='N');
              if(r=='N'){
                break;
              }
            }
          }while(game==NULL);
          if(game==NULL){
            break;
          }
        }

        runGame(game,NULL,NULL);
        break;
      case analyz_old_game:
        send_msg(MSG_WARNING,"Cette option est une idée d'implémentaion future");
        getKey();
        break;
      case see_scores:
        send_msg(MSG_WARNING,"Cette option est une idée d'implémentaion future");
        getKey();
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