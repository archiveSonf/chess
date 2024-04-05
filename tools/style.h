//Coloration du texte
#define cBl "\033[1;30m" //text noir
#define cR "\033[1;31m" //text rouge
#define cG "\033[1;32m" //text vert
#define cY "\033[1;33m" //text jaune
#define cB "\033[1;34m" //text bleu
#define cP "\033[1;35m" //text violet
#define cP0 "\033[0;35m" //text violet
#define cC "\033[1;36m" //text cyan
#define cW "\033[1;37m" //text white

//Sourlignage
#define sans_fond "" //sans fond
#define sBl "\033[40m" //couleur de fond noir
#define sR "\033[41m" //couleur de fond rouge
#define sG "\033[42m" //couleur de fond vert
#define sY "\033[43m" //couleur de fond orange
#define sB "\033[44m" //couleur de fond bleu
#define sP "\033[45m" //couleur de fond violet
#define sC "\033[46m" //couleur de fond cyan
#define sW "\033[47m" //couleur de fond White

//Symbols divers
#define this "\u2771" //❱
#define to_from "\u27AB" //➫

void start_style(char text[], char background[]);

struct Style{
  int active;
  char* text;
  char* background;
  int blink;
};

extern struct Style _style;

//Faire clignoter
void blink();

//Finir un style
void end_style();