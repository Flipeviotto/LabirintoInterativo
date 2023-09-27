#include "HeadersFolders/AnalisesFunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

char * BuscaInicio(char *mat,int linha, int coluna, int* x, int* y){
    int primeiro=0;
    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            if(*(mat+i*coluna+j)=='p'){
                *x=j;
                *y=i;
                return(mat+i*coluna+j);
            }
            else if(primeiro==0 && *(mat+i*coluna+j)==' '){
                *x=j;
                *y=i;
                primeiro=1;
            }
        }
    }
    if(primeiro==0){
        printf("Nao foi possivel definir ponto de partida.\n");
        exit(1);
    }
    return(mat+ *x*coluna+ *y);
}

