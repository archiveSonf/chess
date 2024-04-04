#include <stdio.h>
#include "../tools/env.h"
#include "../tools/menu/menu.h"
#include "../tools/board/board.h"

void main(){
  init();
  options res=select_bool("Sélectionne une option",(option[2]){{run_game_ia,"option1"},{run_game_2,"option2"}});
  CurserPos.row++;
  CurserPos.col=0;
  draw(1,"Vous avez choisi %d",res);

  res=select_list("Sélectionne une option",7,
    (option[7]){{run_game,"option1"},{run_game_ia,"option2"},{run_game_2,"option3"},{save_game,"option4"},{analyz_old_game,"option5"},{see_scores,"option6"},{quitter,"option7"}});

  CurserPos.row++;
  CurserPos.col=0;
  draw(1,"Vous avez choisi %d",res);

  initGame((Joueur){1,"Joueur1",0},(Joueur){2,"Joueur2",0});

  CurserPos.col=10;
  CurserPos.row=16;
  start_style(cB,sans_fond);
  draw(1,"Move:");
  end_style();
  Move mv=getMove(player1);
  CurserPos.row++;
  CurserPos.col=0;
  draw(1,"Vous avez choisi %s :%d %d %d %d",mv.string,mv.to.x,mv.to.y,mv.from.x,mv.from.y);

  end();
}