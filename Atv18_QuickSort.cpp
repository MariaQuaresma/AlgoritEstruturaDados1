#include <stdio.h>
#include <stdlib.h>
 
int vet[10];
int  qtdtrocas=0, qtdcomparacoes=0;
 
void VetorCreat(){ // Sortear números aleatórios
    int cont=0, i;
    printf("Números aleatórios: ");
    for (i=0; i<10; i++){
        vet[i] = rand()%100;
        printf(" %d |", vet[i]);
    }
}
 
void SelectionSort(){
    int menor;
    for (int i=0; i<9; i++) {
        for (int j=i+1; j<10; j++) {
            if(vet[j] < vet[i] && vet[j] ) {
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
void InsertionSort(){
    int atual, i, j;
    for (i=0; i<=9; i++) {
        atual= vet[i];
        j=i;
        while (j > 0 && vet[j-1]> atual) {
                vet[j]= vet[j-1];
                j=j-1;
                qtdtrocas += 1;
            }
            vet[j]=atual;
            qtdcomparacoes += 1;
        }
    }
 

void CountingSort(){
    int i;
    int cont[100], aux=0;
    for(i=0; i<100; i++){
        cont[i]=0;
    }
    for(i=0; i<10; i++){
        cont[vet[i]]=cont[vet[i]]+1;
    }
    for(i=0; i<100; i++){
        if(cont[i]>0){
            vet[aux]=i;
            cont[i]--;
            aux++;
            i--;
            qtdtrocas++;
        }
         qtdcomparacoes += 1;
    }
}
 
void MergeSort(int* vet, int inicio, int fim) {    
    int meio, i, j, k, aux[fim+1];                
    if (inicio < fim) {                            
        meio = (inicio + fim) / 2;              
        MergeSort(vet, inicio, meio);           
        MergeSort(vet, meio + 1, fim);           
        i = inicio;                            
        j = meio + 1;
        k = inicio;
        while (i <= meio && j <= fim) {
            qtdcomparacoes++;
            qtdtrocas++;
            if (vet[i] < vet[j]) {
                aux[k] = vet[i];
                i++;
            } 
			else {
                aux[k] = vet[j];
                j++;
            }
            k++;  
        }
        while (i <= meio) {
            aux[k] = vet[i];   
            i++;
            k++;
            qtdtrocas++;
        }
        while (j <= fim) {
            aux[k] = vet[j]; 
            j++;
            k++;
            qtdtrocas++;
        }
        for (i = inicio; i <= fim; i++) {
            vet[i] = aux[i];  
            qtdcomparacoes++;
        }
    }
}

int particao(int* vet, int inicio, int fim) {
    int ref, i, j, temp; 
    ref = vet[inicio];      // ref (referência/pivô),
    i = inicio + 1;        // i (índice de varredura da esquerda para a direita)
    j = fim;              // j (índice de varredura da direita para a esquerda)
    while (i <= j) {
        while (i <= fim && vet[i] <= ref) {
            i++;
            qtdcomparacoes++;
        }
        while (j >= inicio && vet[j] > ref) {
            j--;
            qtdcomparacoes++;
        }
        if (i < j) {
            temp = vet[i];
            vet[i] = vet[j];
            vet[j] = temp;
            qtdtrocas++;
        }
    }
    vet[inicio] = vet[j];
    vet[j] = ref; //Coloca o pivô na posição correta: troca o valor de vet[inicio] com vet[j]. 
    qtdtrocas++;
    return j;
}

void QuickSort(int* vet, int inicio, int fim) {
    if (inicio < fim) {
        int pivo = particao(vet, inicio, fim);
        QuickSort(vet, inicio, pivo - 1); //a parte antes do pivô (inicio até pivo - 1)
        QuickSort(vet, pivo + 1, fim);  //a parte após o pivô (pivo + 1 até fim).
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
   printf("\n\nEscolha o método utilizado para ordenar o vetor:\n1 - SelectionSort\n2 - BubbleSort\n3 - Insertion Sort\n4 - Counting Sort\n5 - Merge Sort\n6 - Quick Sort\n");
    scanf("%d", &opcao);
    switch (opcao) {
        case 1:
            SelectionSort();
            printf("\nSelection Sort:\n");
            PrintSort();
            printf("\nComparações feitas: %d", qtdcomparacoes);
            printf("\nTrocas feitas: %d", qtdtrocas);
            break;
        case 2:
            BubbleSort();
            printf("\nBubble Sort:\n");
            PrintSort();
            printf("\nComparações feitas: %d", qtdcomparacoes);
            printf("\nTrocas feitas: %d", qtdtrocas);
            break;
        case 3:
            InsertionSort();
            printf("\nInsertion Sort:\n");
            PrintSort();
            printf("\nComparações feitas: %d", qtdcomparacoes);
            printf("\nTrocas feitas: %d", qtdtrocas);
            break;
        case 4:
            CountingSort();
            printf("\nCounting Sort:\n");
            PrintSort();
            printf("\nComparações feitas: %d", qtdcomparacoes);
            printf("\nTrocas feitas: %d", qtdtrocas);
            break;
        case 5:
            MergeSort(vet, 0, 9);
            printf("\nMerge Sort:\n");
            PrintSort();
            printf("\nComparações feitas: %d", qtdcomparacoes);
            printf("\nTrocas feitas: %d\n", qtdtrocas);
            break;
        case 6:
            QuickSort(vet, 0, 9);
            printf("\nQuickSort:\n");
            PrintSort();
            printf("\nComparações feitas: %d", qtdcomparacoes);
            printf("\nTrocas feitas: %d\n", qtdtrocas);
            break;
            printf("Opção inválida!\n");
            return 1;
    }
}