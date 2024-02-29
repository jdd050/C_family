#include <stdio.h>
#include <stdlib.h>

typedef struct dynArray {
    int *array; // the array itself
    size_t usedCapacity; // size of the existing content
    size_t capacity; // total capacity of the array 
} Array;

int createArray(Array *a, size_t initialSize)
{
    a->array = malloc(initialSize * sizeof(int)); // sizeof(array_type)
    if (a->array == NULL) {
        printf("An error occurred while allocating %zu bytes to array %p", initialSize, a);
        free(a->array);
        return 1;
    }
    a->usedCapacity = 0;
    a->capacity = initialSize;
    return 0;
}

void insertArray(Array *a, int element)
{
    // check if the size of the existing content has reached capacity
    // if so, double the capacity
    if (a->usedCapacity == a->capacity) {
        a->capacity *= 2;
        a->array = realloc(a->array, a->capacity * sizeof(int));
    }
    // "the value of a->array sizeof(array_type) bytes ahead is element"
    a->array[a->usedCapacity] = element;

}

void freeArray(Array *a) 
{   
    free(a->array);
    a->usedCapacity = NULL;
    a->capacity = NULL;
}

int main()
{

    return 0;
}