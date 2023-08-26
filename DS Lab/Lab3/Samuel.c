#include <stdio.h>
#include <stdlib.h>
struct DOB {
    int day;
    int month;
    int year;
};
struct Address {
    int house_num;
    int zipCode;
    char state[50];
};
struct Employee {
    char name[50];
    struct DOB dob;
    struct Address address;
};
int main() {
    int n;
    printf("Enter the number of emp: ");
    scanf("%d", &n);
    struct Employee *emp = (struct Employee *)malloc(n * sizeof(struct Employee));
    if (emp == NULL) {
        printf("Memory allocation failed.\n");
        return 1;}
    for (int i = 0; i < n; i++) {
        printf("Enter details for employee %d:\n", i + 1);
        printf("Enter employee name: ");
        scanf("%s", emp[i].name);
        printf("Enter date of birth (day month year): ");
        scanf("%d %d %d", &emp[i].dob.day, &emp[i].dob.month, &emp[i].dob.year);
        printf("Enter address (house number zip code state): ");
        scanf("%d %d %s", &emp[i].address.house_num, &emp[i].address.zipCode, emp[i].address.state);
        printf("\n");
    }
    printf("\nEmployee Information:\n");
    for (int i = 0; i < n; i++) {
        printf("Employee %d:\n", i + 1);
        printf("Name: %s\n", emp[i].name);
        printf("DOB of Birth: %d-%d-%d\n", emp[i].dob.day, emp[i].dob.month, emp[i].dob.year);
        printf("Address: %d, %d, %s\n", emp[i].address.house_num, emp[i].address.zipCode, emp[i].address.state);
        printf("\n");
    }
    free(emp);
    return 0;
}