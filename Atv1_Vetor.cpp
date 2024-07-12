#include <stdio.h>

typedef struct {
    int vetor[10];
    int tamanho;
} Vetor;

Vetor iniciaVetor() {
    Vetor vetor;
    vetor.tamanho=0;
    return vetor;
}

void exibirVetor(Vetor vetor) {
    printf("Vetor: ");
    for (int i=0; i<vetor.tamanho; i++) {
        printf("%d ", vetor.vetor[i]);
    }
    printf("\n");
}

Vetor removerElemento(Vetor vetor, int posicao) {
    if (posicao<0 || posicao>=vetor.tamanho) {
        printf("Posicao invalida!\n");
        return vetor;
    }
    for (int i=posicao; i<vetor.tamanho-1; i++) {
        vetor.vetor[i] = vetor.vetor[i+1];
    }
    vetor.tamanho--;
    return vetor;
}

Vetor inserirElemento(Vetor vetor, int elemento, int posicao) {
    if (posicao<0 || posicao>vetor.tamanho || vetor.tamanho>=10) {
        printf("Posicao invalida ou vetor cheio!\n");
        return vetor;
    }
    for (int i = vetor.tamanho; i>posicao; i--) {
        vetor.vetor[i] = vetor.vetor[i-1];
    }
    vetor.vetor[posicao] = elemento;
    vetor.tamanho++;
    return vetor;
}

int buscarPosicao(Vetor vetor, int valor) {
    for (int i=0; i<vetor.tamanho; i++) {
        if (vetor.vetor[i] == valor) {
            return i;
        }
    }
    return -1;
}

int main() {
    Vetor vetor=iniciaVetor();
    printf("---Digite os valores do vetor---\n");
    
    for (int i=0; i<10; i++) {
        printf("Digite o valor para a posicao %d: ", i);
        scanf("%d", &vetor.vetor[i]);
        vetor.tamanho++;
    }
    
    int opcao;
    do {
        printf("\n---Menu---\n");
        printf("1 - Exibir vetor\n");
        printf("2 - Remover elemento\n");
        printf("3 - Inserir elemento\n");
        printf("4 - Buscar posicao de um valor\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                exibirVetor(vetor);
                break;
            case 2: {
                int posicao;
                printf("Digite a posicao do elemento a ser removido: ");
                scanf("%d", &posicao);
                vetor = removerElemento(vetor, posicao);
                break;
            }
            case 3: {
                int elemento, posicao;
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &elemento);
                printf("Digite a posicao para insercao: ");
                scanf("%d", &posicao);
                vetor = inserirElemento(vetor, elemento, posicao);
                break;
            }
            case 4: {
                int valor;
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                int pos = buscarPosicao(vetor, valor);
                if (pos != -1) {
                    printf("O valor %d esta na posicao %d do vetor.\n", valor, pos);
                } else {
                    printf("O valor %d nao foi encontrado no vetor.\n", valor);
                }
                break;
            }
            case 0:
                printf("Saindo do programa!\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
    return 0;
}