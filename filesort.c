#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    FILE *check ;
    int count = 0;
    check = fopen("student.txt", "r");
    if(check != NULL)
    {
        for (char c = getc(check); c != EOF; c = getc(check)) 
        if (c == '\n') // Increment count if this character is newline 
            count = count + 1; 
    }
    FILE *fp;
    fp = fopen("student.txt", "r");
    if(fp != NULL)
    {
        
        char **str = (char **)malloc(count * sizeof(char *));
        for(int i = 0 ; i < count ; i++)
        {
            str[i] = (char *)malloc(1000 * sizeof(char));
        }
        int i = 0 ;
        while(fgets(str[i++], 1000, fp) != NULL)
        {
            //printf("%s", str[i - 1]);
        }
        for(int i = 0 ; i < count - 1; i++)
        {
            for(int j = 0 ; j < count - 1 - i ; j++)
            {
                if(strcmp(str[j], str[j + 1]) > 0)
                {
                    char temp[1000];
                    strcpy(temp, str[j]);
                    strcpy(str[j], str[j + 1]);
                    strcpy(str[j + 1], temp);
                }
            }
        }
        FILE *fp2;
        fp2 = fopen("sort.txt", "w");
        if(fp2!=NULL)
        {
            for(int i = 0 ; i < count ; i++)
                fprintf(fp2, "%s", str[i]);
        }

    }
}