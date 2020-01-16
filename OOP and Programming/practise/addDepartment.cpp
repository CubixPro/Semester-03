#include<iostream>
#include"classes.hpp"

using namespace std;

int main()
{
    Department dp;
    dp.getInput();
    FILE *fp ;
    fopen("dept.dat", "a");
    fwrite(&dp, sizeof(Department), 1, fp);
    fclose(fp);
}