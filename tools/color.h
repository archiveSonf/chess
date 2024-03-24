//fin
//#define fA "\033[0m"

//color

#ifdef __linux__

#include <ncurses.h>

#define cBl COLOR_BLACK //noir
#define CR COLOR_RED //rouge
#define cG COLOR_GREEN //vert
#define cB COLOR_BLUE //bleu
#define cP COLOR_MAGENTA //violet
#define cC COLOR_CYAN //cyan
#define cW COLOR_WHITE //white
#define cY COLOR_YELLOW //jaune

#define sBl COLOR_BLACK //noir
#define sR COLOR_RED //rouge
#define sG COLOR_GREEN //vert
#define sB COLOR_BLUE //bleu
#define sP COLOR_MAGENTA //violet
#define sC COLOR_CYAN //cyan
#define sW COLOR_WHITE //white
#define sY COLOR_YELLOW //jaune

#else

#define cBl "\033[0;30m" //noir
#define cR "\033[0;31m" //rouge
#define cG "\033[0;32m" //vert
#define cY "\033[0;33m" //jaune
#define cB "\033[0;34m" //bleu
#define cP "\033[0;35m" //violet
#define cC "\033[0;36m" //cyan
#define cW "\033[0;37m" //white

//surlignement
#define sBl "\033[0;40m" //noir
#define sR "\033[0;41m" //rouge
#define sG "\033[0;42m" //vert
#define sY "\033[0;43m" //orange
#define sB "\033[0;44m" //bleu
#define sP "\033[0;45m" //violet
#define sC "\033[0;46m" //cyan
#define sW "\033[0;47m" //White

struct Style{
  int active;
  char text[10];
  char background[10];
};

extern Style _style={0,cW,sBl};

#endif

//Commencer un style
//Assurer de vous positionner à l'endroit où vous voulez que 
//le style commence avant d'appeler cette fonction
void start_style(char text[], char background[]);
void start_style(int text, int background);

//Faire clignoter
//Assurer de vous positionner à l'endroit où vous voulez que 
//le style commence avant d'appeler cette fonction
void blink();

//Finir un style
//Assurer de vous positionner à l'endroit où vous voulez que
//le style se termine avant d'appeler cette fonction
void end_style();