#include "auxiliares.h"

void freeLista(Node** lista){
    while((*lista) != NULL){
        Node* aux = (*lista)->proximo;
        free((*lista)->conteudo);
        (*lista)->conteudo=NULL;
        free((*lista));
        (*lista)=aux;
    }
}

void limpaBuffer(void){
    int c=0;
    while(c!='\n' && c!=EOF)
        c=getchar();
}

void limpaConsole(void){
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
