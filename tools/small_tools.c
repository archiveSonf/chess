#include <stdio.h>
#include <stdarg.h>
#include <termios.h>
#include <unistd.h>
#include "env.h"
#include "style.h"
#include <string.h>

struct _curser_pos CurserPos={0,0,0,0};

void draw(int move,const char *str, ...){
  va_list args;
  va_start(args,str);

  if(move){
    int col=CurserPos.col-CurserPos.X,
      row=CurserPos.row-CurserPos.Y;
    CurserPos.X=CurserPos.col;
    CurserPos.Y=CurserPos.row;
    if(col>0){
      printf("\033[%dC",col);
    }else if(col!=0){
      printf("\033[%dD",-col);
    }
    if(row>0){
      printf("\033[%dB",row);
    }else if(row!=0){
      printf("\033[%dA",-row);
    }
  }

  if(_style.active){
    printf("%s%s",_style.text,_style.background);
  }
  if(_style.blink){
    printf("\033[5m");
  }
    
  CurserPos.X+=strlen(str);

  //récupère les arguments
  while(*str){

    if(*str=='\\'){
      if(*(str+1)=='b'){
        CurserPos.X-=3;
      }
      if(*(str+1)=='n'){
        CurserPos.Y++;
        CurserPos.X=0;
      }
      if(*(str+1)=='u'){
        CurserPos.Y-=6;
      }
      //if(*(str+1)=='0'){
      //  int i=4;
      //  //while(*(str+i)){
      //  //  if(*(str+i)=='m'){
      //  //    i++;
      //  //    break;
      //  //  }
      //  //}
      //  CurserPos.X-=i;
      //}
    }

    if(*str=='%'){
      str++;
      if(*str=='d'){
        int val=va_arg(args,int);
        printf("%d",val);
        char *_val;
        sprintf(_val,"%d",val);
        CurserPos.X+=strlen(_val)-2;
      }else if(*str=='f'){
        double val=va_arg(args,double);
        printf("%lf",val);
        char *_val;
        sprintf(_val,"%lf",val);
        CurserPos.X+=strlen(_val)-3;
      }else if(*str=='s'){
        char *val=va_arg(args,char*);
        CurserPos.X+=strlen(val)-2;
        while(*val){
          if(*val=='\\'){
            if(*(val+1)=='b'){
              CurserPos.X-=3;
            }
            if(*(val+1)=='n'){
              CurserPos.Y++;
              CurserPos.X=0;
            }
            if(*(val+1)=='u'){
              CurserPos.Y-=6;
            }
            if(*(val+1)=='0'){
              int i=4;
              //while(*(val+i)){
              //  if(*(val+i)=='m'){
              //    i++;
              //    break;
              //  }
              //}
              CurserPos.X-=i;
            }
          }
          printf("%c",*val);
          val++;
        }
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
  printf("\033[2J");
  printf("\033[0;0H");
  draw(1,"Bonjour Monde !");
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