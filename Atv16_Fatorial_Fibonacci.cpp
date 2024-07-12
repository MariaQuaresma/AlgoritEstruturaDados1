#include <stdio.h>
int fibonacci(int n){
    if (n == 0 || n == 1){
        return 1;
    }
    else{

        return fibonacci(n-1)+fibonacci(n-2);
    }
}

int fatorial(int n){
    if (n<=1){
        return 1;
    }
    else{

        return n * fatorial(n-1);
    }
}
 
int main(){
    int n, escolha;
    printf("1 - Fibonacci\n");
    printf("2 - Fatorial\n");
    printf("3 - Sair\n");
    printf("Escolha:\n");
    scanf("%d", &escolha);
    switch(escolha){
    	case 1:
    		printf("\nDigite um numero: \n");
            scanf("%d", &n);
            printf("\nO numero fatorado é: %d\n", fibonacci(n));
            break;
        case 2: 
            printf("\nDigite um numero: \n");
            scanf("%d", &n);
            printf("\nO numero fatorado é: %d\n", fatorial(n));
            break;
        case 3: 
            printf("\nFechado, até logo.\n");
            break;
        default:
        	printf("Opção inválida.\n");  
	}
}