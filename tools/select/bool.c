#include <stdio.h>
#include <string.h>
#include "../color.h"
#include "../small_tools.h"
#include "../env.h"

//Permet de proposer deux options
char* select_bool(char q[],char opt1[],char opt2[]){
  CurserPos.col=0;
  CurserPos.row++;
  draw(1,"%s : ",q);
  start_style(cB,sBl);
  draw(0,"%s",opt1);
  end_style();
  draw(0," ou %s",opt2);

  int choice=1;
  int lenght=strlen(opt1)+strlen(opt2)+4;
  int input=getKey();
  while (input!=key_enter){
    switch (input){
      case key_right:
        for(int i=0;i<lenght;i++){
          draw(0,"\b \b");
        }
        draw(0,"%s ou ",opt1);
        start_style(cB,sBl);
        draw(0,"%s",opt2);
        end_style();
        choice=0;
        break;
      case key_left:
        for(int i=0;i<lenght;i++){
          draw(0,"\b \b");
        }
        start_style(cB,sBl);
        draw(0,"%s",opt1);
        end_style();
        draw(0," ou %s",opt2);
        choice=1;
        break;
    }
    input=getKey();
  }

  if(choice)
    return opt1;
  return opt2;
}