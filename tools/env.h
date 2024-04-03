
struct _curser_pos{
  int row;
  int col;
};
//Permet de donner la position du curseur, 
//pour afficher y afficher du texte
extern struct _curser_pos CurserPos;

//Chess
#define roi_blanc "\033[6;1;5m\u265A" //♚
#define dame_blanc "\033[6;1;5m\u265B" //♛
#define tour_blanc "\033[6;1;5m\u265C" //♜
#define fou_blanc "\033[6;1;5m\u265D" //♝
#define cavalier_blanc "\033[6;1;5m\u265E" //♞
#define pion_blanc "\033[6;1;5m\u265F" //♟

#define roi_noir "\033[6;1;5m\u265A" //♚
#define dame_noir "\033[6;1;5m\u265B" //♛
#define tour_noir "\033[6;1;5m\u265C" //♜
#define fou_noir "\033[6;1;5m\u265D" //♝
#define cavalier_noir "\033[6;1;5m\u265E" //♞
#define pion_noir "\033[6;1;5m\u265F" //♟

//Keycode
#define key_left 68
#define key_right 67
#define key_up 65
#define key_down 66
#define key_enter 10
#define backspace 127