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

char* lerString(){
    char* str = malloc(sizeof(char));
    if(str==NULL){
        perror("Erro ao alocar memoria em lerString()");
        exit(EXIT_FAILURE);
    }
    (*str) = '\0';
    int letra, i=0, size=1;
    while((letra=getchar())!=EOF && letra!='\n'){
        if(i>=(size-1)){
            size*=2;
            char* temp = realloc(str,size * sizeof(char));
            if(temp==NULL){
                perror("Erro ao realocar memoria em lerString()");
                exit(EXIT_FAILURE);
            }
            str = temp;
        }
        str[i++]=letra;
    }
    str[i]='\0';
    char* temp=realloc(str,i+1);
    if(temp==NULL){
        perror("Erro ao realocar memoria em lerString()");
        exit(EXIT_FAILURE);
    }
    str=temp;
    return str;
}