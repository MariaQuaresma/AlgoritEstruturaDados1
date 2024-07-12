//Selection Sort:
//Este algoritmo divide o vetor em duas partes: uma parte ordenada e outra desordenada.
//A cada iteração, ele encontra o menor elemento da parte não ordenada e o troca com o primeiro elemento não ordenado. Assim, gradualmente, o vetor é ordenado.

//Bubble Sort:
//O Bubble Sort compara repetidamente cada par de elementos adjacentes e os troca se estiverem na ordem errada. 
//Esse processo é repetido até que nenhum swap seja necessário, o que significa que o vetor está ordenado.

//Insertion Sort:
//O Insertion Sort constrói a lista ordenada um item de cada vez, movendo os elementos não ordenados para a posição correta dentro da parte ordenada do vetor.

//Counting Sort:
//Diferentemente dos anteriores, o Counting Sort é um algoritmo de ordenação não-comparativo que funciona para números inteiros em um intervalo limitado. 
//Ele conta o número de ocorrências de cada elemento e usa essa informação para colocar cada elemento no lugar correto. 

#include <stdio.h>
#include <stdlib.h>

int vet[10];
int  qtdtrocas=0, qtdcomparacoes=0;

void VetorCreat(){
    int cont=0, i;
    for (i=0; i<10; i++){
        vet[i] = rand()%100;
        printf("%d\n", vet[i]);
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
        atual = vet[i];
        j=i;
        while (j>0 && vet[j-1]> atual) {
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
        cont[vet[i]] = cont[vet[i]]+1;   
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

void PrintSort(){
    printf("Vetor Ordenado: ");
    for (int i=0; i<10; i++){
        printf(" %d", vet[i]);
    }
}
int main() {
    int opcao;
    VetorCreat();
   printf("Escolha entre:\nSelectionSort - 1\nBubbleSort - 2\nInsertion Sort - 3\nCounting Sort - 4\n");
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
        default:
            printf("Opção inválida!\n");
            return 1;
    }
}