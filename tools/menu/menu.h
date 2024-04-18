//Les différentes options possibles
typedef enum {
  run_game, //Lancer une partie
  run_game_ia, //Lancer une partie contre l'ia
  run_game_2, //Lancer une partie de 2 joueurs
  load_game, //Charger une partie
  load_game_wiht_id, //Charger une partie avec un identifiant
  load_game_select, //Charger une partie en selectionnant
  save_game, //Sauvegarder une partie
  analyz_old_game,  //Analyser les anciennes parties
  see_scores, //Voir le tableau des scores
  quitter, //Quitter le jeu
} options;

//Crèe une option de menu
typedef struct {
  options id;
  char* txt;
} option;

options select_bool(char q[],option opts[2]);
options select_list(char* q,int nbr_opts,option opts[]);
int select_partie(Partie *partie,int nbr_partie);