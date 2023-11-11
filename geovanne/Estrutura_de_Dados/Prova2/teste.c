#include <stdio.h>
#include <stdlib.h>

long int fatorial(long int n){
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * fatorial(n - 1);
    }  
}

int main(){
    
    printf("Digite o número no qual você quer o fatorial: ");
    long int n;
    scanf("%ld", &n);
    printf("O fatoreal de %ld é %ld\n", n, fatorial(n));
    return 0;
}