//Coordonnées sur la plateau

typedef struct {
  int x;
  int y;
} coord;

typedef struct {
  char string[4];
  coord to;
  coord from;
} Move;

//Joueur
typedef enum {player1,player2} joueur;

//Effectuer un mouvement
Move getMove(joueur joueur);

