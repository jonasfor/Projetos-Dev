#include <stdio.h>
#include <stdlib.h>
int i_fat=0, i_fib=0;
int fib (int n){
    i_fib++;
    if (n<=2){
        return 1;
    }
    else{
        return (fib(n-1)+fib(n-2));

    }
}

    int fat (n){
    i_fat++;
    if (n == 1){
        return 1;
    }
    else{
        return fat(n-1)*n;

    }
}


int main()
{
    int n, t;
    printf("Entre com o tamanho da sequencia a ser calculada (fibonacci): ");
    scanf("%d", &n);
    t = fib(n);
    printf("\nFIB(%d) = %d (%d chamadas)", n, t, i_fib);
    t = 0;
    t = fat(n);
    printf("\nFAT(%d) = %d (%d chamadas)", n, t, i_fat);
    return 0;
}
