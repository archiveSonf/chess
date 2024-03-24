#include <stdio.h>
#include "color.h"

#ifdef __linux__

  #include <ncurses.h>

  void start_style(int text,int background){
    init_pair(1,text,background);
    attron(COLOR_PAIR(1));
  }

  void blink(){
    attron(A_BLINK);
  }

  void end_style(){
    attroff(COLOR_PAIR(1));
    attroff(A_BLINK);
  }

#else

  void start_style(char text[],char background[]){
    _style
  }

  void blink(){
    printf("\033[5m");
  }

#endif