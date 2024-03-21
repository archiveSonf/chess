#include <stdio.h>

#ifdef __linux__

  #include <ncurses.h>

  void init(){
    initscr();
    refresh();
    endwin();
    clear();
    mvprintw(1,1,"Hello World\n");
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

#else
  
  #include <conio.h>

  void init(){
    //
  }

  int getKey(){
    return _getch();
  }

#endif