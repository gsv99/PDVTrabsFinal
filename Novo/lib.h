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

struct usuario{
    char nome[50];
    char *login;
    char *senha;
    int tipo;
    int ponto;
    int usuario_qntd;
    struct usuario* prox;
};

struct userlista{
    user * prim;
    user * ult;
    int user_qntd;
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
user_dados* criarListaUser(void);	//NULL para erro
int inserirUser(user_dados*);		//1 para sucesso e, 0 para erro
//int removerUser(user_dados*);			//1 para sucesso e, 0 para erro
int quantidadeUser(user_dados* );	//quantidade para sucesso e, -1 para erro
//int apagarListaUser(user_dados** );		//1 para sucesso e, 0 para erro

void adduser(user_dados* l, char*  str, char *psw, int tipo);
void ListarContas(user_dados* l);
int fazer_login(user_dados* lg, char *user, char *psw);

void menuscope(int aut);
void Administrador(int aut, ListaBlocos*, user_dados*, cesta_dados*);
void Funcionario(int aut, ListaBlocos*, cesta_dados*);

//----------------------------------------------------------------------------

//Bloco Produtos
ListaBlocos* criarListaBlocos(void);	//NULL para erro
int inserirBloco(ListaBlocos*);		//1 para sucesso e, 0 para erro
int removerBloco(ListaBlocos*);			//1 para sucesso e, 0 para erro
int quantidadeBlocos(ListaBlocos*);	//quantidade para sucesso e, -1 para erro
int apagarListaBlocos(ListaBlocos** );		//1 para sucesso e, 0 para erro

void addproduto(ListaBlocos* l, char*  str, int barra, float vcompra, float vvenda);
void AdicionarEstoque(ListaBlocos* l, int id);
void ListarProdutos(ListaBlocos* l, int aut);

//----------------------------------------------------------------------------

void FazerVenda(ListaBlocos* l, cesta_dados* c);

cesta_dados* criarListaCesta(void);	//NULL para erro
int inserirCesta(cesta_dados*);		//1 para sucesso e, 0 para erro
int removerCesta(cesta_dados*, int);			//1 para sucesso e, 0 para erro
int quantidadeCesta(cesta_dados* );	//quantidade para sucesso e, -1 para erro
void fazerCesta(cesta_dados* c, char*  str, int id_prod, int qnt_prod, float total_prod);
void MostraCarrinho(cesta_dados* c, int);