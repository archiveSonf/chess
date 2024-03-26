
struct _curser_pos{
  int row;
  int col;
};
//Permet de donner la position du curseur, 
//pour afficher y afficher du texte
extern struct _curser_pos CurserPos;

//Chess
#define roi_blanc "\u2654" //♔
#define dame_blanc "\u2655" //♕
#define tour_blanc "\u2656" //♖
#define fou_blanc "\u2657" //♗
#define cavalier_blanc "\u2658" //♘
#define pion_blanc "\u2659" //♙

#define roi_noir "\u265A" //♚
#define dame_noir "\u265B" //♛
#define tour_noir "\u265C" //♜
#define fou_noir "\u265D" //♝
#define cavalier_noir "\u265E" //♞
#define pion_noir "\u265F" //♟

//Keycode
#define key_left 68
#define key_right 67
#define key_up 65
#define key_down 66
#define key_enter 10

//Symbols divers
#define fleche_droite "\u2771" //❱