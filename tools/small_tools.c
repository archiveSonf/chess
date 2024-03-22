#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#ifdef __linux__

  #include <ncurses.h>

  void init(){
    initscr();
    refresh();
    endwin();
    write(1,1,"Hello World\n");
  }

  int getKey(){
    initscr();
    noecho();
    cbreak();
    keypad(stdscr,TRUE);
    int key=getch();
    endwin();
    return key;
  }

  void draw(int row,int col,const char *str, ...){
    va_list args;
    va_start(args,str);
    mvprintw(row,col,str,args);
    va_end(args);
  }

#else
  
  #include <conio.h>

  void init(){
    //
  }

  int getKey(){
    return _getch();
  }

#endif