#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct MyStudent {
    char name[50];
    int roll_num;
    float cgpa;
};
void readStudent(struct MyStudent *student) {
    printf("Enter student name: ");
    scanf("%s", student->name);
    printf("Enter roll number: ");
    scanf("%d", &student->roll_num);
    printf("Enter CGPA: ");
    scanf("%f", &student->cgpa);
}
void displayStudent(const struct MyStudent *student) {
    printf("Name: %s\n", student->name);
    printf("Roll Number: %d\n", student->roll_num);
    printf("CGPA: %.2f\n", student->cgpa);
}
int compareByRollNumber(const void *a, const void *b) {
    const struct MyStudent *studentA = (const struct MyStudent *)a;
    const struct MyStudent *studentB = (const struct MyStudent *)b;
    return studentA->roll_num - studentB->roll_num;
}
int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    struct MyStudent *students = (struct MyStudent *)malloc(numStudents * sizeof(struct MyStudent));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (int i = 0; i < numStudents; i++) {
        printf("Enter details for student %d:\n", i + 1);
        readStudent(&students[i]);
    }
    printf("\nStudent Information:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("MyStudent %d:\n", i + 1);
        displayStudent(&students[i]);
        printf("\n");
    }
    qsort(students, numStudents, sizeof(struct MyStudent), compareByRollNumber);
    printf("\nStudent Information (Sorted by Roll Number):\n");
    for (int i = 0; i < numStudents; i++) {
        printf("MyStudent %d:\n", i + 1);
        displayStudent(&students[i]);
        printf("\n");
    }
    free(students);
    return 0;
}