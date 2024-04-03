#include <stdio.h>
#include <stdarg.h>
#include <termios.h>
#include <unistd.h>
#include "env.h"
#include "style.h"
#include <ncurses.h>
#include <wchar.h>
#include <stdlib.h>

struct _curser_pos CurserPos={1,0};

void draw(int move,const char *str, ...){
  va_list args;
  va_start(args,str);

  if(move){
    printf("\033[%d;%dH",CurserPos.row,CurserPos.col);
  }

  if(_style.active){
    printf("%s%s",_style.text,_style.background);
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
        double val=va_arg(args,double);
        printf("%lf",val);
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
  system("clear");
  //printf("\033[2J\033[H");
  //initscr();
  //mvaddwch(CurserPos.row, CurserPos.col, L'♔');
  //refresh();
  //move(CurserPos.row, CurserPos.col);
    // Afficher le message
  //printw("Hello");
  
  //getch();
  //endwin();
  //(CurserPos.row, CurserPos.col, L'♔');
  //printf("\033[2J");
  //printf("\033[8;%d;%dt", 1, 1);
  draw(1,"Bonjour Monde !\n");
}

int getKey(){
  static struct termios oldt, newt;
  tcgetattr(STDIN_FILENO,&oldt);
  newt=oldt;
  newt.c_lflag &= (~ICANON & ~ECHO);
  tcsetattr(STDIN_FILENO,TCSANOW,&newt);
  int k=getchar();
  tcsetattr(STDIN_FILENO,TCSANOW,&oldt);
  return k;
}


int terminal() {
    system("stty rows 4 cols 100"); // Redimensionne le terminal à 40 lignes et 100 colonnes
    printf("Terminal redimensionné avec succès.\n");
    return 0;
}