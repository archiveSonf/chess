#include <stdio.h>
#include <stdarg.h>
#include <termios.h>
#include <unistd.h>
#include "env.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>


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

  //récupère les arguments
  while(*str){

    if(*str=='%'){
      str++;
      if(*str=='d'){
        int val=va_arg(args,int);
        printf("%d",val);
        int num_digits;
        if(val==0){
          num_digits=1;
        }else{
          num_digits=floor(log10(abs(val)))+1;
        }
        CurserPos.X+=num_digits;
      }else if(*str=='.'){
        str+=4;
        double val=va_arg(args,double);
        printf("%.2lf",val);
        CurserPos.X+=4;
      }else if(*str=='c'){
        char val=va_arg(args,int);
        printf("%c",val);
        CurserPos.X++;
      }else if(*str=='s'){
        char *val=va_arg(args,char*);
        while(*val){
          if(*val=='\b'){
            CurserPos.X-=1;
          }else if(*val=='\n'){
            CurserPos.Y++;
            CurserPos.X=0;
          }
          printf("%c",*val);
          CurserPos.X++;
          val++;
        }
      }
    }else{
      printf("%c",*str);
      CurserPos.X++;
    }

    if(*str=='\b'){
      CurserPos.X-=1;
    }else if(*str=='\n'){
      CurserPos.Y++;
      CurserPos.X=0;
    }
    
    str++;
  }

  if(_style.active){
    printf("\033[0m");
  }

  va_end(args);
}

void clearScreen(){
  system("clear");
  printf("\033[0;0H");
  CurserPos=(struct _curser_pos){0,0,0,0};
}

void init(){
  clearScreen();
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

void send_msg(MSG_TYPE type,char *msg){
  char *color;
  switch(type){
    case MSG_INFO:
      color=cW0;
      break;
    case MSG_ERROR:
      color=cR;
      break;
    case MSG_WARNING:
      color=cY;
      break;
    case MSG_SUCCESS:
      color=cG;
      break;
  }
  CurserPos.col=zone_msg_col;
  CurserPos.row=zone_msg_row;
  draw(1,"                                                  ");
  start_style(color,sans_fond);
  draw(1,"%s",msg);
  end_style();
}

void end(){
  printf("\n\n");
}