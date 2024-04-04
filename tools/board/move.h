//Coordonnées sur la plateau

struct _coord{
  int x;
  int y;
};
struct Move{
  char string[4];
  struct _coord to;
  struct _coord from;
};

//Joueur
enum joueur{player1,player2};

//Effectuer un mouvement
struct Move getMove(enum joueur joueur);

