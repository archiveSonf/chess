typedef struct _hit{
  int num;
  int note;
  struct _hit *previous_hit;
} Hit;


// Ecris le coup joué
void write_hit(char hit[4]);

// Sauvegarde les coups joués dans la partie
void save_hits(char hit[4]);