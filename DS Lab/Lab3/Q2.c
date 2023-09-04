#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct STUDENT{
    char name[100];
    int rollNo;
    float CGPA;
}std;

int main(){
    int n;
    printf("Enter number of Students: ");
    scanf("%d", &n);
    std *a = malloc(n*sizeof(std));
    std *p=a;
    printf("\nEnter the following data: \n");
    for(int i=0; i<n; i++){
        printf("\nSTUDENT %d: \n", i+1);
        printf("Enter name: ");
        scanf("%s", p->name);
        printf("Enter Roll No: ");
        scanf("%d", &p->rollNo);
        printf("Enter CGPA: ");
        scanf("%f", &p->CGPA);
        p++;
    }
    
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(a[j].rollNo<a[i].rollNo){
                std temp = a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }

    p=a;
    printf("\nDisplaying entered details: \n");
    for(int i=0; i<n; i++){
        printf("\nSTUDENT %d: \n", i+1);
        printf("Name: %s \n", p->name);
        printf("Roll No: %d \n", p->rollNo);
        printf("CGPA: %.2f \n", p->CGPA);
        p++;
    }
    return 0;
}