//Permet d'initialiser l'environnement
void init();
//Permet de terminer l'environnement
void end();

//Permet de récupérer la touche du clavier pressée
int getKey();

//Permet d'afficher du texte à une position donnée
void draw(int move,const char* str, ...);

//Permet d'effacer entièrement l'écran
void clearScreen();
