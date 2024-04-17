#ifndef ZONE_OLD_HIT
#define zone_old_hit_col 40 /*Colonne de la zone de rédaction du mouvement*/
#define zone_old_hit_row 3 /*Ligne de la zone de rédaction du mouvement*/
#endif

typedef struct _hit{
  int player;
  int numero_coup;
  char *hit;
  int note;
  struct _hit *previous_hit;
} Hit;

typedef struct _partie{
  int id;
  char* player1;
  char* player2;
  struct _partie *next;
} Partie;


// Ecris le coup joué
void write_hit(char *hit);

// Sauvegarde les coups joués dans la partie
int SaveGame(char *db_file);

// Charge une partie
//GAME *LoadGame(int id,char *db_file);
//
//Partie *LoadGames(char *db_file);