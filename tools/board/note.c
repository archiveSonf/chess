#include "board.h"
//#include <string.h>
#include <time.h>

int old_plateau[8][8];

int note(joueur j){
  //TODO: mettre au point le programme de note
  //analyser le plateau actuel par rapport à l'ancien
  // et au joueur

  time_t t=time(NULL);
  struct tm tm=*localtime(&t);
  int aleatoire=tm.tm_sec+30;

  //memcpy(old_plateau,plateau,sizeof(plateau));   
  return aleatoire;
}