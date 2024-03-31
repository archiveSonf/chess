#include <stdio.h>
#include "../tools/env.h"
#include "../tools/small_tools.h"
#include "../tools/menu/menu.h"
#include "../tools/board/board.h"

void main(){
  init();
  //CurserPos.row++;
  //CurserPos.col=0;
  //draw(1,"%s %s %s %s %s %s %s %s %s %s %s %s\n",roi_blanc,roi_noir,dame_blanc,dame_noir,pion_blanc,pion_noir,
  //  tour_blanc,tour_noir,cavalier_blanc,cavalier_noir,fou_blanc,fou_noir);
  //enum options res=select_bool("Sélectionne une option",(struct option[2]){{run_game_2,"option1"},{run_game_ia,"option2"}});
  //CurserPos.row++;
  //CurserPos.col=0;
  //draw(1,"Vous avez choisi %d",res);
//
  //res=select_list("S\u00E9lectionne une option",7,
  //  (struct option[7]){{run_game,"option1"},{run_game_ia,"option2"},{run_game_2,"option3"},{save_game,"option4"},{analyz_old_game,"option5"},{see_scores,"option6"},{quitter,"option7"}});
//
  //CurserPos.row++;
  //CurserPos.col=0;
  //draw(1,"Vous avez choisi %d",res);

  drawplateau();
}