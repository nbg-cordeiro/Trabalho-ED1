#include "auxiliares.h"

void limpaBuffer(void){
    int c=0;
    while(c!='\n' && c!=EOF)
        c=getchar();
}

void limpaConsole(void){
    #ifdef _WIN32
         system("cls");
    #else
        printf("\033[H\033[J");
    #endif
}

char* lerString(){
    char* str = malloc(32*sizeof(char));
    if(str==NULL){
        perror("Erro ao alocar memoria em lerString()");
        exit(EXIT_FAILURE);
    }
    (*str) = '\0';
    int letra, i=0, size=32;
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
    if(string1==NULL || string2==NULL)
        return 0;
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

int validaEntradaNumero(char* string,int limite){
    if (!string)
        return 0;
    if (tamanhoString(string) != (limite+1))
        return 0;
    for (int i = 0; i < (limite); i++){
        if (string[i] < '0' || string[i] > '9')
            return 0;
    }
    return 1;
}

int validaEntradaLetra(char* string){
    if (!string)
        return 0;
    int size = tamanhoString(string);
    for (int i = 0; i < (size-1); i++){
        int minuscula = ((string[i] >= 'a') && (string[i] <= 'z'));
        int maiuscula = ((string[i] >= 'A') && (string[i] <= 'Z'));
        int espaco = (string[i] == ' ');

        if (!(minuscula || maiuscula || espaco)){
            return 0;
        }
    }
    return 1;
}

int validaEmail(char* string){
    if (!string)    
        return 0;

    int tamanho = tamanhoString(string);
    if (tamanho < 5)
        return 0;
    if (string[0] == '@')
        return 0;
    if (string[tamanho-1] == '.')
        return 0;

    int arroba = 0;
    int ponto = 0;

    for (int index = 0; index < tamanho; index ++){
       if (string[index] == '@'){
            arroba++;
            if (arroba > 1){
                return 0;
            }
        }

        if (string[index] == '.'){
            if (arroba > 0 && string[index-1] == '@')
                return 0;
            
            if (index > 0 && string[index-1] == '.')
                return 0;

            if (arroba == 1){
                ponto = 1;
            }

        }  
        
    }

    if (arroba == 1 && ponto == 1){
        return 1;
    }

    return 0;
}

void continuar(){
    printf("\nPressione enter para continuar.\n");
    getchar();
}