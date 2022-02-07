#include "lib.h"

Produto *inicio = NULL;
Produto *fim = NULL;
int tam = 0;



void CadastrarProduto(char *nome, float valorcompra, float valorvenda, int qntd, int pos){
    if(pos >= 0 && pos <= tam){
        
        Produto *novo =(Produto*) malloc (sizeof(Produto));
        novo->valorcompra = valorcompra;
        novo->valorvenda = valorvenda;
        novo->qntd = qntd;
        strcpy(novo->nome, nome);
        novo->prox = NULL;
        
        if(inicio == NULL){ //tam == 0 - lista vazia :D
            inicio = novo;
            fim = novo;
        }else if(pos == 0){ //no inicio da lista
            novo->prox = inicio;
            inicio = novo;
        }else if(pos == tam){// no fim da lista
            fim->prox = novo;
            fim = novo;
        }else{
            Produto *aux = inicio;
            int i;
            for(i=0; i< pos-1; i++){
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
        }
        tam++;
    }
}

int removerproduto(int pos){
    if(pos >=0 && pos < tam){
        if(pos == 0){ //inicio
            Produto* lixo = inicio;
            inicio = inicio->prox;
            free(lixo);
        }else if(pos == tam -1){ // FIM 
            Produto* aux = inicio;
            int i;
            for(i =0; i<tam -2; i++){
                aux = aux->prox;
            }
            Produto* lixo = fim;
            aux->prox = NULL;
            fim = aux;
            free(lixo);
        }else{
        	int i;
        	Produto* aux = inicio;
            for(i=0; i<pos-1;i++){
            	aux=aux->prox;
            }
            Produto* lixo = aux->prox;
            aux->prox= aux->prox->prox;
            free(lixo);
        }
    }    
}

void ConsultaEstoque(){
    Produto *aux = inicio;
    int i;
    printf("Imprimindo a lista :D\n");
    for(i=0; i< tam; i++){
        printf("*-------------------------------------------------------------*\n");
        printf("Nome: %s \n", aux->nome);
        printf("Valor Compra: %2.f \n", aux->valorcompra);
        printf("Valor de Venda: %2.f \n", aux->valorvenda);
        printf("Quantidade no Estoque: %d \n", aux->qntd);
        aux = aux->prox;
    }
    getchar();
}

int DiminuirEstoque(int id, int qntd){
    if(id >=0 && id < tam){
        if(id == 0){ //inicio
            Produto* venda = inicio;
            venda->qntd = venda->qntd - qntd;
            //return venda->nome;
        }
        else if(id == tam -1){ // FIM 
            Produto* aux = inicio;
            int i;
            for(i =0; i<tam -2; i++){
                aux = aux->prox;
            }
            Produto* venda = fim;
            venda->qntd = venda->qntd - qntd;
            //return venda->nome;
        }
        else{
        	int i;
        	Produto* aux = inicio;
            for(i=0; i<id;i++){
            	aux=aux->prox;
            }
            aux->qntd = aux->qntd - qntd;
            //return aux->nome;
        }
    }
}

void FazerVenda(){
    int f, id, outqntd;
    char teste;
    ConsultaEstoque();
    do{
        printf("\n*-------------------- Venda de Produto --------------------*\n");
        printf("* Produto ID:                                               *\n");
        scanf("%d", &id);
        printf("* Saida de produto (Quantidade):                            *\n");
        scanf("%d", &outqntd);
        char teste = DiminuirEstoque(id, outqntd);
        printf("Finalizar Venda digite 0:                                   *\n");
        scanf("%d", &f);
        printf("*-------------------------------------------------------------*\n");
    }while(f!=0);
}