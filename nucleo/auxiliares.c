#include "auxiliares.h"

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
                free(str);
                str=NULL;
                exit(EXIT_FAILURE);
            }
            str = temp;
        }
        str[i++]=letra;
    }
    str[i]='\0';
    char* temp=realloc(str,i+1);
    if(temp==NULL){
        free(str);
        str=NULL;
        perror("Erro ao realocar memoria em lerString()");
        exit(EXIT_FAILURE);
    }
    str=temp;
    return str;
}

int compararString(char* string1, char* string2){
    int igual = 1, i = 0;
    while(1){
        if(string1[i]!=string2[i]){
            igual=0;
            break;
        }
        if(string1[i]=='\0')
            break;
        i++;
    }
    return igual;
}

int tamanhoString(char* string){
    if(string == NULL)
        return 0;
    int size = 0;
    while(string[size]!='\0')
        size++;
    return (size+1);
}

char* copiarString(char* original){
    if(original==NULL)
        return NULL;
    int tamanho = tamanhoString(original);
    char* copia = malloc(sizeof(char) * tamanho);
    if(copia==NULL){
        perror("Erro ao alocar memoria em copiarString()");
        exit(EXIT_FAILURE);
    }
    for(int i=0; i<tamanho; i++)
        copia[i]=original[i];
    return copia;
}

void continuar(){
    printf("\nPressione enter para continuar.\n");
    getchar();
}