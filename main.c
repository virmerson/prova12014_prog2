#include "MySet.h"
#include <stdio.h>

int main(int argc, const char * argv[]) {

    MySet *mySet = create(5);
    
    add(mySet, 30);
    add(mySet, 20);
    add(mySet, 10);
    
    quickSort(mySet);
    printElements(mySet);
    bool  exist = existsSum(mySet, 55);
    printf(exist? "\nExiste":"\nNão Existe");
    
    return 0;
}
