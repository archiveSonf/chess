#include <stdio.h>
#include <stdarg.h>
#include <termios.h>
#include <unistd.h>
#include "env.h"
#include "style.h"

struct _curser_pos CurserPos={0,0};

void draw(int move,const char *str, ...){
  va_list args;
  va_start(args,str);

  if(move){
    printf("\033[%d;%dH",CurserPos.row,CurserPos.col);
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
  printf("\033[2J\033[1;1H");
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