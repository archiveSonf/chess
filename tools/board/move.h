//Coordonnées sur la plateau

struct _coord{
  int x;
  int y;
};
struct Move{
  struct _coord to;
  struct _coord from;
};

//Joueur
enum Joueur{blanc,noir};

//Effectuer un mouvement
struct Move doMove(enum Joueur joueur);

