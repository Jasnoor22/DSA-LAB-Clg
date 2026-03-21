// Write a program to read the name, address, and salary of 5 employees using array of structure. Display information of each employee in alphabetical order of their name.
#include<stdio.h>
#include<string.h>

struct employee {
    char name[40];
    char address[100];
    float salary;
};

int main() {
    struct employee emp[5], temp;
    int i, j;

    for(i = 0; i < 5; i++) {
        printf("\nEnter details of employee %d\n", i + 1);

        printf("Name: ");
        getchar();  // clear buffer
        fgets(emp[i].name, sizeof(emp[i].name), stdin);
        emp[i].name[strcspn(emp[i].name, "\n")] = 0;

        printf("Address: ");
        fgets(emp[i].address, sizeof(emp[i].address), stdin);
        emp[i].address[strcspn(emp[i].address, "\n")] = 0;

        printf("Salary: ");
        scanf("%f", &emp[i].salary);
    }

    for(i = 0; i < 4; i++) {
        for(j = i + 1; j < 5; j++) {
            if(strcmp(emp[i].name, emp[j].name) > 0) {
                temp = emp[i];
                emp[i] = emp[j];
                emp[j] = temp;
            }
        }
    }

    printf("\nEmployee Records in Alphabetical Order of Name:\n");
    for(i = 0; i < 5; i++) {
        printf("Name: %s, Address: %s, Salary: %.2f\n",
               emp[i].name, emp[i].address, emp[i].salary);
    }

    return 0;
}