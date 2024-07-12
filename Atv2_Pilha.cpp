#include <stdio.h>

int pilha[50];
int topo = -1;

void push(int org) {
    if (topo == 49) {
        printf("A pilha está cheia\n");
    } 
	else {
        topo++;
        pilha[topo] = org;
    }
}

int pop() {
    if (topo == -1) {
        printf("A pilha está vazia\n");
        return -1; 
    } 
	else {
        int x = pilha[topo];
        topo--;
        return x;
    }
}

int main() {
    int num[50];
    int y;

    printf("Digite até 50 números (0 para parar):\n"); 
    for (int i = 0; i < 50; i++) {
        scanf("%d", &num[i]);
        if (num[i] == 0) {
            break;
        }
        push(num[i]);
    }

    printf("\nNúmeros na ordem inversa:\n");
    while (topo != -1) {
        y = pop();
        if (y != -1) {
            printf("%d ", y);
        }
    }

    return 0;
}
