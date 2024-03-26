//color

#define cBl "\033[0;30m" //text noir
#define cR "\033[0;31m" //text rouge
#define cG "\033[0;32m" //text vert
#define cY "\033[0;33m" //text jaune
#define cB "\033[0;34m" //text bleu
#define cP "\033[0;35m" //text violet
#define cC "\033[0;36m" //text cyan
#define cW "\033[0;37m" //text white

//surlignement
#define sBl "\033[0;40m" //couleur de fond noir
#define sR "\033[0;41m" //couleur de fond rouge
#define sG "\033[0;42m" //couleur de fond vert
#define sY "\033[0;43m" //couleur de fond orange
#define sB "\033[0;44m" //couleur de fond bleu
#define sP "\033[0;45m" //couleur de fond violet
#define sC "\033[0;46m" //couleur de fond cyan
#define sW "\033[0;47m" //couleur de fond White

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