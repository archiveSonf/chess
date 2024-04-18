typedef struct _partie{
  int id;
  char* player1;
  char* player2;
  struct _partie *next;
  struct _partie *previous;
} Partie;

// Sauvegarde les coups joués dans la partie
int SaveGame(char *db_file);

// Charge une partie
GAME *LoadGame(int id,char *db_file);

//Retourne la liste des parties
Partie *LoadGames(char *db_file,int *nb_partie);