#ifndef ZONE_OLD_HIT
#define zone_old_hit_col 40 /*Colonne de la zone de rédaction du mouvement*/
#define zone_old_hit_row 2 /*Ligne de la zone de rédaction du mouvement*/
#endif

typedef struct _hit{
  int player;
  int numero_coup;
  char *hit;
  double note;
  struct _hit *previous_hit;
} Hit;


// Ecris le coup joué
void write_hit(char *hit);

// Sauvegarde les coups joués dans la partie
int SaveGame(char *db_file);