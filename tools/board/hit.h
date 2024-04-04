struct hit{
  int num;
  int note;
  struct hit previous_hit;
};

// Ecris le coup joué
void write_hit(char hit[4]);

// Sauvegarde les coups joués dans la partie
void save_hits(char hit[4]);