#include <stdio.h>
#include <string.h>
#include "../ansi.h"
#include "../small_tools.h"

char select_bool(char opt1[],char q[],char opt2[]){
  while(1){
    int key=getKey();
    printf("%d\n",key);
  }
  return 'g';
}