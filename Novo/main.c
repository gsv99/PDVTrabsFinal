#include "lib.h"

#define Admin 1
#define Curumi 0 // PS: sinonimo de Funcionario

int main(){
    int choice, login = 2;
    char str[12], psw[8];
    ListaBlocos* lista = NULL;	
    lista = criarListaBlocos();

    user_dados* user_lista = NULL;	
    user_lista = criarListaUser();

    do{
        printf("Criar a conta administradora:\nPS: Nao possui conta:\nPressionar enter para continuar\n");
        getchar();
        login = 1;
        Administrador(login, lista, user_lista);
    }while(user_lista->prim == NULL);

    login = 2;

    while(login != 1 || login != 0){
        if(login == 1 || login == 0)
            break;
        printf("-------- FAÇA SEU LOGIN --------\n");
        printf("LOGIN: ");
        scanf("%12[^\n]%*c", str);
        puts("");
        printf("SENHA: ");
        scanf("%8[^\n]%*c", psw);
        login = fazer_login(user_lista, str, psw);
        printf("LoginID: %d\n", login);

    }
// falta while aki
    if(login == Admin){
        Administrador(login, lista, user_lista);
    }
    else if(login == Curumi){
        Funcionario(login, lista);
    }

    return 0;
}

void menuscope(int aut){
    if(aut==-1){
        return;
    }

    else if(aut == 1){
        printf("\n*-------------------- Administrador --------------------*\n");
        printf("* 1-| Cadastrar Contas:                                 *\n");
        printf("* 2-| Mostrar Contas:                                   *\n");
        printf("* 3-| Cadastrar Produto:                                *\n");
        printf("* 4-| Adicionar Estoque:                                *\n");
        printf("* 5-| Remover Produto:                                  *\n");
        printf("* 6-| Consulta Estoque:                                 *\n");
        printf("* 7-| Fazer Venda:                                      *\n");
        printf("* 8-| Sair:                                             *\n");
        printf("*-------------------------------------------------------*\n");
        printf("Opção: ");
    }

    else{
        printf("\n*-------------------- Funcionario --------------------*\n");
        printf("* 1-| Fazer Venda:                                      *\n");
        printf("* 2-| Consulta Estoque:                                 *\n");
        printf("* 0-| Sair:                                             *\n");
        printf("*-------------------------------------------------------*\n");
        printf("Opção: ");
    }
}

void Administrador(int aut, ListaBlocos* lista, user_dados* user_lista){
    int choice;
    if(aut != 1)
        return;
    while(1){
        char nomeprod[50], login[12], senha[8];
        int cod_barra, tipo;
        float valorvenda, valorcompra;
        int inqntd, id;
        //system("clear");
        menuscope(aut);
        scanf("%d", &choice);
        getchar();
        if(choice == 8)
            break;
        switch (choice){
        case 1:
            printf("Digite seu login :\n");
            scanf("%12[^\n]%*c", login);
            printf("Digite sua senha :\n");
            scanf("%8[^\n]%*c", senha);
            printf("Digite 1 para administrador ou 0 para funcionario :\n");
            scanf("%d", &tipo);
            adduser(user_lista, login, senha, tipo);
            break;
        case 2:
            ListarContas(user_lista);
            break;
        case 3:
            printf("\n*-------------------- Cadastrar Produto --------------------*\n");
            printf("* Nome:                                                       *\n");
            scanf("%50[^\n]%*c", nomeprod);
            printf("* Codico de Barra:                                            *\n"); // So por enquanto nao edito o codico
            scanf("%d", &cod_barra);
            printf("* Valor de Compra:                                            *\n");
            scanf("%f", &valorvenda);
            printf("* Valor de Venda:                                             *\n");
            scanf("%f", &valorcompra);
            printf("*-------------------------------------------------------------*\n");
            addproduto(lista, nomeprod, cod_barra, valorvenda, valorcompra);
            break;
        case 4:
            printf("AdicionarEstoque:\n Digite o ID do produto: ");
            scanf("%d", &id);
            AdicionarEstoque(lista, id);
            break;
        case 5:
            printf("Remover Produto\n");
            //removerproduto(pos);
            break;
        case 6:
            printf("Consulta Estoque\n");
            ListarProdutos(lista, aut);
            break;
        case 7:
            printf("Fazer Venda\n");
            FazerVenda(lista);
            break;
        default:
            break;
        }
    }
}

void Funcionario(int aut, ListaBlocos* lista){
    int choice;
    if(aut != 0)
        return;

    do{
        int id, outqntd;
        system("clear");
        menuscope(aut);
        scanf("%d", &choice);
        getchar();
        
        switch (choice){
        case 0:
            //exit(0);
            break;
        case 1:
            FazerVenda(lista);
            break;
        case 2:
            printf("Consulta Estoque\n");
            ListarProdutos(lista, aut);
            break;
        default:
            break;
        }
    }while(choice!=0);
}