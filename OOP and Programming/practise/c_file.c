#include<stdio.h>
#include<stdlib.h>
typedef struct {
    char name[31];
    int roll;
}student;

int main(){
    FILE* fp;
    int ch;
    scanf("%d", &ch);
    student s;
    while(ch != 0){
    switch(ch){
        case 1:
                scanf("%s %d", s.name, &s.roll); 
                fp = fopen("student.dat", "a");
                fwrite( &s, sizeof(student), 1, fp);
                fclose(fp);
                break;
        case 2: 
                fp = fopen("student.dat", "r");
                fread(&s, sizeof(student), 1, fp);
                printf("%s", s.name);
                fclose(fp);
                break;
    }
    scanf("%d", &ch);
}

}

