
struct _curser_pos{
  int row;
  int col;
};
//Permet de donner la position du curseur, 
//pour afficher y afficher du texte
extern struct _curser_pos CurserPos;

//Chess
#define roi_blanc "\033[6;1;5m\033[0;32m\u265A\033[0m" //♚
#define dame_blanc "\033[6;1;5m\033[0;32m\u265B\033[0m" //♛
#define tour_blanc "\033[6;1;5m\033[0;32m\u265C\033[0m" //♜
#define fou_blanc "\033[6;1;5m\033[0;32m\u265D\033[0m" //♝
#define cavalier_blanc "\033[6;1;5m\033[0;32m\u265E\033[0m" //♞
#define pion_blanc "\033[6;1;5m\033[0;32m\u265F\033[0m" //♟

#define roi_noir "\033[6;1;5m\033[0;35m\u265A\033[0m" //♚
#define dame_noir "\033[6;1;5m\033[0;35m\u265B\033[0m" //♛
#define tour_noir "\033[6;1;5m\033[0;35m\u265C\033[0m" //♜
#define fou_noir "\033[6;1;5m\033[0;35m\u265D\033[0m" //♝
#define cavalier_noir "\033[6;1;5m\033[0;35m\u265E\033[0m" //♞
#define pion_noir "\033[6;1;5m\033[0;35m\u265F\033[0m" //♟

//Keycode
#define key_left 68
#define key_right 67
#define key_up 65
#define key_down 66
#define key_enter 10

//Symbols divers
#define fleche_droite "\u2771" //❱