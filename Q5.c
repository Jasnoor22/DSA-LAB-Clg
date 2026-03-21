#include <stdio.h>
#include <string.h>  

struct date {
    int day;
    int month;
    int year;
};

struct employee {
    char name[40];
    int id;
    float salary;
    struct date dob;
};

int main() {
    struct employee emp;

    printf("Enter employee details:\n");

    printf("Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = '\0';

    printf("ID: ");
    scanf("%d", &emp.id);

    printf("Salary: ");
    scanf("%f", &emp.salary);

    printf("Date of Birth (dd mm yyyy): ");
    scanf("%d %d %d", &emp.dob.day, &emp.dob.month, &emp.dob.year);

    printf("\nEmployee Details:\n");
    printf("Name: %s\n", emp.name);
    printf("ID: %d\n", emp.id);
    printf("Salary: %.2f\n", emp.salary);
    printf("Date of Birth: %02d/%02d/%04d\n",
           emp.dob.day, emp.dob.month, emp.dob.year);

    return 0;
}