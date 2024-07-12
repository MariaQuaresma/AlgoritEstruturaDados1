#include <stdio.h>
#include <string.h>

int top = -1;
char retornoPop;
char formula[50];
char vet[50]; 

int pilhaVazia() {
    return (top == -1);
}

void empilhar(char elemento) {
    if (top < 50) {
        top++;
        vet[top] = elemento;   
    }
}

void desempilhar() {
    if (!pilhaVazia()) {
        retornoPop = vet[top--];
    }
}

int main() {
    printf("Informe uma formula matematica:");
    scanf("%s", formula);

    for (int i=0; i<50; i++) {
        if (formula[i] == ')') {
            if (pilhaVazia()) {
                printf("Formula mal formulada");
                return 0;
            }
            desempilhar();
            if (retornoPop != '(') {
                printf("Formula mal formulada");
                return 0;
            }
        } 
        else if (formula[i] == ']') {
            if (pilhaVazia()) {
                printf("Formula mal formulada");
                return 0;
            }
            desempilhar();
            if (retornoPop != '[') {
                printf("Formula mal formulada");
                return 0;
            }
        }
        else {
            if (formula[i] == '(' || formula[i] == '[') {
                empilhar(formula[i]);
            }
        }
    }
    if (pilhaVazia()) {
        printf("Formula bem formulada");
    } 
    else {
        printf("Formula mal formulada");
    }

    getchar();
    return 0;
}