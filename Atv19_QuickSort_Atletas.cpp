#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ATLETAS 10
#define TAMANHO_NOME 50

struct atleta {
   char nome[TAMANHO_NOME];
   int prova;
};

struct atleta vet[NUM_ATLETAS];
int particao(struct atleta* vet, int inicio, int fim) {
   int ref = vet[inicio].prova;
   int i = inicio + 1;
   int j = fim;
   struct atleta temp;
   
   while (i <= j) {
       while (i <= fim && vet[i].prova <= ref) {
           i++;
       }
       while (j >= inicio && vet[j].prova > ref) {
           j--;
       }
       if (i < j) {
           temp = vet[i];
           vet[i] = vet[j];
           vet[j] = temp;
       }
   }
   temp = vet[inicio];
   vet[inicio] = vet[j];
   vet[j] = temp;
   return j;
}

void QuickSort(struct atleta* vet, int inicio, int fim) {
   if (inicio < fim) {
       int pivo = particao(vet, inicio, fim);
       QuickSort(vet, inicio, pivo - 1);
       QuickSort(vet, pivo + 1, fim);
   }
}

void PrintSort() {
   printf("Vetor ordenado dos atletas:\n");
   for (int i = 0; i < NUM_ATLETAS; i++) {
       printf("Nome: %s, Tempo de prova: %d\n", vet[i].nome, vet[i].prova);
   }
}

int main() {
   printf("Digite o nome e o tempo de prova dos atletas:\n");
   for (int i = 0; i < NUM_ATLETAS; i++) {
       printf("Atleta %d:\n", i+1);
       printf("Nome: ");
       scanf("%s", vet[i].nome);
       printf("Tempo de prova: ");
       scanf("%d", &vet[i].prova);
   }
   QuickSort(vet, 0, NUM_ATLETAS-1);
   PrintSort();
   return 0;
}