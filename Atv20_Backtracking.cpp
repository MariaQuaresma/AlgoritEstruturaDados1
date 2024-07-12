#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 }; 
int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 }; 

int num; 
int numQuad; 
int** tab; 

void inicializa(int n) {
    int i, j;
    num = n;  
    numQuad = n * n; 
    tab = (int**)malloc(sizeof(int*) * n);
    for (i = 0; i < n; i++) { 
        tab[i] = (int*)malloc(sizeof(int) * n); 
        for (j = 0; j < n; j++) { 
            tab[i][j] = 0; 
        }
    }
}

void imprime() {
    int i, j;
    for (i = 0; i < num; i++) {
        for (j = 0; j < num; j++) {
            printf("%i\t", tab[i][j]);
        }
        printf("\n");
    }
}

bool aceitavel(int x, int y) {
    return (x>=0 && x<num && y>=0 && y<num && tab[x][y] == 0);
}

bool tenta(int i, int x, int y) { 
    int u, v; 
    int k = 0;
    bool feito = (i > numQuad); 
    while (!feito && k < 8) {
        u = x + dx[k]; 
        v = y + dy[k];  
        if (aceitavel(u, v)) {  
            tab[u][v] = i;
            feito = tenta(i + 1, u, v); 
            if (!feito) {  
                tab[u][v] = 0;
            }
        }
        k++;
    }
    return feito;
}

void liberaMemoria() {
    int i;
    for (i = 0; i < num; i++) {
        free(tab[i]);
    }
    free(tab);
}

void passeia(int x, int y) { 
    tab[x][y] = 1; 
    bool feito = tenta(2, x, y); 
    if (feito) {
        imprime();
    } 
	else {
        printf("Nao ha passeio possivel\n");
    }
}

int main() {
    inicializa(8);  
    passeia(0, 0);  
    liberaMemoria();
    return 0;
}
