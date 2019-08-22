#include<stdio.h>
typedef struct {
    int coeff[10000];
    int power[10000];
    int begin[100];
    int end[100];
    int count;
}polynomials;

void input(polynomials *poly)
{
    printf("Enter -1 to stop entering polynomials, 0 to enter a new polynomial. Enter polynomials in decreasing power\n");
    int ch;
    scanf("%d", &ch);
    while(ch != -1)
    {
        switch(ch)
        {
            case 0:{
                printf("Enter the terms you want : ");
                int terms ;
                scanf("%d", &terms);
                for(int i = poly->begin[poly->count]; i < poly->begin[poly->count] + terms ; i++)
                {
                    printf("coeff : ");
                    scanf("%d", &(poly->coeff[i]));
                    printf("Power : ");
                    scanf("%d", &(poly->power[i]));
                }
                poly->end[poly->count] = poly->begin[poly->count] + terms - 1;
                poly->count++;
                poly->begin[poly->count] = poly->end[poly->count - 1] + 1;
            }
            default : break;
        }
        printf("Enter -1 to stop entering polynomials, 0 to enter a new polynomial. Enter polynomials in decreasing power\n");
        
        scanf("%d", &ch);
    }
}

void print_all(polynomials poly)
{
    for(int i = 0 ; i < poly.count ; i++)
    {
        for(int j = poly.begin[i] ; j < poly.end[i] ; j++)
        {
            printf("%dx^%d + ", poly.coeff[j], poly.power[j]);
        }
        printf("%dx^%d\n", poly.coeff[poly.end[i]], poly.power[poly.end[i]]);

    }
}
int degree(polynomials poly, int i)
{
   // printf("Degree of polynomial %d : %d\n", coeff[begin[i - 1]]);
   return poly.coeff[poly.begin[i - 1]];
}
void add(polynomials* poly, int i, int j)
{
    int a = poly->begin[i];
    int b = poly->begin[j];
    int k = 0;
    while(a <= poly->end[i] && b <= poly->end[j])
    {
        if(poly->power[a] > poly->power[b])
        {
            poly->coeff[poly->begin[poly->count]+k] = poly->coeff[a];
            poly->power[poly->begin[poly->count]+k] = poly->power[a];
            k++;
            a++;
        }
        else if(poly->power[b] > poly->power[b])
        {
            poly->coeff[poly->begin[poly->count]+k] = poly->coeff[b];
            poly->power[poly->begin[poly->count]+k] = poly->power[b];
            k++;
            b++;
        }
        else
        {
            poly->coeff[poly->begin[poly->count]+k] = poly->coeff[a] + poly->coeff[b];
            poly->power[poly->begin[poly->count]+k] = poly->power[a];
            k++;
            a++;
            b++;
        }
    }
    for(; a <= poly->end[i] ; a++)
    {
        poly->coeff[poly->begin[poly->count]+k] = poly->coeff[a];
            poly->power[poly->begin[poly->count]+k] = poly->power[a];
            k++;
           
    }
    for(; b <= poly->end[j] ; b++)
    {
        poly->coeff[poly->begin[poly->count]+k] = poly->coeff[b];
            poly->power[poly->begin[poly->count]+k] = poly->power[b];
            k++;
    }

    poly->end[poly->count] = poly->begin[poly->count] + k - 1;
    poly->count ++;
    poly->begin[poly->count] = poly->end[poly->count - 1] + 1;


}
int main()
{
    printf("Maximum number of terms is 10000");
    printf("Maximum number of polynomials is 100");
    polynomials poly;
    poly.begin[0] = 0;
    poly.count = 0;
    input(&poly);
    print_all(poly);
    add(&poly, 0, 1);
    print_all(poly);

}