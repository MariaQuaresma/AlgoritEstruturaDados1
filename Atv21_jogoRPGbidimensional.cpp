//Crie um programa em C onde, dado o mapa de um jogo de RPG bidimensional abaixo, o programa calcule o melhor caminho para o destino.
//1) O mapa é transformado em uma matriz, onde:
//-- O caractere '0' significa casa livre.
//-- O caractere 'X' significa casa bloqueada.
//-- O caractere '1' é o objetivo de chegada.
//-- Os caracteres '2', '3' e '4' significam casa bloqueada também (nesta parte da atividade).
//2) O código base já contém:
//-- Declaração, preenchimento e impressão da matriz.
//-- Declaração do struct Casa (nó de lista encadeada representando uma posição da matriz) e método para criação de uma nova Casa.
//-- Declaração do struct Caminhos (nó de lista encadeada representando um início de uma lista encadeada de Casa) e método para criação de um novo Caminhos.
//-- Método Main imprimindo a matriz e obtendo a posição inicial desejada.
//3) O algoritmo deve iniciar na posição escolhida e calcular o melhor caminho até o castelo (casa marcada com o caractere '1'). Quando for identificado o melhor caminho, deve ser mostrado o mapa com o caminho marcado com caracteres '*'.
//4) Ao procurar um caminho, crie uma lista encadeada de nós do tipo "Casa", onde cada casa contém um passo do caminho.
//5) Ao encontrar um caminho possível, registre esse caminho (a lista encadeada) em um nó do tipo "Caminho". Essa lista encadeada funciona como um array de listas encadeadas do tipo "Casa".

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100;

