#include <stdio.h>
#include "../tools/select/bool.h"
#include "../tools/small_tools.h"

void main(int argc, char *argv[]){
  init();
  printf("enter -> %s\n",key_enter);
  select_bool("Select an option","option1","option2");
}