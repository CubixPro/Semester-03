//#include<iostream>
#include<stdio.h>
#include<stdlib.h>
//using namespace std;

int main(){
    int (*p)[10];
    int *x = (int *)malloc(sizeof(int) * 10);
    int m[2][10];
    m[0][0] = 5;
    m[1][0] = 10;
    p = m;
    printf("%d %d\n", **p, **(p + 1));
}