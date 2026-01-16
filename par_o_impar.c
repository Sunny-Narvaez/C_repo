#include <stdio.h>

int main(void){
    int x;
    printf("Inserte un numero entero:");
    scanf("%d", &x);
    if (x % 2 == 0){
        printf("%d es un numero par\n", x);
    }else{
        printf("%d es un numero impar\n", x);
    }
    return 0;
}