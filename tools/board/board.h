#include "hit.h"
#include "move.h"
#include "case.h"

#ifndef PlateauPosition 
#define plateau_col 0 
#define plateau_row 4 
#endif

typedef struct{
  int id;
  char pseudo[8];
  int score;
} Joueur;

struct _joueurs{
  Joueur *player1;
  Joueur *player2;
};

typedef struct{
  int id;
  struct _joueurs players;
  int nombre_de_coup;
  Joueur *vainqueur;
  Hit *last_hit;
} GAME;

extern GAME Game;

//Contenu Case
#define cv -1 //Case vide
#define cpb 0 //Case pion blanc
#define cfb 2 //Case fou blanc
#define ccb 4 //Case cavalier blanc
#define ctb 6 //Case tour blanc
#define cdb 8 //Case dame blanc
#define crb 10 //Case roi blanc
#define cpn 1 //Case pion noir
#define cfn 3 //Case fou noir
#define ccn 5 //Case cavalier noir
#define ctn 7 //Case tour noir
#define cdn 9 //Case dame noir
#define crn 11 //Case roi noir


//Plateau de jeu
extern int plateau[8][8];

//Initie le jeu
void runGame(GAME *game,Joueur *player1, Joueur *player2);

//Dessine le tableau
void drawplateau (int plateau[8][8]);