char mapa[12][15];
void montarMapa() {
    mapa[0][0] = '0';
    mapa[0][1] = '0';
    mapa[0][2] = '0';
    mapa[0][3] = '0';
    mapa[0][4] = '0';
    mapa[0][5] = '0';
    mapa[0][6] = 'X';
    mapa[0][7] = 'X';
    mapa[0][8] = 'X';
    mapa[0][9] = 'X';
    mapa[0][10] = 'X';
    mapa[0][11] = '0';
    mapa[0][12] = 'X';
    mapa[0][13] = 'X';
    mapa[0][14] = 'X';
    mapa[1][0] = '0';
    mapa[1][1] = '0';
    mapa[1][2] = 'X';
    mapa[1][3] = 'X';
    mapa[1][4] = 'X';
    mapa[1][5] = 'X';
    mapa[1][6] = 'X';
    mapa[1][7] = 'X';
    mapa[1][8] = '0';
    mapa[1][9] = 'X';
    mapa[1][10] = 'X';
    mapa[1][11] = '0';
    mapa[1][12] = 'X';
    mapa[1][13] = 'X';
    mapa[1][14] = 'X';
    mapa[2][0] = '0';
    mapa[2][1] = '0';
    mapa[2][2] = 'X';
    mapa[2][3] = 'X';
    mapa[2][4] = 'X';
    mapa[2][5] = 'X';
    mapa[2][6] = 'X';
    mapa[2][7] = '0';
    mapa[2][8] = 'X';
    mapa[2][9] = 'X';
    mapa[2][10] = 'X';
    mapa[2][11] = '0';
    mapa[2][12] = 'X';
    mapa[2][13] = '0';
    mapa[2][14] = 'X';
    mapa[3][0] = 'X';
    mapa[3][1] = 'X';
    mapa[3][2] = 'X';
    mapa[3][3] = 'X';
    mapa[3][4] = 'X';
    mapa[3][5] = '0';
    mapa[3][6] = '0';
    mapa[3][7] = 'X';
    mapa[3][8] = 'X';
    mapa[3][9] = 'X';
    mapa[3][0] = '0';
    mapa[3][1] = '0';
    mapa[3][2] = '0';
    mapa[3][3] = '0';
    mapa[3][4] = '0';
    mapa[3][5] = '0';
    mapa[3][6] = '0';
    mapa[3][7] = '0';
    mapa[3][8] = '0';
    mapa[3][9] = '0';
    mapa[3][10] = '0';
    mapa[3][11] = '0';
    mapa[3][12] = '0';
    mapa[3][13] = '0';
    mapa[3][14] = '0';
    mapa[4][0] = 'X';
    mapa[4][1] = 'X';
    mapa[4][2] = 'X';
    mapa[4][3] = 'X';
    mapa[4][4] = 'X';
    mapa[4][5] = '2';
    mapa[4][6] = 'X';
    mapa[4][7] = 'X';
    mapa[4][8] = 'X';
    mapa[4][9] = '0';
    mapa[4][10] = '0';
    mapa[4][11] = '0';
    mapa[4][12] = '0';
    mapa[4][13] = '0';
    mapa[4][14] = 'X';
    mapa[5][0] = 'X';
    mapa[5][1] = 'X';
    mapa[5][2] = '0';
    mapa[5][3] = '0';
    mapa[5][4] = '0';
    mapa[5][5] = '0';
    mapa[5][6] = '0';
    mapa[5][7] = '0';
    mapa[5][8] = '0';
    mapa[5][9] = '0';
    mapa[5][10] = '0';
    mapa[5][11] = 'X';
    mapa[5][12] = '0';
    mapa[5][13] = 'X';
    mapa[5][14] = '0';
    mapa[6][0] = 'X';
    mapa[6][1] = 'X';
    mapa[6][2] = '0';
    mapa[6][3] = '0';
    mapa[6][4] = '0';
    mapa[6][5] = '0';
    mapa[6][6] = 'X';
    mapa[6][7] = 'X';
    mapa[6][8] = '0';
    mapa[6][9] = 'X';
    mapa[6][10] = 'X';
    mapa[6][11] = 'X';
    mapa[6][12] = '0';
    mapa[6][13] = '0';
    mapa[6][14] = 'X';
    mapa[7][0] = 'X';
    mapa[7][1] = '0';
    mapa[7][2] = '0';
    mapa[7][3] = '0';
    mapa[7][4] = '0';
    mapa[7][5] = '0';
    mapa[7][6] = '4';
    mapa[7][7] = 'X';
    mapa[7][8] = '0';
    mapa[7][9] = 'X';
    mapa[7][10] = '1';
    mapa[7][11] = 'X';
    mapa[7][12] = '0';
    mapa[7][13] = '0';
    mapa[7][14] = 'X';
    mapa[8][0] = '3';
    mapa[8][1] = '0';
    mapa[8][2] = 'X';
    mapa[8][3] = 'X';
    mapa[8][4] = 'X';
    mapa[8][5] = 'X';
    mapa[8][6] = 'X';
    mapa[8][7] = '0';
    mapa[8][8] = '0';
    mapa[8][9] = '0';
    mapa[8][10] = '0';
    mapa[8][11] = '0';
    mapa[8][12] = '0';
    mapa[8][13] = 'X';
    mapa[8][14] = 'X';
    mapa[9][0] = 'X';
    mapa[9][1] = '0';
    mapa[9][2] = '0';
    mapa[9][3] = 'X';
    mapa[9][4] = 'X';
    mapa[9][5] = 'X';
    mapa[9][6] = 'X';
    mapa[9][7] = 'X';
    mapa[9][8] = 'X';
    mapa[9][9] = '0';
    mapa[9][10] = '0';
    mapa[9][11] = '0';
    mapa[9][12] = 'X';
    mapa[9][13] = 'X';
    mapa[9][14] = 'X';
    mapa[10][0] = 'X';
    mapa[10][1] = 'X';
    mapa[10][2] = 'X';
    mapa[10][3] = 'X';
    mapa[10][4] = 'X';
    mapa[10][5] = 'X';
    mapa[10][6] = 'X';
    mapa[10][7] = 'X';
    mapa[10][8] = '0';
    mapa[10][9] = '0';
    mapa[10][10] = 'X';
    mapa[10][11] = '0';
    mapa[10][12] = '0';
    mapa[10][13] = '0';
    mapa[10][14] = '0';
    mapa[11][0] = 'X';
    mapa[11][1] = 'X';
    mapa[11][2] = 'X';
    mapa[11][3] = 'X';
    mapa[11][4] = 'X';
    mapa[11][5] = '0';
    mapa[11][6] = '0';
    mapa[11][7] = '0';
    mapa[11][8] = '0';
    mapa[11][9] = '0';
    mapa[11][10] = '0';
    mapa[11][11] = '0';
    mapa[11][12] = '0';
    mapa[11][13] = '0';
    mapa[11][14] = '0';
}   

typedef struct Casa {
    int x, y;
    struct Casa* proximo;
    struct Casa* anterior;
} Casa;

typedef struct Caminhos {
    Casa* inicio;
    struct Caminhos* proximo;
} Caminhos;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void imprimirMapa() {
    printf("\n\n  0   1   2   3   4   5   6   7   8   9   10  11  12  13  14\n\n");
    for (int i = 0; i < 12; i++) {
        printf("| ");
        for (int j = 0; j < 15; j++) {
            printf("%c | ", mapa[i][j]);
          if(j == 14){
          	printf("  %d", i);
		  }
        }
        printf("\n");
    }
    printf("\n\n");
}

Casa* novaCasa(int x, int y) {
    Casa* novo = (Casa*)malloc(sizeof(Casa));
    if (novo != NULL) {
        novo->x = x;
        novo->y = y;
        novo->proximo = NULL;
        novo->anterior = NULL;
    }
    return novo;
}

Caminhos* novoCaminho(Casa* casa_inicial) {
    Caminhos* novo = (Caminhos*)malloc(sizeof(Caminhos));
    if (novo != NULL) {
        novo->inicio = casa_inicial;
        novo->proximo = NULL;
    }
    return novo;
}

