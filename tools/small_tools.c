#include <windows.h>

void waitKeyRelease(int keyCode){
  while(GetAsyncKeyState(keyCode)&0x8000){
    Sleep(1);//wait for the key to be released
  }
}