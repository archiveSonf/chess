#include "../tools.h"

void echec_et_mat(){
    int checkmate = 0; 
    if(danger_blanc){
        int Rb[2];

        for (int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            if(plateau[i][j] == 10){
                Rb[0] = i;
                Rb[1] = j;
            }
        }
    }
    path_piece(Rb[0],Rb[1]);
    if(nbre_cases_jouables==0){
        for (int u=0;u<8;u++){
        for (int v=0;v<8;v++){
            int **cases_jouables = path_piece(u,v);
            for(int a=0;a<nbre_cases_jouables;a++){
                if(Leroi(u,v,cases_jouables[a][0],cases_jouables[a][1])){
                    checkmate = 1;
                }
                
            }
        }
        }
    }

    }
    CurserPos.row = 25;
    CurserPos.col = 0;
    draw(1,"%d",checkmate);
}