void registrar_movimento(Casa** movimentos, Casa* casa_atual) {
    Casa* aux = *movimentos;
    if (aux == NULL){
        *movimentos = casa_atual;
    } 
	else {
        while (aux -> proximo != NULL) { 
           aux = aux -> proximo;
        }
        aux -> proximo = casa_atual;
        casa_atual->anterior = aux;
        casa_atual->proximo = NULL;
    }
}

void registrar_sucesso(Caminhos** sucessos, Casa* movimentos) {
    Caminhos* novo_sucesso = novoCaminho(movimentos);
    novo_sucesso->proximo = *sucessos;
    *sucessos = novo_sucesso;
}

Casa* apagar_movimento(Casa* movimentos){
    Casa* casa_atual = movimentos;
    Casa* anterior = NULL; 
    while (casa_atual -> proximo != NULL) { 
       anterior = casa_atual;
       casa_atual = casa_atual -> proximo;
    }
    if (anterior != NULL) { 
        anterior -> proximo = NULL;
    }
    else{
        movimentos = NULL;
    }
    free (casa_atual);
    return movimentos;
}

void imprimirMovimentos(Casa** movimentos){
    Casa* casa = *movimentos;
    printf("\nImprimindo movimentos:\n");
    while (casa != NULL) {
        printf("Movimentos: (%d,%d)\n",casa->x,casa->y);
        casa = casa->proximo;
    }
    printf("Fim da impressão de movimentos.\n");
}

int Andar(Casa** movimentos, Casa* casa_atual, Caminhos** sucessos) {
    if (mapa[casa_atual->x][casa_atual->y] == '1') {
        registrar_sucesso(sucessos, *movimentos);
        return 1;   
    }  
    for (int i = 0; i < 4; i++) {
        int nx = casa_atual->x + dx[i];
        int ny = casa_atual->y + dy[i];

        if (nx >= 0 && nx < 12 && ny >= 0 && ny < 15 && (mapa[nx][ny] == '0' || mapa[nx][ny] == '1')) {
        	mapa[casa_atual->x][casa_atual->y] = '*';
            Casa* proximaCasa = novaCasa(nx, ny);            
            proximaCasa->anterior = casa_atual;
            casa_atual->proximo = proximaCasa;
            registrar_movimento(movimentos, proximaCasa);
            
            if (Andar(movimentos, proximaCasa, sucessos)) {            
                casa_atual->proximo = proximaCasa;
                return 1;  
            }          
            apagar_movimento(*movimentos);
        }      
    }
    mapa[casa_atual->x][casa_atual->y] = '0';  
    casa_atual->proximo = NULL;
    return 0;
}

int calcular_custo(Caminhos* caminho) {
    int custo = 0;
    Casa* casa = caminho->inicio;
    while (casa != NULL) {
        custo++;
        casa = casa->proximo;
    }
    return custo;
}

Casa* Melhor_caminho(Casa* casa_inicial){
    Caminhos* sucessos = NULL;
    Casa* movimentos = novaCasa(casa_inicial->x, casa_inicial->y);
    Andar(&movimentos, casa_inicial, &sucessos);
    Casa* melhor = NULL;
    int melhor_custo = MAX; 
    Caminhos* k = sucessos;
    while(k != NULL){
        int custo = calcular_custo(k);
        if(custo < melhor_custo){
            melhor_custo = custo;
            melhor = k->inicio;
        }
        k = k->proximo;
    }
    return melhor;
}

void marcarMelhorCaminho(Casa* melhor) {
    Casa* atual = melhor;
    while (atual != NULL) {
        if (mapa[atual->x][atual->y] != '1') {
            mapa[atual->x][atual->y] = '*';
        }
        atual = atual->proximo;
        return;
    }
}

int main() {
    printf("\n----------------Mapa de jogo de RPG bidimensional----------------\n");
    montarMapa();
    imprimirMapa();
    int x, y;    
    do {
        printf("\n----------Tente chegar ao castelo localizado no numero 1----------\n\n");
        printf("\nDigite a posição X inicial do personagem: ");
        scanf("%d", &x);
        printf("Digite a posição Y inicial do personagem: ");
        scanf("%d", &y);
        if (mapa[x][y] != '0') {
            printf("\nPosição inválida!\n");
        }
    } while (mapa[x][y] != '0');
    printf("\nPosição inicial do personagem selecionada: (%d, %d)\n", x, y);

    Casa* casa_inicial = novaCasa(x, y);
    Caminhos* sucessos = NULL;
    Casa* movimentos = casa_inicial;

    if (Andar(&movimentos, casa_inicial, &sucessos)) {
        printf("\nMelhor caminho encontrado:\n");
        Casa* atual = sucessos->inicio;
        while (atual != NULL) {
            printf("(%d, %d) -> ", atual->x, atual->y);
            atual = atual->proximo;
        }
        printf("Objetivo\n");
        imprimirMovimentos(&movimentos);
        marcarMelhorCaminho(sucessos->inicio);
        imprimirMapa();
    } 
	else {
        printf("Nenhum caminho encontrado.\n");
    }
    return 0;
}