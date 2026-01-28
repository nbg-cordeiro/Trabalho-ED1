#ifndef USUARIO_H
#define USUARIO_H

typedef struct Usuario{
    char* cpf;
    char* nome;
    char* telefone;
}Usuario;

Usuario criarUsuario(char*,char*,char*);
Usuario salvarUsuario(Usuario,void*);
Usuario lerUsuario(void*);

#endif