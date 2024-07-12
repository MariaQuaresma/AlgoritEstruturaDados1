#include <stdio.h>

char pilha[50];
int topo = -1;

void push(char org) {
    if (topo == 49) {
        printf("A pilha esta cheia.\n");
    } 
	else {
        topo++;
        pilha[topo] = org;
    }
}

char pop() {
    if (topo == -1) {
        printf("A pilha esta vazia.\n");
        return '\0'; 
    } 
	else {
        char x = pilha[topo];
        topo--;
        return x;
    }
}

int main() {
    char nome[50];
    char y;
    
    printf("Digite ate 50 caracteres: ");
    gets(nome);
    for (int i=0; nome[i] != '\0'; i++) {
        push(nome[i]);
    }
    
    printf("\nCaracteres na ordem inversa:\n");
    while (topo != -1) {
        y = pop();
        printf("%c", y);
    }
    
    return 0;
}