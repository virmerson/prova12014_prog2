
#include <stdbool.h>

typedef struct {
    int numOfElements;
    int capacity;
    int *data;

}MySet;

MySet* create (int);
void destroy(MySet* );

void add(MySet*, int);

//Sorting
int partition (MySet*, int, int);
void quickSortRec(MySet*, int, int);
void quickSort(MySet*);


void printElements(MySet*);
void toString(MySet*);

//Search
int binarySearch(MySet*, int);
bool existsSum (MySet* , int );




