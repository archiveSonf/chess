#include <stdio.h>
#include "../small_tools.h"
#include "../env.h"
#include "../style.h"
#include "./case.h"


void backgroundcolor(char *piece, int lp,  int cp){
    if ((lp % 2 == 0 && cp % 2 == 0) || ( lp % 2 != 0 && cp % 2 != 0 )){
           printf("\033[47;30m %s  \033[0m",piece);
        }
        else {
            printf("\033[42;30m %s  \033[0m",piece);
        }

}

void drawpion (int num_pion, int lp, int cp) {
//
//    CurserPos.row = largeur_case*(lp-1) + (largeur_case/2);
//    CurserPos.col = longueur_case*(cp-1) + (longueur_case/2);
//
//    switch (num_pion)
//    {
//    case 0:
//        start_style(cC,sC);
//        draw(1,"%s",pion_noir);
//        break;
//
//    case 1:
//        start_style(cC,sC);
//        draw(1,"%s",fou_noir);
//        break;
//    
//    case 2:
//        start_style(cC,sC);
//        draw(1,"%s",cavalier_noir);
//        break;
//    
//    case 3:
//        start_style(cC,sC);
//        draw(1,"%s",tour_noir);
//        break;
//    
//    case 4:
//        start_style(cC,sC);
//        draw(1,"%s",dame_noir);
//        break;
//    
//    case 5:
//        start_style(cC,sC);
//        draw(1,"%s",roi_noir);
//        break;
//    
//    case 6:
//        start_style(cC,sW);
//        draw(1,"%s",pion_blanc);
//        break;
//
//    case 7:
//        start_style(cC,sW);
//        draw(1,"%s",fou_blanc);
//        break;
//
//    case 8:
//        start_style(cC,sW);
//        draw(1,"%s",cavalier_blanc);
//        break;
//
//    case 9:
//        start_style(cC,sW);
//        draw(1,"%s",tour_blanc);
//        break;
//
//    case 10:
//        start_style(cC,sW);
//        draw(1,"%s",dame_blanc);
//        break;
//
//    case 11:
//        start_style(cC,sW);
//        draw(1,"%s",roi_blanc);
//        break;
//
//    case -1:
//        start_style(cC,sW);
//        draw(1," ");
//        break;
//    
//    case -2:
//        start_style(cC,sC);
//        draw(1," ");
//        break;
//    
//    default:
//        break;
//    }
}