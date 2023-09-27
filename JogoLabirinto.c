#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include "HeadersFolders/MatrizFunctions.h"
#include "HeadersFolders/AnalisesFunctions.h"


int main() {
    int ch;
    int x = 0, y = 0, lin, col;
    
    initscr(); // Inicia o modo curses
    raw(); // Desativa o buffer de linha
    keypad(stdscr, TRUE); // Permite a captura de teclas especiais como as setas
    noecho(); // Não mostra os caracteres digitados na tela
    
    char * mat = CriaMatriz(&lin,&col);
    
    char * p = BuscaInicio(mat,lin,col,&x,&y);
    PrintaMatriz(mat,lin,col);
    
    mvprintw(y, x, "@"); // Desenha o personagem na posição inicial
    refresh(); // Atualiza a tela

    while((ch = getch()) != 'q') { // Enquanto 'q' não for pressionado
        mvprintw(y, x," "); // Apaga o personagem da posição antiga
        
        switch(ch) {
            case KEY_UP:
                if(*(p-col)!='#'){
                    y--;
                    p=p-col;
                }
                break;
            case KEY_DOWN:
                if(*(p+col)!='#'){
                    y++;
                    p=p+col;
                }
                break;
            case KEY_LEFT:
                if(*(p-1)!='#'){
                    x--;
                    p=p-1;
                }   
                break;
            case KEY_RIGHT:
                if(*(p+1)!='#'){
                    x++;
                    p=p+1;
                }   
                break;
        }
        mvprintw(y, x,"@"); // Desenha o personagem na nova posição
        refresh(); // Atualiza a tela
        if(*p =='o'){
            break;
        }
        
    }

    endwin(); // Finaliza o modo curses
    printf("Encontrou a saida\n");

    return 0;
}
