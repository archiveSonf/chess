//Les différentes options possibles
enum options{
  run_game, //Lancer une partie
  run_game_ia, //Lancer une partie contre l'ia
  run_game_2, //Lancer une partie de 2 joueurs
  analyz_old_game,  //Analyser les anciennes parties
  see_scores, //Voir le tableau des cores
  save_game
};

//Crèe une option de menu
struct option{
  enum options id;
  char* txt;
};