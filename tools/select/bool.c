#include <stdio.h>
#include <string.h>
#include "../ansi.h"
#include "../small_tools.h"

char select_bool(char opt1[],char q[],char opt2[]){
  int i=3;
  while(1){
    int key=getKey();
    draw(i,1,"%d\n",key);
    i++;
  }
  return 'g';
}