#include "style.h"

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

#ifndef ZONE_MSG
#define zone_msg_col 35 /*Colonne de la zone de rédaction du message*/
#define zone_msg_row 16 /*Ligne de la zone de rédaction du message*/
#endif

typedef enum {
  MSG_INFO,
  MSG_ERROR,
  MSG_WARNING,
  MSG_SUCCESS
} MSG_TYPE;

void Init();
void init();
void end();

//Permet de récupérer la touche du clavier pressée
int getKey();

//Permet d'afficher du texte à une position donnée
void draw(int move,const char* str, ...);

//Permet d'effacer entièrement l'écran
void clearScreen();

//Permet d'envoyer un message à l'utilisateur
void send_msg(MSG_TYPE type,char *msg);