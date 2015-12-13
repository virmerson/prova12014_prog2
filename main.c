#include "MySet.h"
#include <stdio.h>


int main(int argc, const char * argv[]) {

    
    int k, n, i, x, j=0;
    MySet *set=  create(100);
    
    printf("Quantos casos de teste?");
    scanf("%d", &k);
 
    //Casos de Teste
    while(k > 0)
    {
    
        //Lendo no vetor a sequencia para cada caso de teste
        printf ("Sequencia %d terá quantos números?", ++j);
        scanf("%d", &n);
        //Lendo a sequencia
        for(i = 0; i < n; i++)
            scanf("%d", &set->data[i]);
        
        set->numOfElements = n;
        //Número que deseja saber se tem 2 termos do vetor que dá a soma.
        printf("Verificar soma de qual número? " );
        scanf("%d", &x);
        
        //Existe soma?
        if(existsSum(set, x))
            printf("Sim Existe\n");
        else
            printf("Não Existe\n");
        
        k--;
    }
    destroy(set);
}
