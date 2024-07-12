#include <stdio.h>
#include <stdlib.h>
int vet[10];
int  qtdtrocas=0, qtdcomparacoes=0;
 
void VetorCreat(){
    int i;
    for (i=0; i<10; i++){
        vet[i] = rand()%100;
        printf("%d\n", vet[i]);
    }
}
 
void SelectionSort(){
    int menor;
    for (int i=0; i<9; i++) {
        for (int j=i+1; j<10; j++) {
            if(vet[j] < vet[i] && vet[j]) {
                menor = vet[j];
                vet[j] = vet[i];
                vet[i] = menor;
                qtdtrocas += 1;
            }
            qtdcomparacoes += 1;
        }
    }
}
 
void BubbleSort(){
    int trocou=0, menor;
    while (trocou == 0){
        trocou=1;
        for (int i=0; i<9; i++) {
            if (vet[i+1] < vet[i]){
                menor = vet[i+1];
                vet[i+1] = vet[i];
                vet[i] = menor;
                qtdtrocas += 1;
                trocou = 0;
            }
            qtdcomparacoes += 1;
        }
    }
}
 
 
void PrintSort(){
    printf("Vetor Ordenado: ");
    for (int i=0; i<10; i++){
        printf(" %d", vet[i]);
    }
}
 
int main() {
    int opcao;
    VetorCreat();
    printf("Escolha entre:\nSelectionSort - 1\nBubbleSort - 2\n");
    scanf("%d", &opcao);
    switch (opcao) {
        case 1:
            SelectionSort();
            printf("\nSelection Sort:\n");
            PrintSort();
            printf("\nComparacoes feitas: %d", qtdcomparacoes);
            printf("\nTrocas feitas: %d", qtdtrocas);
            break;
        case 2:
            BubbleSort();
            printf("\nBubble Sort:\n");
            PrintSort();
            printf("\nComparacoes feitas: %d", qtdcomparacoes);
            printf("\nTrocas feitas: %d", qtdtrocas);
            break;
        default:
            printf("Opção invalida!\n");
            return 1;
    }
}