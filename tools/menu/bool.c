#include <stdio.h>
#include <string.h>
#include "../tools.h"

//Permet de proposer deux options
options select_bool(char q[],option opts[2]){
  draw(1,"%s : ",q);
  start_style(cB,sans_fond);
  draw(0,"%s",opts[0].txt);
  end_style();
  draw(0," ou %s",opts[1].txt);

  int lenght=strlen(opts[0].txt)+strlen(opts[1].txt)+4;
  int input=getKey();
  int choice=0;
  while (input!=key_enter){
    switch (input){
      case key_right:
        for(int i=0;i<lenght;i++){
          draw(0,"\b \b");
        }
        choice=1;
        draw(0,"%s ou ",opts[0].txt);
        start_style(cB,sans_fond);
        draw(0,"%s",opts[1].txt);
        end_style();
        break;
      case key_left:
        for(int i=0;i<lenght;i++){
          draw(0,"\b \b");
        }
        choice=0;
        start_style(cB,sans_fond);
        draw(0,"%s",opts[0].txt);
        end_style();
        draw(0," ou %s",opts[1].txt);
        break;
    }
    input=getKey();
  }

  return opts[choice].id;
}