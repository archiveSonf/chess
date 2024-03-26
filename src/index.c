#include <stdio.h>
#include "../tools/select/bool.h"
#include "../tools/small_tools.h"
#include "../tools/env.h"
#include "../tools/select/list.h"

void main(){
  init();
  CurserPos.row++;
  CurserPos.col=0;
  draw(1,"%s %s %s %s %s %s %s %s %s %s %s %s\n",roi_blanc,roi_noir,dame_blanc,dame_noir,pion_blanc,pion_noir,
    tour_blanc,tour_noir,cavalier_blanc,cavalier_noir,fou_blanc,fou_noir);
  char* res=select_bool("Sélectionne une option","option1","option2");
  CurserPos.row++;
  CurserPos.col=0;
  draw(1,"Vous avez choisi %s",res);

  res=select_list("S\u00E9lectionne une option",7,
    (char*[]){"option1","option2","option3","option4","option5","option6","option7"});

  CurserPos.row++;
  CurserPos.col=0;
  draw(1,"Vous avez choisi %s",res);
}