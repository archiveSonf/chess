#include <stdio.h>
#include "../tools/select/bool.h"
#include "../tools/small_tools.h"
#include "../tools/env.h"
#include "../tools/select/list.h"

void main(){
  init();
  draw(0,"Bonjour Monde !");
  char* res=select_bool("S\u00E9lectionne une option","option1","option2");
  CurserPos.row++;
  CurserPos.col=0;
  draw(1,"Vous avez choisi %s",res);

  res=select_list("S\u00E9lectionne une option",7,
    (char*[]){"option1","option2","option3","option4","option5","option6","option7"});

  CurserPos.row++;
  CurserPos.col=0;
  draw(1,"Vous avez choisi %s",res);
}