#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto{
    char nome[50];
    int qntd;
    float valorcompra;
    float valorvenda;

    struct produto * prox;
    struct produto * ant;
}Produto;

typedef struct usuario{
    char nome[50];
    char login[12];
    int senha[8];
    int tipo;
    int ponto;
    
    struct usuario * prox;
    struct usuario * ant;
}user;


void menuscope();
int Administrador(int autent);
int FdCaixa(int autent);
void CadastrarProduto(char *nome, float valorcompra, float valorvenda, int qntd, int pos);
int removerproduto(int pos);
int DiminuirEstoque(int id, int qntd);
void FazerVenda();
void ConsultaEstoque();
void AbrirCaixa();
int LogarConta(int aut);