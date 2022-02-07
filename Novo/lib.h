#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista ListaBlocos;
typedef struct no produto;

typedef struct userlista user_dados;
typedef struct usuario user;


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

struct userlista
{
    user * prim;
    user * ult;
    int user_qntd;
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

//----------------------------------------------------------------------------

//Bloco Produtos
ListaBlocos* criarListaBlocos(void);	//NULL para erro
int inserirBloco(ListaBlocos*);		//1 para sucesso e, 0 para erro
int removerBloco(ListaBlocos*);			//1 para sucesso e, 0 para erro
int quantidadeBlocos(ListaBlocos* );	//quantidade para sucesso e, -1 para erro
int apagarListaBlocos(ListaBlocos** );		//1 para sucesso e, 0 para erro

void ListarProdutos(ListaBlocos* l, int aut);
void FazerVenda(ListaBlocos* l);

void addproduto(ListaBlocos* l, char*  str, int barra, float vcompra, float vvenda);
void AdicionarEstoque(ListaBlocos* l, int id);

void menuscope(int aut);
void Administrador(int aut, ListaBlocos*, user_dados*);
void Funcionario(int aut, ListaBlocos*);

void FazerVenda();