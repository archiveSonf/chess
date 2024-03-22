#include <stdio.h>
#include "../tools/select/bool.h"
#include "../tools/small_tools.h"

void main(){
  init();
  draw(2,1,"enter -> %d\n",key_enter);
  select_bool("Select an option","option1","option2");
}