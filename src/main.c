#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char const *argv[])
{
    stack* temp = stack_create_from_list((int[]){1,2,3,4,5,6,7,8,9,10}, 10, sizeof(int));
    stack_free(temp, NULL);
    return 0;
}