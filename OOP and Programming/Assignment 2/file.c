#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
    int roll;
    int score[5];
    char name[31];
    int exists; //1 means exists, 0 means doesn't exist
} student;

void getData(student *node)
{
    printf("Enter the roll number : ");
    scanf("%d", &node->roll);
    printf("Enter the name : ");
    /* char ch = getchar();
    while (ch != '\n' || ch != EOF)
        ch = getchar();
    fgets(node->name, 31, stdin);
    */
    scanf("%*c%[^\n]%*c", node->name);
    printf("Enter the marks in the five subjects : ");
    scanf("%d %d %d %d %d", &(node->score[0]), &(node->score[1]), &(node->score[2]), &(node->score[3]), &(node->score[4]));
    node->exists = 1;
}
void modify(student **node)
{
    printf("Enter the details of the new record : ");
    student newnode;
    getData(&newnode);
    *node = &newnode;
}
int main()
{
    int counter = 0;//counter for physical deletion; physically deletes only when counter is equal to 10
    FILE *fp;
    int choice;
    printf("Enter your choice\n\t0. Create a new file\n\t1. Add a new record\n\t2. Display all records\n\t3. Delete a particular record\n\t4. Search for a record\n\t5. Edit a particular record\n\t");
    scanf("%d", &choice);
    while (choice != -1)
    {
        switch (choice)
        {
        case 0:
            fp = fopen("student.dat", "w");
            if (fp != NULL)
            {
                student node;
                getData(&node);
                fwrite(&node, sizeof(student), 1, fp);
            }
            else
            {
                printf("Error\n");
            }
            fclose(fp);
            break;
        case 1:
            fp = fopen("student.dat", "a");
            if (fp != NULL)
            {
                student node;
                getData(&node);
                fwrite(&node, sizeof(student), 1, fp);
            }
            else
            {
                printf("Error occured.\n");
            }
            fclose(fp);
            break;
        case 2:
            fp = fopen("student.dat", "r");
            if (fp == NULL)
                printf("File does not exist.\n");
            else
            {
                student node;
                while (fread(&node, sizeof(student), 1, fp) != 0)
                {
                    if (node.exists == 1)
                        printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\n", node.roll, node.name, node.score[0], node.score[1], node.score[2], node.score[3], node.score[4]);
                }
            }
            fclose(fp);
            break;
        case 3:
            fp = fopen("student.dat", "r+");
            printf("Enter the roll number of the record to be deleted : ");
            int roll_num;
            scanf("%d", &roll_num);
            student node;
            int check = 0;
            while (fread(&node, sizeof(student), 1, fp) != 0)
            {
                if (node.roll == roll_num && node.exists == 1)
                {
                    counter ++;
                    node.exists = 0;
                    check = 1;
                    break;
                }
            }
            if (check == 0)
            {
                printf("Record not found \n");
            }
            else
            {
                fseek(fp, -1 * sizeof(student), 1);
                fwrite(&node, sizeof(student), 1, fp);
            }
            fclose(fp);
            if(counter == 3)
            {
                counter = 0;
                fp = fopen("student.dat", "r");
                FILE *newfp;
                newfp = fopen("copied.dat", "w");
                student node;
                while(fread(&node, sizeof(student), 1, fp) != 0)
                {
                    if(node.exists == 1)
                    {
                        fwrite(&node, sizeof(student), 1, newfp);
                    }
                }
                fclose(fp);
                fclose(newfp);
                fp = fopen("student.dat", "w");
                newfp = fopen("copied.dat", "r");
                while(fread(&node, sizeof(student), 1, newfp) != 0)
                {
                    fwrite(&node, sizeof(student), 1, fp);
                }
                printf("Physical Deletion a success.\n");
                fclose(fp);
                fclose(newfp);
            }

            break;
        case 4:
            fp = fopen("student.dat", "r");
            if (fp != NULL)
            {
                printf("Enter the roll number that you want to search for : ");
                int k;
                scanf("%d", &k);
                int check = 0;
                student node;
                while (fread(&node, sizeof(student), 1, fp) != 0)
                {
                    if (node.roll == k && node.exists == 1)
                    {
                        printf("Record exists.\nName : %s\n", node.name);
                        check = 1;
                        break;
                    }
                }
                if (check == 0)
                    printf("Record not found.\n");
            }
            else
                printf("File doesn't exist.\n");
            break;
        case 5:
            fp = fopen("student.dat", "r+");
            if (fp != NULL)
            {
                student node;
                student newnode;
                int count = 0;
                printf("Enter the roll number that you want to edit : ");
                int rollnum;
                scanf("%d", &rollnum);
                while (fread(&node, sizeof(student), 1, fp) != 0)
                {
                    if (node.roll == rollnum && node.exists == 1)
                    {
                        getData(&newnode);
                        check = 1;
                        break;
                    }
                }
                if (check == 0)
                    printf("Record not found \n");
                else
                {
                    fseek(fp, -1 * sizeof(student), 1);
                    fwrite(&newnode, sizeof(student), 1, fp);
                }
            }
            else
            {
                printf("File not found.\n");
            }

            fclose(fp);
            break;
        default:
            break;
        }
        printf("Enter your choice\n\t1. Add a new record\n\t2. Display all records\n\t3. Delete a particular record\n\t4. Search for a record\n\t5. Edit a particular record\n\t");
        scanf("%d", &choice);
    }
}