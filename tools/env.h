#include "style.h"
#include "small_tools.h"


struct _curser_pos{
  int row;
  int col;
  int X; //Tracer la position du curseur sur la colonne
  int Y; //Tracer la position du curseur sur la ligne
};
//Permet de donner la position du curseur, 
//pour afficher y afficher du texte
extern struct _curser_pos CurserPos;

//Keycode
#define key_left 68
#define key_right 67
#define key_up 65
#define key_down 66
#define key_enter 10
#define backspace 127