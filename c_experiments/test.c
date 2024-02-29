#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *myNumber = malloc(sizeof(int));
    *myNumber = 5;
    printf("test error message:\nfailed to allocate %zu bytes to array %p that contained value %d\n", sizeof(int), myNumber, *myNumber);
    free(myNumber);
    return 0;
}