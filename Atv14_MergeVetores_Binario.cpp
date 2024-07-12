//Crie um programa em C para registro de compras de um mercado, que possua as seguintes funções:
//- Registrar compra: esta função deve permitir o registro de um número indefinido de produtos, cada um com seu código de barras e quantidade.
// Deve ser possível registrar até 2 compras, cada uma com os seus produtos (no máximo 10 pra simplificar).
// Utilize um vetor para guardar os produtos de cada compra. Porém, antes de armazenar cada compra (após registrar todos os produtos),
// ordene o vetor, de modo que ele seja armazenado já ordenado. Utilize qualquer algoritmo de ordenação já estudado para isso.
//- Exibir compras: esta função deve exibir cada compra separadamente. 
//- Localizar produto vendido: esta função deve localizar um código de barras em cada compra registrada, mostrando todas as compras que possuem esse produto, e a sua quantidade vendida.
//- Sumarizar vendas: esta função deve realizar a fusão de todos os vetores de compras armazenados.
 
#include <stdio.h>
#include <stdlib.h>
 
  struct produto{
    int  codigo_barras;
    int quantidade;
    };
    
    struct produto prod[2][10];
    int compr=0;
    int soma=0;
 
void exibirCompra(){
         printf("Exibir compra:\n");
         for(int i=0; i<2; i++){
             for(int j=0; j<10; j++){
              if (prod[i][j].codigo_barras == 0) {
               break;
           }
           printf("Código de barras: %d, Quantidade: %d\n", prod[i][j].codigo_barras, prod[i][j].quantidade);
        }
    }
}

void SelectionSort(int cop){
    struct produto menor;
    for (int i=0; i<9; i++) {
        for (int j=i+1; j<10; j++) {
            if(prod[cop][j].codigo_barras < prod[cop][i].codigo_barras) {
                 menor.codigo_barras = prod[cop][j].codigo_barras;
                 prod[cop][j].codigo_barras = prod[cop][i].codigo_barras;
                 prod[cop][i].codigo_barras = menor.codigo_barras;
                 
                 menor.quantidade = prod[cop][j].quantidade;
                 prod[cop][j].quantidade = prod[cop][i].quantidade;
                 prod[cop][i].quantidade = menor.quantidade;
            }
        }
    }
}
 
void registrarCompra(){
    if(compr>1){
        printf("Você ultrapassou o número de compras");
        return;
    }
    else{
        printf("Registre sua compra: ");
    for (int i = 0; i<10; i++) {
        printf("Insira o nome do produtos (código de barras e quantidade) separados por espaço:\n");
        scanf("%d %d", &prod[compr][i].codigo_barras, &prod[compr][i].quantidade);
    }
    SelectionSort(compr);
    compr++;
  }
}

void localizarProduto(int codigo_barras, int cop){
    int meio = 0;
    int achou = 0;
    int inicio = 0, fim = 9;
    
    while(inicio<=fim && achou==0){
         meio = (inicio+fim)/2;
            if(prod[cop][meio].codigo_barras == codigo_barras){
                achou=1;
                }
                else{
                    if(prod[cop][meio].codigo_barras > codigo_barras){
                        fim = meio - 1;
                    }
                    else{
                        inicio = meio + 1;
                    }
                }
             }
             if(achou == 1){
                 printf("achou o codigo de barras na compra %d e a quantidade %d\n", cop, prod[cop][meio].quantidade);
            }
}

void sumarizarVendas() {
    int i = 0, j = 0, k = 0;
    struct produto prod2[20];
    
    while (k < 20) {
        if (i >= 10) {
            prod2[k].codigo_barras = prod[1][j].codigo_barras;
            prod2[k].quantidade = prod[1][j].quantidade;
            j++;
        } 
		else if (j >= 10) {
            prod2[k].codigo_barras = prod[0][i].codigo_barras;
            prod2[k].quantidade = prod[0][i].quantidade;
            i++;
        } 
		else {
            if (prod[0][i].codigo_barras < prod[1][j].codigo_barras) {
                prod2[k].codigo_barras = prod[0][i].codigo_barras;
                prod2[k].quantidade = prod[0][i].quantidade;
                i++;
            } 
			else {
                prod2[k].codigo_barras = prod[1][j].codigo_barras;
                prod2[k].quantidade = prod[1][j].quantidade;
                j++;
            }
        }
        k++;
    }
    printf("Resumo de vendas:\n");
    for (i = 0; i < 20; i++) {
        printf("Código de barras: %d, Quantidade: %d\n", prod2[i].codigo_barras, prod2[i].quantidade);
    }
}

int main() {
   int opcao, codigo_barras;
   do {
       printf("\nEscolha uma opção:\n");
       printf("1. Registrar compra\n");
       printf("2. Exibir compras\n");
       printf("3. Localizar produto vendido\n");
       printf("4. Sumarizar vendas\n");
       printf("0. Sair\n");
       scanf("%d", &opcao);
       switch (opcao) {
           case 1:
               registrarCompra();
               break;
           case 2:
                exibirCompra();
               break;
           case 3:
               printf("Insira o código de barras do produto: ");
               scanf("%d", &codigo_barras);
               localizarProduto(codigo_barras, 0);
               localizarProduto(codigo_barras, 1);
               break;
            case 4:
               sumarizarVendas();
               break;
           case 0:
               printf("Encerrando o programa.\n");
               break;
           default:
               printf("Opção inválida. Tente novamente.\n");
       }
   } while (opcao != 0);
   return 0;
}