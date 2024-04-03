#include "board.h"
#include "./case.h"
#include "../style.h"
#include "../env.h"
#include "../small_tools.h"
#include <stdio.h>

int plateau[8][8]={
  {ctb,ccb,cfb,cdb,crb,cfb,ccb,ctb},
  {cpb,cpb,cpb,cpb,cpb,cpb,cpb,cpb},
  {cv,cv,cv,cv,cv,cv,cv,cv},
  {cv,cv,cv,cv,cv,cv,cv,cv},
  {cv,cv,cv,cv,cv,cv,cv,cv},
  {cv,cv,cv,cv,cv,cv,cv,cv},
  {cpn,cpn,cpn,cpn,cpn,cpn,cpn,cpn},
  {ctn,ccn,cfn,cdn,crn,cfn,ccn,ctn}
};

void drawplateau (int plateau[8][8]) {
    //for(int i=1;i<9;i++){
    //    for (int j=1; j<9;j++){
    //        CurserPos.row = largeur_case*(i-1) + 2;
    //        CurserPos.col = longueur_case*(j-1) + 1 ;
    //        if (((i%2 == 0 && j%2 == 0) || (i%2 != 0 && j%2 !=0 )) ){
    //            for (int m=0;m<largeur_case;m++){
    //                int move=1;
    //                for(int n=0;n<longueur_case;n++){
    //                    start_style(cG,sC);
    //                    draw(move,"1");
    //                    move=0;
    //                }
    //                CurserPos.row++;
    //            }
    //        }
//
    //        else{
    //            for (int u=0;u<largeur_case;u++){
    //                int move=1;
    //                for(int v=0;v<longueur_case;v++){
    //                    start_style(cB,sC);
    //                    draw(move,"1");
    //                    move=0;
    //                }
    //                CurserPos.row++;
    //        }
    //    }
    //}
    //}

    //for(int i=0; i <4;i++){
    //    for (int k=0; k<largeur_case;k++){
    //        for(int j=0;j<4;j++){
    //        for(int m=0;m<longueur_case;m++){
    //            start_style(cG,sW);
    //            draw(0,"  ");
    //        }
    //        for(int n=0;n<longueur_case;n++){
    //            start_style(cB,sC);
    //            draw(0,"  ");
    //        }
    //    }
    //    printf("\n");
//
    //    }
    //    for (int k=0; k<largeur_case;k++){
    //        for(int j=0;j<4;j++){
    //        for(int m=0;m<longueur_case;m++){
    //            start_style(cB,sC);
    //            draw(0,"  ");
    //        }
    //        for(int n=0;n<longueur_case;n++){
    //            start_style(cG,sW);
    //            draw(0,"  ");
    //        }
    //    }
    //    printf("\n");
//
    //    }
    //}
    //terminal();
    //init();
    //CurserPos.row = 2;
    //CurserPos.col = 0;
    //draw(1,"♜") ;
    ////drawpion(plateau[0][0],1,1,sW);
    ////printf("\n");
    //CurserPos.row = 20;
    //CurserPos.col = 0;
    //draw(1,"");

    //for(int u=1;u<9;u++){
    //    for (int v=1; v=9;v++){
    //        if ((u%2 == 0 && v%2 == 0) || (u%2 != 0 && v%2 !=0 )){
    //            drawpion(plateau[u][v],u,v,sW);
    //        }
    //        else{
    //            drawpion(plateau[u][v],u,v,sC);
    //        }
    //    }
    //}
    
    for (int i=0; i<8;i++){
        //if(i%2==0){
        //        for (int u=0;u<4;u++){
        //        printf("\033[47;30m    \033[0m\033[42;30m    \033[0m");
        //    }
        //    printf("\n");
        //    }
        //    else {
        //        for (int u=0;u<4;u++){
        //        printf("\033[42;30m    \033[0m\033[47;30m    \033[0m");
        //    }
        //    printf("\n");
        //    }
        for (int j=0; j<8;j++){
            drawpion(plateau[i][j], i , j);
        }
        printf("\n");
    }
    
    
    
}
    

