#include <stdio.h>
#include <stdlib.h>
struct DOB {
    int day;
    int *month;
    int year;
};
struct INFO {
    int reg_no;
    char *name;
    char address[100];
};

struct UNI {
    char *college_name;
    char university_name[100];
};

struct STUDENT {
    struct DOB dob;
    struct INFO stu_info;
    struct UNI college;
};

int main() {
    struct STUDENT *student = (struct STUDENT *)malloc(sizeof(struct STUDENT));
    if (student == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int month;
    student->dob.month = &month;
    student->stu_info.name = "John Doe";
    student->college.college_name = "XYZ College";

    printf("Enter date of birth (day month year): ");
    scanf("%d %d %d", &student->dob.day, student->dob.month, &student->dob.year);

    printf("Enter registration number: ");
    scanf("%d", &student->stu_info.reg_no);
    
    printf("Enter address: ");
    scanf("%s", student->stu_info.address);

    printf("Enter university name: ");
    scanf("%s", student->college.university_name);

    printf("\nStudent Information:\n");
    printf("Name: %s\n", student->stu_info.name);
    printf("Date of Birth: %d-%d-%d\n", student->dob.day, *student->dob.month, student->dob.year);
    printf("Registration Number: %d\n", student->stu_info.reg_no);
    printf("Address: %s\n", student->stu_info.address);
    printf("College Name: %s\n", student->college.college_name);
    printf("University Name: %s\n", student->college.university_name);

    free(student);

    return 0;
}
