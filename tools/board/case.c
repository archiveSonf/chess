#include <stdio.h>

void backgroundcolor(char *piece, int lp,  int cp){
  if ((lp % 2 == 0 && cp % 2 == 0) || ( lp % 2 != 0 && cp % 2 != 0 )){
     printf("\033[47;30m %s  \033[0m",piece);
  }else{
      printf("\033[42;30m %s  \033[0m",piece);
  }
}

void drawpion (int num_pion, int lp, int cp) {
  switch (num_pion){
    case 1:
        backgroundcolor("♟",lp,cp);
        break;

    case 3:
        backgroundcolor("♝",lp,cp);
        break;
    
    case 5:
        backgroundcolor("♞",lp,cp);
        break;
    
    case 7:
        backgroundcolor("♜",lp,cp);
        break;
    
    case 9:
        backgroundcolor("♛",lp,cp);
        break;
    
    case 11:
        backgroundcolor("♚",lp,cp);
        break;
    
    case 0:
        backgroundcolor("♙",lp,cp);
        break;

    case 2:
        backgroundcolor("♗",lp,cp);
        break;

    case 4:
        backgroundcolor("♘",lp,cp);
        break;

    case 6:
        backgroundcolor("♖",lp,cp);
        break;

    case 8:
        backgroundcolor("♕",lp,cp);
        break;

    case 10:
        backgroundcolor("♔",lp,cp);
        break;

    case -1:
        backgroundcolor(" ",lp,cp);
        break;
        
    default:
        break;
  }
}