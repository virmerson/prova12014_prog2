#include "MySet.h"
#include <stdio.h>


int main(int argc, const char * argv[]) {

    
    int k, n, i, x, j;
    MySet *set=  create(100);
    
    printf("Digite número de casos de teste:");
    scanf("%d", &k);
 
    //Casos de Teste
    while(k > 0)
    {
        j = 0;
        //Lendo no vetor a sequencia para cada caso de teste
        printf ("Sequencia de quantos números?");
        scanf("%d", &n);
        //Lendo a sequencia
        for(i = 0; i < n; i++)
            scanf("%d", &set->data[i]);
        
        set->numOfElements = n;
        //Número que deseja saber se tem 2 termos do vetor que dá a soma.
        printf("Número X da Soma: " );
        scanf("%d", &x);
        
        //Existe soma?
        if(existsSum(set, x))
            printf("S\n");
        else
            printf("N\n");
        
        k--;
    }
    destroy(set);
}
