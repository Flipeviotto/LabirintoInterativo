#include "HeadersFolders/MatrizFunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>


char * CriaMatriz(int * lin, int * col){ //baixar o conteudo da matriz
    FILE * arq = fopen("labirinto.txt", "r");
    if(arq==NULL){
        printf("erro em abrir arquivo\n");
        exit(1);
    }
    
    fscanf(arq,"%d", lin); 
    *col = *lin;
    *lin = *lin -1;

    char c;
    char * mat = malloc(sizeof(char*)* (*col) * (*lin));
    for(int i=0;i< *lin * *col;i++){
        fscanf(arq,"%c", &c);
        if(c=='\n' && i==0 || c==' '){
            i--;
        }
        else if(c=='0'){
            *(mat+i) = ' ';
        }
        else if(c=='2'){
            *(mat+i) = 'p';
        }
        else if(c=='3'){
            *(mat+i) = 'o';
        }
        else if(c=='1'){
            *(mat+i) = '#';
        }
        else
            *(mat+i) = c;
            
    }
    fclose(arq);
    *(mat+*lin * *col-1) ='\n';

    return mat;
    
}

void PrintaMatriz(char * mat, int lin, int col){
    for(int i=0;i<lin;i++){
        int control = 0;
        for(int j=0;j<col;j++){
            if(*(mat+i*col+j)=='#')
                mvprintw(i,j+control,"#");
            else if(*(mat+i*col+j)=='o')
                mvprintw(i,j+control,"o");
            else
                mvprintw(i,j+control," ");
        }
    }
}