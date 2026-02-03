#include "testes.h"

void verificar(void* ptr){
    if(ptr==NULL){
        perror("Erro ao alocar memoria em testes");
        exit(EXIT_FAILURE);
    }
}

void produtoTeste(NodeProduto** lista, char* codigo, char* nome, double preco, int quantidade){
    NodeProduto* novoNode = malloc(sizeof(NodeProduto));
    verificar(novoNode);
    novoNode->produto = malloc(sizeof(Produto));
    verificar(novoNode->produto);
    novoNode->produto->codigo=copiarString(codigo);
    novoNode->produto->nome=copiarString(nome);
    novoNode->produto->preco=preco;
    novoNode->produto->quantidade=quantidade;

    novoNode->proximo=(*lista);
    (*lista)=novoNode;
}

void clienteTeste(NodeCliente** lista, char* cpf, char* nome, char* telefone, char* email){
    NodeCliente* novoNode = malloc(sizeof(NodeCliente));
    verificar(novoNode);
    novoNode->data = malloc(sizeof(Cliente));
    verificar(novoNode->data);
    novoNode->data->cpf=copiarString(cpf);
    novoNode->data->nome=copiarString(nome);
    novoNode->data->email=(copiarString(email));
    novoNode->data->telefone=copiarString(telefone);
    novoNode->data->dataNascimento=copiarString("01012000");
    novoNode->data->carrinho=NULL;

    novoNode->proximo=(*lista);
    (*lista)=novoNode;
}

void objetosTeste(NodeProduto** produtos, NodeCliente** clientes){
    free_ListaClientes(clientes, produtos);
    freeProdutos(produtos);
    
    char* nomes[]={"Lucas U.B.", "Eduardo", "Joao Pedro", "Gregory House", "Pessonilson Comunindo", "Testonildo"};
    char* codigos[]={"001","657","091","codigo","4444","123456789"};
    char* nomesProduto[]={"Produto Generico", "Genericador 3000", "Tijolo", "Abobora", "Europa", "Quadrado Qualquer"};
    int quantidades[]={0,1,5,10,20,50};
    double precos[]={199.99, 1.50, 0.60, 8.75, 5249.99, 10000.02};
    char cpf[][12]={"11111111111","22222222222","33333333333","44444444444","55555555555","66666666666"};
    char* telefone[]={"61935953053", "61950345134", "62967753421", "60910670134", "99999999999", "99988776655"};
    char* email[]={"lucas.ub@email.com","eduardo@insee.web","joao.pedro@moj.com","gregh@mdhouse.org","pessonilson@comun.br","tes_teste@tst.tst"};

    for(int i=0; i<6; i++)
        produtoTeste(produtos,codigos[i],nomesProduto[i],precos[i],quantidades[i]);
    for(int i=0; i<6; i++)
        clienteTeste(clientes,cpf[i],nomes[i],telefone[i],email[i]);
}