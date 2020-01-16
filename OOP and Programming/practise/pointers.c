#include<stdio.h>
#include<stdlib.h>

int main(){
    int* x = (int*)malloc(2 * sizeof(int));
    x[0] = 1;
    x[1] = 2;
    printf("%d", *(x + sizeof(int)));
}