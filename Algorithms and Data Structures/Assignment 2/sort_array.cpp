#include<stdio.h>
#include<stdlib.h>

int main()
{
    int len1, len2;
    scanf("%d %d", &len1, &len2);
    int *arr1 = (int *)malloc(len1 * sizeof(int));
    int *arr2 = (int *)malloc(len2 * sizeof(int));
    for(int i = 0 ; i < len1 ; i++)
    {
         scanf("%d", &arr1[i]);
    }
    for(int i = 0 ; i < len2 ; i++)
    {
        scanf("%d", &arr2[i]);
    }
    int *arr = (int *)malloc((len1 + len2) * sizeof(int));
    int j = 0 ; 
    int k = 0 ;
    int i = 0 ;
    for( i = 0 ; (i < (len1 + len2) && (j < len1) && (k < len2)); i++)
    {
        if(arr1[j] > arr2[k])
        {
            arr[i] = arr2[k];
            k++;
        }
        else if(arr1[j] < arr2[j])
        {
            arr[i] = arr1[j];
            j++;
        }
        else 
        {
            arr[i] = arr1[j];
            arr[++i] = arr2[k];
            k++;
            j++;
            
        }
        //printf("%d %d \n", j, k);
    }
    
        while(j < len1)
        {
            arr[i] = arr1[j];
            i++;
            j++;
        }
        while(k < len2){
            arr[i] = arr2[j];
            k++;
            i++;
    }
  
    for(int i = 0 ; i < len1 + len2 ; i++)
    {
        printf("%d ", arr[i]);
    }
}