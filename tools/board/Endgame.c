#include "./board.h"
#include "../env.h"

int echec_et_mat_blanc(int x_to,int y_to,int x_from,int y_from){

    
    int checkmate = 0;
    int permut;
    if(coup_valide(x_to,y_to,x_from,y_from)){
    permut = plateau[x_from][y_from];
    plateau[x_from][y_from] = plateau[x_to][y_to];
    plateau[x_to][y_to] = cv;
    int Rb[2];
    for (int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            if(plateau[i][j] == crb){
                Rb[0] = i;
                Rb[1] = j;
            }
        }
    } 
    if(coup_valide(x_from,y_from,Rb[0],Rb[1])){
    
        checkmate = 1;
        for (int u=0;u<8;u++){
        for (int v=0;v<8;v++){
            if(plateau[u][v] != cv && plateau[u][v] % 2 == 0){
            int **cases_jouables = path_piece(u,v);
            for(int a=0;a<nbre_cases_jouables;a++){
                if(!Leroi(u,v,cases_jouables[a][0],cases_jouables[a][1])){
                    checkmate = 0;
                    
                }
                path_piece(u,v);
                
            }
        }

        }
    
    }

    }
    
    plateau[x_to][y_to] = plateau[x_from][y_from];
    plateau[x_from][y_from] = permut;
    
    }
    return checkmate;
}

int echec_et_mat_noir(int x_to,int y_to,int x_from,int y_from){

    
    int checkmate = 0;
    int permut;
    if(coup_valide(x_to,y_to,x_from,y_from)){
    permut = plateau[x_from][y_from];
    plateau[x_from][y_from] = plateau[x_to][y_to];
    plateau[x_to][y_to] = cv;
    int Rn[2];
    for (int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            if(plateau[i][j] == crn){
                Rn[0] = i;
                Rn[1] = j;
            }
        }
    } 
    if(coup_valide(x_from,y_from,Rn[0],Rn[1])){
    
        checkmate = 1;
        for (int u=0;u<8;u++){
        for (int v=0;v<8;v++){
            if(plateau[u][v] != cv && plateau[u][v] % 2 != 0){
            int **cases_jouables = path_piece(u,v);
            for(int a=0;a<nbre_cases_jouables;a++){
                if(!Leroi(u,v,cases_jouables[a][0],cases_jouables[a][1])){
                    checkmate = 0;
                }
                path_piece(u,v);
                
            }
        }

        }
    
    }

    }
    
    plateau[x_to][y_to] = plateau[x_from][y_from];
    plateau[x_from][y_from] = permut;
    
    }
    return checkmate;
    
}