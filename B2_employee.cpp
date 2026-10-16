#include <stdio.h>
#include <stdlib.h>
#define FULL_TIME 0
#define CONTRACT 1

typedef struct {
    char name[20];
    int emp_id;
    int type;
    union {
        float salary;
        struct {
            float hourly_rate;
            int hours_worked;
        } contract_info;
    } pay;
} Employee;

int main(void) {
    Employee *e;
    int n,i;
    float total_bill=0,total_pay;

    printf("Enter number of employees: ");
    scanf("%d",&n);
    if(n<=0) {
        printf("Invalid number of employees.\n");
        return 1;
    }

    e=(Employee*)malloc(n*sizeof(Employee));
    if(e==NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for(i=0;i<n;i++) {
        printf("\nEmployee %d\n",i+1);
        printf("Enter name: ");
        scanf("%19s",e[i].name);
        printf("Enter employee ID: ");
        scanf("%d",&e[i].emp_id);
        printf("Enter type (0=Full-time, 1=Contract): ");
        scanf("%d",&e[i].type);

        if(e[i].type==FULL_TIME) {
            printf("Enter monthly salary: ");
            scanf("%f",&e[i].pay.salary);
        }
        else if(e[i].type==CONTRACT) {
            printf("Enter hourly rate: ");
            scanf("%f",&e[i].pay.contract_info.hourly_rate);
            printf("Enter hours worked: ");
            scanf("%d",&e[i].pay.contract_info.hours_worked);
        }
        else {
            printf("Invalid employee type.\n");
            free(e);
            return 1;
        }
    }

    printf("\n===== EMPLOYEE PAYSLIPS =====\n");
    for(i=0;i<n;i++) {
        if(e[i].type==FULL_TIME)
            total_pay=e[i].pay.salary;
        else
            total_pay=e[i].pay.contract_info.hourly_rate*
                      e[i].pay.contract_info.hours_worked;

        printf("\nEmployee ID: %d\n",e[i].emp_id);
        printf("Name: %s\n",e[i].name);
        printf("Type: %s\n",e[i].type==FULL_TIME?"Full-time":"Contract");
        printf("Total Pay: %.2f\n",total_pay);
        total_bill+=total_pay;
    }

    printf("\nTotal Salary Bill: %.2f\n",total_bill);
    free(e);
    return 0;
}
