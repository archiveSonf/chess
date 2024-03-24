#include <stdio.h>
#include "../tools/select/bool.h"
#include "../tools/small_tools.h"
#include "../tools/env.h"

void main(){
  init();
  draw(0,"Hello World");
  char* res=select_bool("Selectionne une option","option1","option2");
  CurserPos.row++;
  CurserPos.col=1;
  draw(1,"Vous avez choisi %s",res);
}