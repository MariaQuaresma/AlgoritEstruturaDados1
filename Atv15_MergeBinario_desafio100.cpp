//desafio: Altere o código do exercício anterior para permitir até 100 registros de compras e até 1000 produtos em cada compra. 

#include <stdio.h>
#include <stdlib.h>

#define MAX_COMPRAS 100
#define MAX_PRODUTOS 1000

struct produto {
    int codigo_barras;
    int quantidade;
};

struct produto prod[MAX_COMPRAS][MAX_PRODUTOS];
int compr = 0;

void SelectionSort(int cop, int tamanho) {
    struct produto menor;
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (prod[cop][j].codigo_barras < prod[cop][i].codigo_barras) {
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

void registrarCompra() {
    if (compr >= MAX_COMPRAS) {
        printf("Você ultrapassou o número máximo de compras.\n");
        return;
    }
    printf("Registre sua compra: \n");
    int tamanho;
    printf("Insira o número de produtos na compra: ");
    scanf("%d", &tamanho);
    if (tamanho > MAX_PRODUTOS) {
        printf("Número de produtos excede o máximo permitido.\n");
        return;
    }
    for (int i = 0; i < tamanho; i++) {
        printf("Insira o código de barras e a quantidade do produto %d (separados por espaço):\n", i+1);
        scanf("%d %d", &prod[compr][i].codigo_barras, &prod[compr][i].quantidade);
    }
    SelectionSort(compr, tamanho);
    compr++;
}

void exibirCompra(int idx) {
    printf("Exibindo compra %d:\n", idx+1);
    for (int i = 0; i < MAX_PRODUTOS; i++) {
        if (prod[idx][i].codigo_barras == 0) {
            break;
        }
        printf("Código de barras: %d, Quantidade: %d\n", prod[idx][i].codigo_barras, prod[idx][i].quantidade);
    }
}

void localizarProduto(int codigo_barras) {
    printf("Procurando pelo código de barras %d:\n", codigo_barras);
    for (int i = 0; i < compr; i++) {
        for (int j = 0; j < MAX_PRODUTOS; j++) {
            if (prod[i][j].codigo_barras == codigo_barras) {
                printf("Produto encontrado na compra %d com quantidade %d.\n", i+1, prod[i][j].quantidade);
            }
        }
    }
}

void sumarizarVendas() {
    struct produto prod2[MAX_COMPRAS * MAX_PRODUTOS];
    int k = 0;
    for (int i = 0; i < compr; i++) {
        for (int j = 0; j < MAX_PRODUTOS; j++) {
            if (prod[i][j].codigo_barras == 0) {
                break;
            }
            prod2[k] = prod[i][j];
            k++;
        }
    }
    printf("Resumo de vendas:\n");
    for (int i = 0; i < k; i++) {
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
                for (int i = 0; i < compr; i++) {
                    exibirCompra(i);
                }
                break;
            case 3:
                printf("Insira o código de barras do produto: ");
                scanf("%d", &codigo_barras);
                localizarProduto(codigo_barras);
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


#include <stdio.h>
 
#define TAMANHO 10
 
void imprimir(int vet[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}
 
void merge_sort(int vet[], int inicio, int fim) {
    int meio, i, j, k, aux[TAMANHO];
    if (inicio < fim) {
        meio = (inicio + fim) / 2;
        merge_sort(vet, inicio, meio);
        merge_sort(vet, meio + 1, fim);
        i = inicio;
        j = meio + 1;
        k = inicio;
        while (i <= meio && j <= fim) {
            if (vet[i] < vet[j]) {
                aux[k] = vet[i];
                i++;
            } else {
                aux[k] = vet[j];
                j++;
            }
            k++;
        }
        while (i <= meio) {
            aux[k] = vet[i];
            i++;
            k++;
        }
        while (j <= fim) {
            aux[k] = vet[j];
            j++;
            k++;
        }
        for (i = inicio; i <= fim; i++) {
            vet[i] = aux[i];
        }
    }
}
 
void inicio() {
    int vet[TAMANHO] = {5, 7, 8, 6, 5, 9, 1, 3, 2, 7};
    int tamanho = TAMANHO;
    printf("Vetor nao ordenado: ");
    imprimir(vet, tamanho);
    merge_sort(vet, 0, tamanho - 1);
    printf("Vetor ordenado: ");
    imprimir(vet, tamanho);
}
 
int main() {
    inicio();
    return 0;
}