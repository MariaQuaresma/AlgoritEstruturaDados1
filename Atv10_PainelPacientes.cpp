//Crie um programa de atendimento de uma clínica que possua atendimento normal de atendimento preferencial utilizando lista encadeada. 
//No menu do programa, devem existir as opções: exibir fila, chegada normal, chegada preferencial e atendimento.
//Regras de negócio:
//- Cada pessoa que chega possui um código composto por letras e números, que deve ser inserido no programa.
//- Uma chegada normal sempre será inserida no final da fila, enquanto uma chegada preferencial sempre será inserida após o último código preferencial presente na fila.
//- O atendimento sempre é realizado pelo início da fila.
//- Ao realizar o atendimento, o programa deve exibir o código que está sendo atendido.
//adicionar:
//- Além do codigo, cada item da lista deve possuir tambem o nome do paciente.
//- Ao realizar o atendimento, deverá ser indicado o local de destino do paciente.
//- Ao mostrar o paciente chamado, também devem ser mostrados os 3 ultimos pacientes chamados anteriormente.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char codigo[6];
    char nome[50];
    char destino[50];
    char pref;
    struct no *prox;
    char pacientesAnteriores[3][50];
} No;

void exibirLista(No *lista) {
    printf("Fila de Atendimento:\n");
    if (lista == NULL) {
        printf("Fila vazia\n");
        return;
    }
    while (lista != NULL) {
        printf("%s - %s - %s\n", lista->codigo, lista->nome, lista->destino);
        lista = lista->prox;
    }
}

void inserirNoFim(No **lista, char cod[6], char nome[50], char destino[50]) {
    No *novoNo = malloc(sizeof(No)); 
    if (novoNo) {
        strcpy(novoNo->codigo, cod);
        strcpy(novoNo->nome, nome);
        strcpy(novoNo->destino, destino);
        novoNo->pref = 'n';
        novoNo->prox = NULL;
        
        if (*lista == NULL) {
            *lista = novoNo;
        } else {
            No *aux = *lista;
            while (aux->prox != NULL)
                aux = aux->prox;
            aux->prox = novoNo;
        }
    } 
	else {
        printf("Erro ao alocar memória\n");
    }
}

void inserirPreferencial(No **lista, char cod[6], char nome[50], char destino[50]) {
    No *novoPref = malloc(sizeof(No));
    if (novoPref) {
        strcpy(novoPref->codigo, cod);
        strcpy(novoPref->nome, nome);
        strcpy(novoPref->destino, destino);
        novoPref->pref = 'p';
        novoPref->prox = NULL;

        if (*lista == NULL || (*lista)->pref == 'n') {
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

void atenderPessoa(No **lista, char pacientesAnteriores[3][50]) {
    if (*lista) {
        No *aux = *lista;
        *lista = (*lista)->prox;
        printf("Atendendo (local de destino: %s): %s - %s\n", aux->destino, aux->codigo, aux->nome);
        printf("Pacientes anteriores:\n");
        for (int i = 0; i < 3; i++) {
            if (strlen(pacientesAnteriores[i]) > 0) {
                printf("  - %s\n", pacientesAnteriores[i]);
            }
        }
        for (int i = 2; i > 0; i--) {
            strcpy(pacientesAnteriores[i], pacientesAnteriores[i - 1]);
        }
        strcpy(pacientesAnteriores[0], aux->nome);   
    } 
	else {
        printf("Fila vazia, nenhum atendimento pendente.\n");
    }
}

int main() {
    No *lista = NULL;
    char pacientesAnteriores[3][50];
    printf("APLICAÇÃO DE ATENDIMENTO DE FILA ENCADEADA\n");
    int selecao = -1;
    char codigo[6], nome[50], destino[50];

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
                scanf("%s", codigo);
                printf("Digite o nome da pessoa normal: ");
                scanf("%s", nome);
                printf("Digite o destino da pessoa normal: ");
                scanf("%s", destino);
                inserirNoFim(&lista, codigo, nome, destino);
                break;
            case 3:
                printf("Digite o código da pessoa preferencial a ser inserida (máx. 5 caracteres): ");
                scanf("%s", codigo);
                printf("Digite o nome da pessoa preferencial: ");
                scanf("%s", nome);
                printf("Digite o destino da pessoa preferencial: ");
                scanf("%s", destino);
                inserirPreferencial(&lista, codigo, nome, destino);
                break;
            case 4:
                atenderPessoa(&lista, pacientesAnteriores);
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                
        }
    }
    printf("Encerrando o programa...\n");
    return 0;
}
