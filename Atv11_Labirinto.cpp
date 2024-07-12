#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 5

typedef struct no{
  int i;
  int j;
  struct no *prox;
  struct no *ant;
  char novo;
}No;

char labirinto[MAX][MAX];

void montarLabirinto(){
    char camada[MAX];
    int i,j;
    printf("--------------------------------------\n");
    printf("  MONTAGEM DO LABIRINTO EM %d CAMADAS\n", MAX);
    printf("(utilize 0 para livre e X para parede)\n");
    printf("--------------------------------------\n\n");
    for (i=0; i<MAX; i++) {
        printf("Camada %d: ", i+1);
        scanf("%s", &camada);
        for (j=0; j<MAX; j++){
            labirinto[i][j] = toupper(camada[j]);
        }
    }
    printf("\n\n----------\n");
    printf("LABIRINTO:\n");
    printf("----------\n\n");
    printf("   j = ");
    for (j=0; j<MAX; j++) {
        printf("%d ",j);
    }
    printf("\n");
    for (i=0; i<MAX; i++) {
        if (i==0) {
            printf("i = %d ",i);
        } 
		else {
            printf("    %d ",i);
        }
        printf("|");
        for (j=0; j<MAX; j++){
            printf("%c|",labirinto[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void imprimirCaminho(No **lista){
    No *temp = *lista;
    int i = 1;
    if (temp){
        printf("\n\nCaminho localizado:\n");
    } 
	else {
        printf("\n\nNão foi possível identificar nenhum caminho para o final :(");
    }
    while (temp != NULL){
        printf("Passo %d: (%d,%d)\n", i, temp->i, temp->j);
        temp = temp->prox;
        i++;
    }
}

void inserirCaminho(No **lista, int i, int j){
    No *novo = malloc(sizeof(No));
    No *aux;
    if(novo){
        novo->i = i;
        novo->j = j;
        novo->prox = NULL;
        
        if(*lista==NULL){
            novo->ant = NULL;
            *lista=novo;
        }
        else {
            aux = *lista;
            while(aux->prox) {
                aux = aux->prox;
            }
            novo->ant = aux;
            aux->prox = novo;
        }     
    }
}

void removerElemento(No **lista){
    if(*lista){
        No *aux = *lista;
            while (aux->prox != NULL) {
                aux = aux->prox;
            }
            aux = aux->ant;
            aux->prox=NULL;        
        }
    }

int main() {
    int i=0, j=0, win = 0;
    No *novo = malloc(sizeof(No));
    No *aux;
    montarLabirinto();
    printf("Calculando caminho... por favor aguarde...\n\n");
    
    No *lista = NULL;

    while (win==0){
        printf("%d, %d\n", i, j);
        labirinto[i][j] = '1';
        inserirCaminho(&lista, i, j);
        if (j < MAX-1 && labirinto[i][j+1] == '0'){
            j++;
        } 
		else if (i < MAX-1 && labirinto[i+1][j] == '0'){
            i++;
        } 
		else if (j > 0 && labirinto[i][j-1] == '0'){
            j--;
        } 
		else if (i > 0 && labirinto[i-1][j] == '0'){
            i--;
        }
        else{
            removerElemento(&lista);
            novo->ant = aux;
            aux->prox = novo;
        }
        if (i==MAX-1 && j==MAX-1){
            win=1;
            inserirCaminho(&lista, i, j);
        }
    }
    imprimirCaminho(&lista);
}