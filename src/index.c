#include <stdio.h>
#include "../tools/select/bool.h"
#include "../tools/small_tools.h"
#include "../tools/env.h"

void main(){
  init();
  CurserPos.row++;
  draw("enter -> %d %d\n",key_enter,1);
  CurserPos.row++;
  select_bool("Select an option","option1","option2");
}