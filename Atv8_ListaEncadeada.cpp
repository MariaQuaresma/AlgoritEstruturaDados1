#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
    int aux;
}No;

void inserirNoInicio(No **lista, int val){ 
    No *novo = malloc(sizeof(No));
    if (novo){
        novo->valor = val;
        novo->prox = *lista;
        *lista = novo;
    }
    else{
        printf("Erro ao alocar memória");
    } 
}

void exibirLista(No **lista){ 
    No *aux = *lista;
    if(*lista == NULL){
        printf("A lista esta vazia!");
    }
    else{
        printf("\n");
        while (aux != NULL) {
            printf ("%d|", aux->valor);
            printf ("\n");
            aux = aux->prox;
        }
    }
}

void inserirNoFim(No **lista, int val){ 
    No *novo = malloc(sizeof(No)); 
    No *aux;
    if(novo){
        novo->valor = val;
        novo->prox = NULL;
        
        if(*lista == NULL){
            *lista = novo;
        }   
        else{ 
            aux = *lista;
            while(aux ->prox)
                aux = aux->prox;
            aux->prox = novo;
        }      
    }
}

void inserirNoMeio(No **lista, int val, int ant) {
    No *novo = malloc(sizeof(No));
    if (novo) {
        novo->valor = val;
        if (*lista == NULL) {
            novo->prox = NULL;
            *lista = novo;
        }
        else {
            No *aux = *lista;
            while (aux != NULL && aux->valor != ant) {
                aux = aux->prox;
            }
            if (aux == NULL) {
                printf("Elemento anterior não encontrado na lista!\n");
                return;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
        }
    }
    else {
        printf("Erro ao alocar memória\n");
    }
}

void removerElemento(No **lista, int val){
    No *removerElemento = NULL;
    No *ant = NULL;
    if(*lista){
        No *aux = *lista;
            while (aux->prox != NULL && aux->valor != val) {
                ant = aux;
                aux = aux->prox;
            }
            if(aux->valor == val){
                if(ant == NULL){
                    *lista = aux->prox;
                }
                else{
                    ant->prox = aux->prox;
                }
            }
            else{
                printf("O valor não existe");
            }
    }
}
    
int main() {
    No *lista = NULL;
    printf("APLICAÇÃO DE LISTA ENCADEADA");
    int selecao = -1;
    int valor1, valor2;
    while (selecao != 0) {
        printf("\nSELECIONE A OPÇÃO DESEJADA:\n");
        printf("  0 - Sair\n");
        printf("  1 - Exibir lista\n");
        printf("  2 - Incluir elemento no início da lista\n");
        printf("  3 - Incluir elemento no final da lista\n");
        printf("  4 - Incluir elemento no meio da lista\n");
        printf("  5 - Remover elemento da lista\n");
        scanf("%d", &selecao);
        switch (selecao) {
            case 1:
                exibirLista(&lista);
                break;
            case 2:
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &valor1);
                inserirNoInicio(&lista, valor1);
                break;
            case 3:
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &valor1);
                inserirNoFim(&lista, valor1);
                break;
            case 4:
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &valor1);
                printf("Após qual elemento ele será inserido? ");
                scanf("%d", &valor2);
                inserirNoMeio(&lista, valor1, valor2 );
                break;
            case 5:
                printf("Digite o elemento a ser removido: ");
                scanf("%d", &valor1);
                removerElemento(&lista, valor1 );
                break;
        }
        printf("\n");
    }
    printf("Encerrando o programa...");
    return 0;
}