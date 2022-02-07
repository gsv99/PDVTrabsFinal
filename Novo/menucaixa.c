#include "lib.h"

#define Admin = 1
#define Funcionario = 0

int autent = -1;


int LogarConta(int aut){
    printf("\n[%d]", aut);
    if(aut==0){
        printf("Voce esta logado ao NOME");
        autent = 0;
        FdCaixa(autent);
    }
    else if(aut == 1){
        printf("Voce esta logado como Administrador");
        autent = 1;
        Administrador(autent);
    }
    else{
        printf("Voce nao esta logado");
        return -1;
    }
    return 1;
}