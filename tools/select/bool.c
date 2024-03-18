#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "../ansi.h"
#include "../small_tools.h"

char* bool(char* q,char* opt1,char* opt2){

  waitKeyRelease(VK_RETURN);

  int length=strlen(opt1)+strlen(opt2);
  printf("%s: ",q);
  printf("%s%s%s ou %s",cB,opt1,fA,opt2);

  BOOL choice=TRUE, _select=FALSE;
  MSG msg;

  while(!_select){
    BOOL keyLeft=(GetAsyncKeyState(VK_LEFT) & 0x8000),
      keyRight=(GetAsyncKeyState(VK_RIGHT) & 0x8000),
      unKeyCode=keyLeft^keyRight;
    if(unKeyCode){
      for(int i=0;i<length+4;i++){
        printf("\b \b");
      }
      if(keyLeft){
        printf("%s%s%s ou %s",cB,opt1,fA,opt2);
        choice=TRUE;
        waitKeyRelease(VK_LEFT);
      }else{
        printf("%s ou %s%s%s",opt1,cB,opt2,fA);
        choice=FALSE;
        waitKeyRelease(VK_RIGHT);
      }
    }
    if(GetAsyncKeyState(VK_RETURN)&0x8000){
      _select=TRUE;
    }
  }

  if(choice){
    return opt1;
  }
  return opt2;
}