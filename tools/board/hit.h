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

// Ecris le coup joué
void write_hit(char *hit);
