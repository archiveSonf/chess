#include <stdio.h>
#include <string.h>
#include "../ansi.h"
#include "../small_tools.h"
#include "../env.h"

char select_bool(char q[],char opt1[],char opt2[]){
  while(CurserPos.row<10){
    int key=getKey();
    draw("%d\n",key);
    CurserPos.row++;
    switch (key){
      case key_left:
        draw("gauche");
        break;
      case key_right:
        draw("droite");
        break;
      case key_up:
        draw("haut");
        break;
      case key_down:
        draw("bas");
        break;
    }
  }
  CurserPos.row++;
  return 'g';
}