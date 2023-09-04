#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct DOB{
    int day, month, year;
}DOB;

typedef struct STU_INFO{
    int reg_no;
    char name[50];
    char address[100];
}STU_INFO;

typedef struct COLLEGE{
    char college_name[100];
    char university_name[100];
}COLLEGE;

typedef struct STUDENT{
    DOB *dob;
    STU_INFO *stu_info;
    COLLEGE *college;
}STUDENT;

int main(){
    STUDENT *p = malloc(sizeof(STUDENT));
    p->dob = malloc(sizeof(DOB));
    p->stu_info = malloc(sizeof(STU_INFO));
    p->college = malloc(sizeof(COLLEGE));

    printf("Enter the following details: ");

    printf("Enter DOB (DD MM YYYY): ");
    scanf("%d %d %d", &p->dob->day, &p->dob->month, &p->dob->year);

    printf("Enter Registration number: ");
    scanf("%d", &p->stu_info->reg_no);

    printf("Enter name: ");
    scanf("%s[^\n]", p->stu_info->name);
    //gets(p->stu_info->name);

    printf("Enter address: ");
    scanf("%s[^\n]", p->stu_info->address);
    //gets(p->stu_info->address);

    printf("Enter college name: ");
    scanf("%s[^\n]", p->college->college_name);
    //gets(p->college->college_name);

    printf("Enter University name: ");
    scanf("%s[^\n]", p->college->university_name);
    //gets(p->college->university_name);

    printf("\nDisplaying entered data: \n");
    printf("DOB: %d %d %d \n", p->dob->day, p->dob->month, p->dob->year);
    printf("Registration number: %d \n", p->stu_info->reg_no);
    printf("Name: %s \n", p->stu_info->name);
    printf("Address: %s \n", p->stu_info->address);
    printf("College name: %s \n", p->college->college_name);
    printf("University name: %s \n", p->college->university_name);

    free(p->dob);
    free(p->stu_info);
    free(p->college);
    free(p);
    return 0;
}