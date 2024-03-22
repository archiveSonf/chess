#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#ifdef __linux__

  #include <ncurses.h>

  void draw(int row,int col,const char *str, ...){
    va_list args;
    va_start(args,str);

    move(row,col);
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

    va_end(args);
  }

  void init(){
    initscr();
    refresh();
    endwin();
    clear();
    draw(1,1,"Hello World\n");
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
  #include <windows.h>

  void draw(int row,int col,const char* str, ...){
    va_list args;
    va_start(args,str);
    COORD coord;
    coord.X=col;
    coord.Y=row;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    
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

    va_end(args);
  }

  void init(){
    system("cls");
    draw(1,1,"Hello World\n");
  }

  int getKey(){
    return _getch();
  }

#endif