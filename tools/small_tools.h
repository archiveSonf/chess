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

//Permet d'initialiser l'environnement
void init();
//Permet de terminer l'environnement
void end();

//Permet de récupérer la touche du clavier pressée
int getKey();

//Permet d'afficher du texte à une position donnée
void draw(int move,const char* str, ...);

//Permet d'effacer entièrement l'écran
void clearScreen();

//Permet d'envoyer un message à l'utilisateur
void send_msg(MSG_TYPE type,char *msg);