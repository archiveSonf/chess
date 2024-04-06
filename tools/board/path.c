#include "./board.h"
#include <stdio.h>
#include <stdlib.h>

//void full_cases_jouables(int *nbre_cases_jouables, int ** cases_jouables, int x_to, int y_to){
//    nbre_cases_jouables++;
//    cases_jouables[*nbre_cases_jouables-1][0] = x_to;
//    cases_jouables[*nbre_cases_jouables-1][1] = y_to;
//}

int** path_piece (int x_to, int y_to){
    
    int nbre_cases_jouables=28;
    int **cases_jouables;
    cases_jouables = (int **)malloc(nbre_cases_jouables * sizeof(int *));
    if (cases_jouables == NULL) {
        printf("Erreur d'allocation de mémoire pour les lignes.\n");
            }
    for (int i = 0; i<nbre_cases_jouables; i++){
        cases_jouables[i] = (int *)malloc( 2 * sizeof(int));
        if (cases_jouables[i] == NULL) {
        printf("Erreur d'allocation de mémoire pour les colonnes.\n");
    }
    }
    //for (int i = 0; i < nbre_cases_jouables; i++) {
    //    free(cases_jouables[i]);
    //}
//
    //// Libérer la mémoire allouée pour les pointeurs de lignes
    //free(cases_jouables);
    
    switch (plateau[x_to][y_to])
    {
    case 6 :
    case 7 :
        nbre_cases_jouables = 0;
        int joueur = plateau[x_to][y_to] % 2;
        y_to++;
        int horizontal = 2;
        int vertical = 2;
        while(y_to < 8 && plateau[x_to][y_to] == -1) {
            nbre_cases_jouables++;
            cases_jouables[nbre_cases_jouables-1][0] = x_to;
            cases_jouables[nbre_cases_jouables-1][1] = y_to;
            y_to++;
            horizontal++;
        }
        if(y_to < 8 && plateau[x_to][y_to] != -1 && plateau[x_to][y_to] % 2 != joueur){
                nbre_cases_jouables++;
                cases_jouables[nbre_cases_jouables-1][0] = x_to;
                cases_jouables[nbre_cases_jouables-1][1] = y_to;
            }

        y_to = y_to - horizontal;
        horizontal = 2;
        while(y_to >= 0 && plateau[x_to][y_to] == -1){
            nbre_cases_jouables++;
            cases_jouables[nbre_cases_jouables-1][0] = x_to;
            cases_jouables[nbre_cases_jouables-1][1] = y_to;
            y_to--;
            horizontal++;
        }
        if(y_to >= 0 && plateau[x_to][y_to] != -1 && plateau[x_to][y_to] % 2 != joueur){
                nbre_cases_jouables++;
                cases_jouables[nbre_cases_jouables-1][0] = x_to;
                cases_jouables[nbre_cases_jouables-1][1] = y_to;
            }

        y_to = y_to + horizontal -1;
        x_to++;
        while (x_to < 8 && plateau[x_to][y_to] == -1){
            nbre_cases_jouables++;
            cases_jouables[nbre_cases_jouables-1][0] = x_to;
            cases_jouables[nbre_cases_jouables-1][1] = y_to;
            x_to++;
            vertical++;
        }
        if(x_to < 8 && plateau[x_to][y_to] != -1 && plateau[x_to][y_to] % 2 != joueur){
                nbre_cases_jouables++;
                cases_jouables[nbre_cases_jouables-1][0] = x_to;
                cases_jouables[nbre_cases_jouables-1][1] = y_to;
            }

        x_to = x_to - vertical;
        while(x_to >= 0 && plateau[x_to][y_to] == -1) {
            nbre_cases_jouables++;
            cases_jouables[nbre_cases_jouables-1][0] = x_to;
            cases_jouables[nbre_cases_jouables-1][1] = y_to;
            x_to--;
        }
        if(x_to >= 0 && plateau[x_to][y_to] != -1 && plateau[x_to][y_to] % 2 != joueur){
                nbre_cases_jouables++;
                cases_jouables[nbre_cases_jouables-1][0] = x_to;
                cases_jouables[nbre_cases_jouables-1][1] = y_to;
            }
        
        return cases_jouables;
        break;

    case 4:
    case 5:
        nbre_cases_jouables = 0;
        joueur = plateau[x_to][y_to] % 2;
        if(x_to + 2 < 8){
            if(y_to - 1 >= 0 && plateau[x_to+2][y_to-1] % 2 != joueur){
                nbre_cases_jouables++;
                cases_jouables[nbre_cases_jouables-1][0] = x_to + 2;
                cases_jouables[nbre_cases_jouables-1][1] = y_to - 1;
            }
            if(y_to + 1 < 8 && plateau[x_to+2][y_to+1] % 2 != joueur){
                nbre_cases_jouables++;
                cases_jouables[nbre_cases_jouables-1][0] = x_to + 2;
                cases_jouables[nbre_cases_jouables-1][1] = y_to + 1;
            }
        }
        if(x_to + 1 < 8){
            if(y_to - 2 >= 0 && plateau[x_to+1][y_to-2] % 2 != joueur){
                nbre_cases_jouables++;
                cases_jouables[nbre_cases_jouables-1][0] = x_to + 1;
                cases_jouables[nbre_cases_jouables-1][1] = y_to - 2;
            }
            if(y_to + 2 < 8 && plateau[x_to+1][y_to+2] % 2 != joueur){
                nbre_cases_jouables++;
                cases_jouables[nbre_cases_jouables-1][0] = x_to + 1;
                cases_jouables[nbre_cases_jouables-1][1] = y_to + 2;
            }
        }
        if(x_to - 1 > 0){
            if(y_to - 2 >= 0 && plateau[x_to-1][y_to-2] % 2 != joueur){
                nbre_cases_jouables++;
                cases_jouables[nbre_cases_jouables-1][0] = x_to - 1;
                cases_jouables[nbre_cases_jouables-1][1] = y_to - 2;
            }
            if(y_to + 2 < 8 && plateau[x_to-1][y_to+2] % 2 != joueur){
                nbre_cases_jouables++;
                cases_jouables[nbre_cases_jouables-1][0] = x_to - 1;
                cases_jouables[nbre_cases_jouables-1][1] = y_to + 2;
            }
        }
        if(x_to - 2 > 0){
            if(y_to - 1 >= 0 && plateau[x_to-2][y_to-1] % 2 != joueur){
                nbre_cases_jouables++;
                cases_jouables[nbre_cases_jouables-1][0] = x_to - 2;
                cases_jouables[nbre_cases_jouables-1][1] = y_to - 1;
            }
            if(y_to + 1 < 8 && plateau[x_to-2][y_to+1] % 2 != joueur){
                nbre_cases_jouables++;
                cases_jouables[nbre_cases_jouables-1][0] = x_to - 2;
                cases_jouables[nbre_cases_jouables-1][1] = y_to + 1;
            }
        }
        return cases_jouables;
        break;

    case 0:
        nbre_cases_jouables = 0;
        joueur = plateau[x_to][y_to] % 2;
        if(plateau[x_to+1][y_to]==-1){
            nbre_cases_jouables++;
            cases_jouables[nbre_cases_jouables-1][0] = x_to + 1;
            cases_jouables[nbre_cases_jouables-1][1] = y_to;
        }
        if (plateau[x_to+1][y_to+1]!=-1 && plateau[x_to+1][y_to+1] % 2 != joueur){
            nbre_cases_jouables++;
            cases_jouables[nbre_cases_jouables-1][0] = x_to + 1;
            cases_jouables[nbre_cases_jouables-1][1] = y_to + 1;
        }
        if (plateau[x_to+1][y_to-1]!=-1 && plateau[x_to+1][y_to-1] % 2 != joueur){
            nbre_cases_jouables++;
            cases_jouables[nbre_cases_jouables-1][0] = x_to + 1;
            cases_jouables[nbre_cases_jouables-1][1] = y_to - 1;
        }
        if (x_to==1 && plateau[x_to+2][y_to]==-1 && plateau[x_to+1][y_to]==-1){
            nbre_cases_jouables++;
            cases_jouables[nbre_cases_jouables-1][0] = x_to + 2;
            cases_jouables[nbre_cases_jouables-1][1] = y_to;
        }
        return cases_jouables;

        break;
    case 1:
        nbre_cases_jouables = 0;
        joueur = plateau[x_to][y_to] % 2;
        if(plateau[x_to-1][y_to]==-1){
            nbre_cases_jouables++;
            cases_jouables[nbre_cases_jouables-1][0] = x_to - 1;
            cases_jouables[nbre_cases_jouables-1][1] = y_to;
        }
        if (plateau[x_to-1][y_to+1]!=-1 && plateau[x_to-1][y_to+1] % 2 != joueur){
            nbre_cases_jouables++;
            cases_jouables[nbre_cases_jouables-1][0] = x_to - 1;
            cases_jouables[nbre_cases_jouables-1][1] = y_to + 1;
        }
        if (plateau[x_to-1][y_to-1]!=-1 && plateau[x_to-1][y_to-1] % 2 != joueur){
            nbre_cases_jouables++;
            cases_jouables[nbre_cases_jouables-1][0] = x_to - 1;
            cases_jouables[nbre_cases_jouables-1][1] = y_to - 1;
        }
        if (x_to==6 && plateau[x_to-2][y_to]==-1 && plateau[x_to-1][y_to]==-1){
            nbre_cases_jouables++;
            cases_jouables[nbre_cases_jouables-1][0] = x_to - 2;
            cases_jouables[nbre_cases_jouables-1][1] = y_to;
        }
        return cases_jouables;

        break;
    
    case 2:
    case 3:
        nbre_cases_jouables = 0;
        joueur = plateau[x_to][y_to] % 2;
        x_to++;
        y_to++;
        int oblique1 = 2;
        int oblique2 = 2;
        while(y_to < 8 && x_to < 8 && plateau[x_to][y_to] == -1) {
            nbre_cases_jouables++;
            cases_jouables[nbre_cases_jouables-1][0] = x_to;
            cases_jouables[nbre_cases_jouables-1][1] = y_to;
            x_to++;
            y_to++;
            oblique1++;
        }
        if(y_to < 8 && x_to<8 && plateau[x_to][y_to] != -1 && plateau[x_to][y_to] % 2 != joueur){
                nbre_cases_jouables++;
                cases_jouables[nbre_cases_jouables-1][0] = x_to;
                cases_jouables[nbre_cases_jouables-1][1] = y_to;
            }
        x_to = x_to - oblique1;
        y_to = y_to - oblique1;
        oblique1 = 2;
        while(y_to >= 0 && x_to>=0 && plateau[x_to][y_to] == -1){
            nbre_cases_jouables++;
            cases_jouables[nbre_cases_jouables-1][0] = x_to;
            cases_jouables[nbre_cases_jouables-1][1] = y_to;
            x_to--;
            y_to--;
            oblique1++;
        }
        if(y_to >= 0 && x_to>=0 && plateau[x_to][y_to] != -1 && plateau[x_to][y_to] % 2 != joueur){
                nbre_cases_jouables++;
                cases_jouables[nbre_cases_jouables-1][0] = x_to;
                cases_jouables[nbre_cases_jouables-1][1] = y_to;
            }
        x_to = x_to + oblique1 -1;
        y_to = y_to + oblique1 -1;
        x_to++;
        y_to--;
        while (x_to < 8 && y_to>=0 && plateau[x_to][y_to] == -1){
            nbre_cases_jouables++;
            cases_jouables[nbre_cases_jouables-1][0] = x_to;
            cases_jouables[nbre_cases_jouables-1][1] = y_to;
            x_to++;
            y_to--;
            oblique2++;
        }
        if(y_to >= 0 && x_to<8 && plateau[x_to][y_to] != -1 && plateau[x_to][y_to] % 2 != joueur){
                nbre_cases_jouables++;
                cases_jouables[nbre_cases_jouables-1][0] = x_to;
                cases_jouables[nbre_cases_jouables-1][1] = y_to;
            }

        x_to = x_to - oblique2;
        y_to = y_to + oblique2;
        while(x_to >= 0 && y_to<8 && plateau[x_to][y_to] == -1) {
            nbre_cases_jouables++;
            cases_jouables[nbre_cases_jouables-1][0] = x_to;
            cases_jouables[nbre_cases_jouables-1][1] = y_to;
            x_to--;
            y_to++;
        }
        if(y_to < 8 && x_to>=0 && plateau[x_to][y_to] != -1 && plateau[x_to][y_to] % 2 != joueur){
                nbre_cases_jouables++;
                cases_jouables[nbre_cases_jouables-1][0] = x_to;
                cases_jouables[nbre_cases_jouables-1][1] = y_to;
            }
        return cases_jouables;
        break;

    case 8:
    case 9:
        nbre_cases_jouables = 0;
        joueur = plateau[x_to][y_to] % 2;
        y_to++;
        horizontal = 2;
        vertical = 2;
        while(y_to < 8 && plateau[x_to][y_to] == -1) {
            nbre_cases_jouables++;
            cases_jouables[nbre_cases_jouables-1][0] = x_to;
            cases_jouables[nbre_cases_jouables-1][1] = y_to;
            y_to++;
            horizontal++;
        }
        if(y_to < 8 && plateau[x_to][y_to] != -1 && plateau[x_to][y_to] % 2 != joueur){
                nbre_cases_jouables++;
                cases_jouables[nbre_cases_jouables-1][0] = x_to;
                cases_jouables[nbre_cases_jouables-1][1] = y_to;
            }

        y_to = y_to - horizontal;
        horizontal = 2;
        while(y_to >= 0 && plateau[x_to][y_to] == -1){
            nbre_cases_jouables++;
            cases_jouables[nbre_cases_jouables-1][0] = x_to;
            cases_jouables[nbre_cases_jouables-1][1] = y_to;
            y_to--;
            horizontal++;
        }
        if(y_to >= 0 && plateau[x_to][y_to] != -1 && plateau[x_to][y_to] % 2 != joueur){
                nbre_cases_jouables++;
                cases_jouables[nbre_cases_jouables-1][0] = x_to;
                cases_jouables[nbre_cases_jouables-1][1] = y_to;
            }

        y_to = y_to + horizontal -1;
        x_to++;
        while (x_to < 8 && plateau[x_to][y_to] == -1){
            nbre_cases_jouables++;
            cases_jouables[nbre_cases_jouables-1][0] = x_to;
            cases_jouables[nbre_cases_jouables-1][1] = y_to;
            x_to++;
            vertical++;
        }
        if(x_to < 8 && plateau[x_to][y_to] != -1 && plateau[x_to][y_to] % 2 != joueur){
                nbre_cases_jouables++;
                cases_jouables[nbre_cases_jouables-1][0] = x_to;
                cases_jouables[nbre_cases_jouables-1][1] = y_to;
            }

        x_to = x_to - vertical;
        vertical = 2;
        while(x_to >= 0 && plateau[x_to][y_to] == -1) {
            nbre_cases_jouables++;
            cases_jouables[nbre_cases_jouables-1][0] = x_to;
            cases_jouables[nbre_cases_jouables-1][1] = y_to;
            x_to--;
            vertical++;
        }
        if(x_to >= 0 && plateau[x_to][y_to] != -1 && plateau[x_to][y_to] % 2 != joueur){
                nbre_cases_jouables++;
                cases_jouables[nbre_cases_jouables-1][0] = x_to;
                cases_jouables[nbre_cases_jouables-1][1] = y_to;
            }
        x_to = x_to + vertical - 1;


        x_to++;
        y_to++;
        oblique1 = 2;
        oblique2 = 2;
        while(y_to < 8 && x_to < 8 && plateau[x_to][y_to] == -1) {
            nbre_cases_jouables++;
            cases_jouables[nbre_cases_jouables-1][0] = x_to;
            cases_jouables[nbre_cases_jouables-1][1] = y_to;
            x_to++;
            y_to++;
            oblique1++;
        }
        if(y_to < 8 && x_to<8 &&plateau[x_to][y_to] != -1 && plateau[x_to][y_to] % 2 != joueur){
                nbre_cases_jouables++;
                cases_jouables[nbre_cases_jouables-1][0] = x_to;
                cases_jouables[nbre_cases_jouables-1][1] = y_to;
            }
        x_to = x_to - oblique1;
        y_to = y_to - oblique1;
        oblique1 = 2;
        while(y_to >= 0 && x_to>=0 && plateau[x_to][y_to] == -1){
            nbre_cases_jouables++;
            cases_jouables[nbre_cases_jouables-1][0] = x_to;
            cases_jouables[nbre_cases_jouables-1][1] = y_to;
            x_to--;
            y_to--;
            oblique1++;
        }
        if(y_to >= 0 && x_to>=0 && plateau[x_to][y_to] != -1 && plateau[x_to][y_to] % 2 != joueur){
                nbre_cases_jouables++;
                cases_jouables[nbre_cases_jouables-1][0] = x_to;
                cases_jouables[nbre_cases_jouables-1][1] = y_to;
            }
        x_to = x_to + oblique1 -1;
        y_to = y_to + oblique1 -1;
        x_to++;
        y_to--;
        while (x_to < 8 && y_to>=0 && plateau[x_to][y_to] == -1){
            nbre_cases_jouables++;
            cases_jouables[nbre_cases_jouables-1][0] = x_to;
            cases_jouables[nbre_cases_jouables-1][1] = y_to;
            x_to++;
            y_to--;
            oblique2++;
        }
        if(y_to >= 0 && x_to<8 && plateau[x_to][y_to] != -1 && plateau[x_to][y_to] % 2 != joueur){
                nbre_cases_jouables++;
                cases_jouables[nbre_cases_jouables-1][0] = x_to;
                cases_jouables[nbre_cases_jouables-1][1] = y_to;
            }

        x_to = x_to - oblique2;
        y_to = y_to + oblique2;
        while(x_to >= 0 && y_to<8 && plateau[x_to][y_to] == -1) {
            nbre_cases_jouables++;
            cases_jouables[nbre_cases_jouables-1][0] = x_to;
            cases_jouables[nbre_cases_jouables-1][1] = y_to;
            x_to--;
            y_to++;
        }
        if(y_to < 8 && x_to>=0 && plateau[x_to][y_to] != -1 && plateau[x_to][y_to] % 2 != joueur){
                nbre_cases_jouables++;
                cases_jouables[nbre_cases_jouables-1][0] = x_to;
                cases_jouables[nbre_cases_jouables-1][1] = y_to;
            }
            
            return cases_jouables;
            break;

    case 10:
    case 11:
        nbre_cases_jouables = 0;
        joueur = plateau[x_to][y_to] % 2;
        if(plateau[x_to-1][y_to]%2 != joueur && x_to-1>=0){
            nbre_cases_jouables++;
            cases_jouables[nbre_cases_jouables-1][0] = x_to - 1;
            cases_jouables[nbre_cases_jouables-1][1] = y_to;
        }
        if (plateau[x_to-1][y_to+1] % 2 != joueur && x_to-1>=0 && y_to+1<8){
            nbre_cases_jouables++;
            cases_jouables[nbre_cases_jouables-1][0] = x_to - 1;
            cases_jouables[nbre_cases_jouables-1][1] = y_to + 1;
        }
        if (plateau[x_to-1][y_to-1] % 2 != joueur && x_to-1>=0 && y_to-1>=0){
            nbre_cases_jouables++;
            cases_jouables[nbre_cases_jouables-1][0] = x_to - 1;
            cases_jouables[nbre_cases_jouables-1][1] = y_to - 1;
        }
        if(plateau[x_to+1][y_to]%2 != joueur && x_to+1<8){
            nbre_cases_jouables++;
            cases_jouables[nbre_cases_jouables-1][0] = x_to + 1;
            cases_jouables[nbre_cases_jouables-1][1] = y_to;
        }
        if (plateau[x_to+1][y_to+1] % 2 != joueur && x_to+1<8 && y_to+1<8){
            nbre_cases_jouables++;
            cases_jouables[nbre_cases_jouables-1][0] = x_to + 1;
            cases_jouables[nbre_cases_jouables-1][1] = y_to + 1;
        }
        if (plateau[x_to+1][y_to-1] % 2 != joueur && x_to+1<8 && y_to-1>=0){
            nbre_cases_jouables++;
            cases_jouables[nbre_cases_jouables-1][0] = x_to + 1;
            cases_jouables[nbre_cases_jouables-1][1] = y_to - 1;
        }
        if (plateau[x_to][y_to+1] % 2 != joueur && y_to+1<8){
            nbre_cases_jouables++;
            cases_jouables[nbre_cases_jouables-1][0] = x_to;
            cases_jouables[nbre_cases_jouables-1][1] = y_to+1;
        }
        if (plateau[x_to][y_to-1] % 2 != joueur && y_to-1>=0){
            nbre_cases_jouables++;
            cases_jouables[nbre_cases_jouables-1][0] = x_to;
            cases_jouables[nbre_cases_jouables-1][1] = y_to-1;
        }
        return cases_jouables;
        
        break;
    
    default:
        break;
    }

     
}

int coup_valide(int x_to,int y_to,int x_from,int y_from){
    int verified = 0;
    int **cases_jouables;

    cases_jouables = path_piece(x_to,y_to);
    //for (int i= 0; i<sizeof(cases_jouables);i++){
    //            printf("\n%d %d\n",cases_jouables[i][0],cases_jouables[i][1]);
    //    }

    for (int i=0;i<sizeof(cases_jouables);i++){
        if(cases_jouables[i][0]==x_from && cases_jouables[i][1]==y_from){
            verified = 1;
            break;
    }
}

return verified;

}