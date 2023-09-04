#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct DOB{
    int day, month, year;
}DOB;

typedef struct ADDRESS{
    int houseNo;
    int zipCode;
    char state[100];
}ADDRESS;

typedef struct employee{
    char name[100];
    DOB dob;
    ADDRESS address;
}emp;

int main(){
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    emp *a = malloc(n*sizeof(emp));
    emp *p=a;
    printf("Enter the following data: \n");
    for(int i=0; i<n; i++){
        printf("\nEMPLOYEE %d: \n", i+1);
        printf("Enter name: ");
        scanf("%s", p->name);
        printf("Enter DOB: ");
        scanf("%d %d %d", &p->dob.day, &p->dob.month, &p->dob.year);
        printf("Enter address- \n");
        printf("House Number: ");
        scanf("%d", &p->address.houseNo);
        printf("Zip code: ");
        scanf("%d", &p->address.zipCode); 
        printf("State: ");
        scanf("%s", p->address.state);
        p++;
    }
    
    p=a;
    printf("\nDisplaying entered details: \n");
    for(int i=0; i<n; i++){
        printf("\nEMPLOYEE %d: \n", i+1);
        printf("Name: %s \n", p->name);
        printf("DOB: %d %d %d \n", p->dob.day, p->dob.month, p->dob.year);
        printf("Address- \n");
        printf("House Number: %d \n", p->address.houseNo);
        printf("Zip code: %d \n", p->address.zipCode); 
        printf("State: %s \n",p->address.state);
        p++;
    }
    return 0;
}