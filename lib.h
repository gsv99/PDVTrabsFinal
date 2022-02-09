#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct lista ListaBlocos;
typedef struct no produto;

typedef struct userlista user_dados;
typedef struct usuario user;

typedef struct cestalista cesta_dados;
typedef struct Cesta carrinho;

struct usuario{
    char nome[50];
    char *login;
    char *senha;
    int tipo;
    int usuario_qntd;
    struct usuario* prox;
};

struct userlista{
    user * prim;
    user * ult;
    int user_qntd;
    int tamanho;
};

struct no{
    int id;
	char *nome;
    int cod_barra;
    int qntd;
    float valorcompra;
    float valorvenda;
    struct no* prox;
};

struct lista{
	produto* prim;
	produto* ult;
    int id_p;
	int tamanho;
};

struct Cesta{
    char *nome_produto;
    int id_produto;
    int qnt_produto; 
    float total_produto;

    struct Cesta* prox;
    struct Cesta* ant;
};

struct cestalista{
    carrinho * prim;
    carrinho * ult;
    float total_carrinho;
    int tamanho;
};

//Bloco Users
user_dados* criarListaUser(void);
int inserirUser(user_dados*);
int quantidadeUser(user_dados* );

void adduser(user_dados* l, char*  str, char *psw, int tipo);
void ListarContas(user_dados* l);
int fazer_login(user_dados* lg, char *user, char *psw);

void menuscope(int aut);
void Administrador(int aut, ListaBlocos*, user_dados*, cesta_dados*);
void Funcionario(int aut, ListaBlocos*, cesta_dados*);

//----------------------------------------------------------------------------

//Bloco Produtos
ListaBlocos* criarListaBlocos(void);
int inserirBloco(ListaBlocos*);
int quantidadeBlocos(ListaBlocos*);

void addproduto(ListaBlocos* l, char*  str, int barra, float vcompra, float vvenda, int qntd);
void AdicionarEstoque(ListaBlocos* l, int id);
void ListarProdutos(ListaBlocos* l, int aut);

//----------------------------------------------------------------------------

void FazerVenda(ListaBlocos* l, cesta_dados* c);

cesta_dados* criarListaCesta(void);
int inserirCesta(cesta_dados*);
int quantidadeCesta(cesta_dados* );
void fazerCesta(cesta_dados* c, char*  str, int id_prod, int qnt_prod, float total_prod);
void MostraCarrinho(cesta_dados* c, int);


//-----------------------------------------------------------------------------
void Salvar_carrinho(cesta_dados*);

int ler_dados(ListaBlocos*);
void Salvar_estoque(ListaBlocos*);

int ler_conta(user_dados*);
void salvar_conta(user_dados*);
