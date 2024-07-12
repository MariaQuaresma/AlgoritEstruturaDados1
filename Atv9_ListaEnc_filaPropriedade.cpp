//Crie um programa de atendimento de uma clínica que possua atendimento normal de atendimento preferencial utilizando lista encadeada. 
//No menu do programa, devem existir as opções: exibir fila, chegada normal, chegada preferencial e atendimento.
//Regras de negócio:
//- Cada pessoa que chega possui um código composto por letras e números, que deve ser inserido no programa.
//- Uma chegada normal sempre será inserida no final da fila, enquanto uma chegada preferencial sempre será inserida após o último código preferencial presente na fila.
//- O atendimento sempre é realizado pelo início da fila.
//- Ao realizar o atendimento, o programa deve exibir o código que está sendo atendido.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct no {
    char valor[6];
    struct no *prox;
    char pref;
} No;

void exibirLista(No *lista) {
    printf("Fila de Atendimento:\n");
    if (lista == NULL) {
        printf("Fila vazia\n");
        return;
    }
    while (lista != NULL) {
        printf("%s\n", lista->valor);
        lista = lista->prox;
    }
}

void inserirNoFim(No **lista, char val[6]) {
    No *novonormal = malloc(sizeof(No)); 
    if (novonormal) {
        strcpy(novonormal->valor, val);
        novonormal -> pref = 'n';
        novonormal->prox = NULL;
        if (*lista == NULL) {
            *lista = novonormal;
        } 
		else {
            No *aux = *lista;
            while (aux->prox != NULL)
                aux = aux->prox;
            aux->prox = novonormal;
        }
    } 
	else {
        printf("Erro ao alocar memória\n");
    }
}

void inserirPreferencial(No **lista, char val[6]) {
    No *novoPref = malloc(sizeof(No));
    if (novoPref) {
        strcpy(novoPref->valor, val);
        novoPref->prox = NULL;
        novoPref->pref = 'p'; 
        if (*lista == NULL) {
            *lista = novoPref;
        } 
		else if ((*lista)->pref == 'n') {
            novoPref->prox = *lista;
            *lista = novoPref;
        } 
		else {
            No *aux = *lista;
            while (aux->prox != NULL && aux->prox->pref == 'p') {
                aux = aux->prox;
            }
            novoPref->prox = aux->prox;
            aux->prox = novoPref;
        }
    } 
	else {
        printf("Erro ao alocar memória\n");
    }
}

void atenderPessoa(No **lista) {
    if (*lista) {
        No *aux = *lista;
        *lista = (*lista)->prox;
    } 
	else {
        printf("Fila vazia, nenhum atendimento pendente.\n");
    }
}

int main() {
    No *lista = NULL;   
    printf("APLICAÇÃO DE ATENDIMENTO DE FILA ENCADEADA\n");
    int selecao = -1;
    char pesNormal[6], pesPref[6];

    while (selecao != 0) {
        printf("\nSELECIONE A OPÇÃO DESEJADA:\n");
        printf("  0 - Sair\n");
        printf("  1 - Exibir fila de atendimento\n");
        printf("  2 - Incluir pessoa normal na fila\n");
        printf("  3 - Incluir pessoa preferencial na fila\n");
        printf("  4 - Atender próximo da fila\n");
        printf("Opção: ");
        scanf("%d", &selecao);

        switch (selecao) {
            case 1:
                exibirLista(lista);
                break;
            case 2:
                printf("Digite o código da pessoa normal a ser inserida (máx. 5 caracteres): ");
                scanf("%s", pesNormal);
                inserirNoFim(&lista, pesNormal);
                break;
            case 3:
                printf("Digite o código da pessoa preferencial a ser inserida (máx. 5 caracteres): ");
                scanf("%s", pesPref);
                inserirPreferencial(&lista, pesPref);
                break;
            case 4:
                atenderPessoa(&lista);
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }
   
    printf("Encerrando o programa...\n");
    return 0;
}