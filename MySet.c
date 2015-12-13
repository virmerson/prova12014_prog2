#include "MySet.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

MySet *create(int n){

    MySet *newMySet =  malloc(sizeof(MySet));
    
    if (!newMySet){
        printf("Error Memory Alocation");
        exit(1);
    }
    
    newMySet->data =  malloc(n* sizeof(int));
   
    if (!newMySet->data){
        printf("Error Memory Alocation");
        exit(1);
    }
    
    newMySet->numOfElements=0;
    newMySet->capacity=n;
    
    
    return newMySet;
}
void add(MySet *set,int value){
   
    if ( set->numOfElements<set->capacity){
        set->data[ set->numOfElements] =  value;
        set->numOfElements++;
    } else {
        printf("Memory Overflow!");
        exit(1);
    }
}

void destroy(MySet *set){
    free(set->data);
    free(set);
}

void toString(MySet *set){
    printf("\n numOfElements:%d",set->numOfElements);
    printf("\n capacity:%d",set->capacity);
}

void printElements(MySet *set){
    int i;
    for(i=0; i<set->numOfElements; i++){
        printf("\n%d", set->data[i]);
    }
}

//Sorting

int partition (MySet *V, int p, int r)
{
    int x=V->data[p]; int i=p-1; int q=r+1; int temp;
    while (1) {
        do {  q--; } while (V->data[q] > x);
        do {  i++; } while (V->data[i] < x);
        if(i < q)  { temp = V->data[i];
            V->data[i] = V->data[q];
            V->data[q] = temp;
        }
        else return q;
    }
}



void quickSortRec(MySet *set, int p, int r)
{
    if (p < r)
    {
        int q  = partition (set, p, r);
        quickSortRec(set, p, q);
        quickSortRec(set, q+1, r);
    }
}

void quickSort(MySet *set)
{
    quickSortRec (set, 0, set->numOfElements-1);
}

//O(n log n)
//Vai rodar n vezes no for mais para cada 1 faz uma busca binária log n totalizando n log n
bool existsSum (MySet *set , int x){
    int i;
    //Percorrendo o vetor
    for (i=0; i<set->numOfElements; i++){
        
        //Elemento canditado a bater com a soma
        int dif = x- set->data[i];
        
        //Buscando pelo elemento candidato que é a diferenca entre x e cada elemento vetor
        //O(log n)
        int index = binarySearch(set,dif);
        
        //Encontrou o elemento em alguma posição?
        if (index!=-1){
           
            //Calculando a soma entre o elemento encontrado com o valor comparado no momento
            int sum  = set->data[index] + set->data[i];
            //Bate a soma?
            if (sum == x){
                return true;
            }
        }
    }
    return false;
}

int binarySearch(MySet *set, int x)
{
    int p, q, r;
    p = -1;
    r = set->numOfElements;
    
    while(p < r-1)
    {
        q = (p+r) / 2;
        if(x < set->data[q])
            r = q;
        else
            p = q;
    }
    return p;
}



