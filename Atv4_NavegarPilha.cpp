#include <stdio.h>
#include <string.h>

char sites[100][100];
int top = -1;
int indiceAtual = -1;
char retornoPop[100];

int pilhaVazia() {
    return (top == -1);
}

int pilhaCheia() {
    return (top == 100 - 1);
}

void push(char site[]) {
    if (pilhaCheia()) {
        printf("A pilha de voltar esta cheia. Descartando o site mais antigo.\n");
        for (int i=0; i<top; i++) {
            strcpy(sites[i], sites[i+1]);
        }
        top--;
    } 
	else {
        top++;
        strcpy(sites[top], site);
        indiceAtual = top;
    }
}

void pop() {
    if (!pilhaVazia()) {
        strcpy(retornoPop, sites[top--]);
    }
}

void avancar() {
    if (top < 100 - 1) {
        printf("Carregando URL: %s\n", sites[top+1]);
        top++;
    } 
	else {
        printf("Nao e possivel avancar mais.\n");
    }
}

void descartarMaisAntigo() {
    if (!pilhaVazia()) {
        for (int i=0; i<top; i++) {
            strcpy(sites[i], sites[i+1]);
        }
        top--;
    }
}

void esvaziarPilha() {
    while (!pilhaVazia()) {
        pop();
    }
}

int main() {
    char siteAtual[100];
    char opcao;
    printf("Bem-vindo ao Navegador de Internet!\n");
    do {
        printf("\nMenu:\n");
        printf("1. Navegar\n");
        if (!pilhaVazia()) {
            printf("2. Voltar\n");
        }
        printf("3. Avancar\n");
        printf("4. Remover item mais antigo da pilha de voltar\n");
        printf("5. Limpar pilha de avancar\n");
        printf("6. Fechar\n");
        printf("Escolha uma opcao: \n");
        scanf(" %c", &opcao);
        switch (opcao) {
            case '1':
                printf("Digite o endereco do site: \n");
                scanf("%s", siteAtual);
                printf("Carregando URL: %s\n", siteAtual);
                push(siteAtual);
                break;
            case '2':
                pop();
                strcpy(siteAtual, retornoPop);
                if (siteAtual != NULL) {
                    printf("Carregando URL: %s\n", siteAtual);
                } 
				else {
                    printf("Nao e possivel voltar mais.\n");
                }
                break;
            case '3':
                avancar();
                break;
            case '4':
                descartarMaisAntigo();
                printf("Item mais antigo removido da pilha de voltar.\n");
                break;
            case '5':
                esvaziarPilha();
                printf("Pilha de avancar limpa.\n");
                break;
            case '6':
                printf("Fechando o navegador.\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != '6');
    return 0;
}