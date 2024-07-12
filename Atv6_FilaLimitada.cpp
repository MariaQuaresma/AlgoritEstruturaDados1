#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

int fila[MAX];
int inicio = -1; 
int fim =-1;
int elemento;

bool filaVazia(){
    if(inicio ==-1 && fim==-1){
        return 1;
    }
    else{
        return 0;
    }
} 

void exibirFila(){
    printf("Fila atual: ");
    for (int i=0; i < MAX; i++){
        printf("%d | ", fila[i]);
    }
    printf("\n");
}

void enfileirar(){
    printf("Digite um número para ser enfileirado:");
    scanf("%d", &elemento);
    if (fim != 4) {
        if(inicio==-1) {
           inicio++; 
        }
        fim++;
        fila[fim] = elemento;
    }
    else{
        printf("A fila está cheia!");
    }

}

void desenfileirar(){
    if (filaVazia()) {
        printf("A fila está vazia!\n");
        return;
    }
    else{
    printf("Número desenfileirado: %d\n", fila[inicio]);
    fila[inicio] = 0;
    if (inicio == fim) {
        inicio = -1;
        fim = -1; }
    else {
        inicio++;
        }
    }
}

int main() {
    printf("APLICAÇÃO DE FILA LINEAR DE TAMANHO: %d\n", MAX);
    int selecao = -1;
    while (selecao != 0) {
        printf("\nSELECIONE A OPÇÃO DESEJADA:\n");
        printf("  0 - Sair\n");
        printf("  1 - Exibir fila\n");
        printf("  2 - Incluir elemento na fila\n");
        printf("  3 - Remover elemento da fila\n");
        scanf("%d", &selecao);
        switch (selecao) {
            case 1:
                exibirFila();
                break;

            case 2:
                enfileirar();
                break;

            case 3:
                desenfileirar();
                break;
            default: 
            printf("Opcao errada!");
        }
        printf("\n");
    }
    printf("Encerrando o programa...");
    return 0;
}