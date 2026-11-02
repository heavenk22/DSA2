#include <stdio.h>

struct Student {
    int roll;
    char name[50], program[30], course[30];
    float marks[5], total, average;
};

int main() {
    struct Student s[100], temp;
    int n = 0, choice, i, j, pos, roll;

    while(1) {
        printf("\n--- STUDENT DATABASE ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Sort by Average\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

        case 1:
            printf("Enter Roll No: ");
            scanf("%d", &s[n].roll);

            printf("Enter Name: ");
            scanf("%49s", s[n].name);

            printf("Enter Program: ");
            scanf("%29s", s[n].program);

            printf("Enter Course: ");
            scanf("%29s", s[n].course);

            s[n].total = 0;

            printf("Enter marks of 5 subjects:\n");
            for(i = 0; i < 5; i++) {
                scanf("%f", &s[n].marks[i]);
                s[n].total += s[n].marks[i];
            }

            s[n].average = s[n].total / 5;
            n++;

            printf("Student added successfully!\n");
            break;

        case 2:
            printf("\n--- STUDENT RECORDS ---\n");

            for(i = 0; i < n; i++) {
                printf("\nRoll No: %d", s[i].roll);
                printf("\nName: %s", s[i].name);
                printf("\nProgram: %s", s[i].program);
                printf("\nCourse: %s", s[i].course);

                printf("\nTotal: %.2f", s[i].total);
                printf("\nAverage: %.2f\n", s[i].average);
            }
            break;

        case 3:
            printf("Enter Roll No to search: ");
            scanf("%d", &roll);

            pos = -1;

            for(i = 0; i < n; i++) {
                if(s[i].roll == roll) {
                    pos = i;
                    break;
                }
            }

            if(pos != -1) {
                printf("Student Found!\n");
                printf("Name: %s\n", s[pos].name);
                printf("Average: %.2f\n", s[pos].average);
            }
            else {
                printf("Student not found!\n");
            }
            break;

        case 4:
            printf("Enter Roll No to update: ");
            scanf("%d", &roll);

            pos = -1;

            for(i = 0; i < n; i++) {
                if(s[i].roll == roll) {
                    pos = i;
                    break;
                }
            }

            if(pos != -1) {
                printf("Enter New Name: ");
                scanf("%49s", s[pos].name);

                printf("Enter New Program: ");
                scanf("%29s", s[pos].program);

                printf("Enter New Course: ");
                scanf("%29s", s[pos].course);

                s[pos].total = 0;

                printf("Enter Updated Marks:\n");
                for(i = 0; i < 5; i++) {
                    scanf("%f", &s[pos].marks[i]);
                    s[pos].total += s[pos].marks[i];
                }

                s[pos].average = s[pos].total / 5;

                printf("Record updated successfully!\n");
            }
            else {
                printf("Student not found!\n");
            }
            break;

        case 5:
            for(i = 0; i < n-1; i++) {
                for(j = 0; j < n-i-1; j++) {
                    if(s[j].average < s[j+1].average) {
                        temp = s[j];
                        s[j] = s[j+1];
                        s[j+1] = temp;
                    }
                }
            }

            printf("Students sorted by average marks!\n");
            break;

        case 6:
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}