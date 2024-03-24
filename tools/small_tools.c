#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "env.h"
#include "color.h"


struct _curser_pos CurserPos={0,0};

#ifdef __linux__

  #include <ncurses.h>

  void draw(int move,const char *str, ...){
    va_list args;
    va_start(args,str);

    if(move){
      move(CurserPos.row,CurserPos.col);
    }

    while(*str){//récupère les arguments
      if(*str=='%'){
        str++;
        if(*str=='d'){
          int val=va_arg(args,int);
          printw("%d",val);
        }else if(*str=='f'){
          char val=va_arg(args,double);
          printw("%c",val);
        }else if(*str=='s'){
          char* val=va_arg(args,char*);
          printw("%s",val);
        }
      }else{
        printw("%c",*str);
      }
      str++;
    }

    va_end(args);
  }

  void init(){
    initscr();
    start_color();
    refresh();
    endwin();
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
  #include <windows.h>

  void draw(int move,const char* str, ...){
    va_list args;
    va_start(args,str);

    if(move){
      COORD coord;
      coord.X=CurserPos.col;
      coord.Y=CurserPos.row;
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    }

    if(_style.active){
      printf("%s%s",_style.background,_style.text);
    }
    if(_style.blink){
      printf("\033[5m");
    }
    
    while(*str){//récupère les arguments
      if(*str=='%'){
        str++;
        if(*str=='d'){
          int val=va_arg(args,int);
          printf("%d",val);
        }else if(*str=='f'){
          char val=va_arg(args,double);
          printf("%c",val);
        }else if(*str=='s'){
          char* val=va_arg(args,char*);
          printf("%s",val);
        }
      }else{
        printf("%c",*str);
      }
      str++;
    }

    if(_style.active){
      printf("\033[0m");
    }

    va_end(args);
  }

  void init(){
    system("cls");
  }

  int getKey(){
    return _getch();
  }

#endif