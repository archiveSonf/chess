#include <stdio.h>
#include <string.h>
#include "../color.h"
#include "../small_tools.h"
#include "../env.h"

//Permet de proposer deux options
char* select_bool(char q[],char opt1[],char opt2[]){
  CurserPos.col++;
  CurserPos.row=1;
  draw(1,"%s : ",q);
  draw(0,"%s ou %s",cB,opt1,fA,opt2);

  int choice=TRUE;
  int lenght=strlen(opt1)+strlen(opt2)+4;
  int input=getKey();
  while (input!=key_enter){
    switch (input){
      case key_right:
        for(int i=0;i<lenght;i++){
          draw(0,"\b \b");
        }
        draw(0,"%s ou %s%s%s",opt1,cB,opt2,fA);
        choice=FALSE;
        break;
      case key_left:
        for(int i=0;i<lenght;i++){
          draw(0,"\b \b");
        }
        draw(0,"%s%s%s ou %s",cB,opt1,fA,opt2);
        choice=TRUE;
        break;
      default:
        input=getKey();
        break;
    }
  }

  if(choice)
    return opt1;
  return opt2;
}