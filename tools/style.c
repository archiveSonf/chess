#include <stdio.h>
#include "style.h"

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

  struct Style _style={0,cW,sBl,0};

  void start_style(char text[],char background[]){
    _style.active=1;
    _style.text=text;
    _style.background=background;
  }

  void blink(){
    _style.blink=1;
  }

  void end_style(){
    _style.active=0;
    _style.blink=0;
  }

#endif