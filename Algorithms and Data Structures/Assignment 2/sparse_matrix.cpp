#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int size;
    int *i;
    int *j;
    int *val;
    int r, c;
}matrix;

void allocate(matrix *mat)
{
    mat->i = (int *)malloc(sizeof(int) * mat->size);
    mat->j = (int *)malloc(sizeof(int) * mat->size);
    mat->val = (int *)malloc(sizeof(int) * mat->size);
}

void input_val(matrix* mat)
{
    for(int k = 0 ; k < mat->size ; k++)
    {
        scanf("%d %d %d", &mat->i[k], &mat->j[k], &mat->val[k]);
    }
}

void input_deets(matrix* mat)
{
    printf("%d %d %d", mat->size, mat->r, mat->c);
}

matrix* add(matrix m1, matrix m2)
{
    if(m1.r == m2.r && m1.c == m2.c)
    {
        matrix m3;
        m3.r = m2.r;
        m3.c = m2.c; 
        m3.size = m2.size + m1.size;
        int count = 0;
        for(int k = 0 ; k < m1.size ; k++)
        {
            m3.val[count] = m1.val[k];
            for(int l = 0 ; l < m2.size ; l++)
            {
                if(m1.i[k] == m2.i[l] && m1.j[k] == m2.j[l])
                {
                    m3.val[count] += m2.val[l]; 
                    
                }
            }
            m3.i[count] = m1.i[k];
            m3.j[count] = m1.j[k];
            count++;
        }
       outer : for(int k = 0 ; k < m2.size ; k++)
        {
            m3.val[count] = m2.val[k];
            for(int l = 0 ; l < m1.size ; l++)
            {
                if(m2.i[k] == m1.i[l] && m2.j[k] == m1.j[l])
                {
                    goto outer;      
                }
            }
            m3.i[count] = m1.i[k];
            m3.j[count] = m1.j[k];
            count++;
        }
 
    }
}

int main()
{
    matrix a1, a2;
    int size1, size2;
    scanf("%d %d", &size1, &size2);
    matrix *a3;
    input_deets(&a1);
    input_deets(&a2);
    allocate(&a1);
    allocate(&a2);
    input_val(&a1, &a2);
    matrix* m = add(a1, a2);
}
