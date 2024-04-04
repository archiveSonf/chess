#include <stdio.h>
#include "../tools/env.h"
#include "../tools/style.h"
#include "../tools/small_tools.h"
#include "../tools/menu/menu.h"
#include "../tools/board/board.h"
#include "../tools/board/move.h"

void main(){
  init();
  //CurserPos.row++;
  //CurserPos.col=0;
  //draw(1,"%s %s %s %s %s %s\n",roi,dame,tour,fou,cavalier,pion);
  //enum options res=select_bool("Sélectionne une option",(struct option[2]){{run_game_ia,"option1"},{run_game_2,"option2"}});
  //CurserPos.row++;
  //CurserPos.col=0;
  //draw(1,"Vous avez choisi %d",res);
//
  //res=select_list("Sélectionne une option",7,
  //  (struct option[7]){{run_game,"option1"},{run_game_ia,"option2"},{run_game_2,"option3"},{save_game,"option4"},{analyz_old_game,"option5"},{see_scores,"option6"},{quitter,"option7"}});
//
  //CurserPos.row++;
  //CurserPos.col=0;
  //draw(1,"Vous avez choisi %d",res);

  //struct Move mv=doMove(blanc);
  //CurserPos.row++;
  //CurserPos.col=0;
  //draw(1,"Vous avez choisi %d %d %d %d",mv.to.x,mv.to.y,mv.from.x,mv.from.y);
  drawplateau(plateau);
  end();
  printf("\x1b[9;1;t");
}