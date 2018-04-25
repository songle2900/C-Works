#include <stdio.h>

#define SIZE 4

struct Emp{
	int eid;
	int eage;
	double esal;
	double nesal;
};

int main(void){
	int menu;
	struct Emp emps[SIZE];
	int i = 0;
	int j = 0;
	int id = 0;

	printf("---=== EMPLOYEE DATA ===---\n\n");

	while(1){
		printf("1. Display Employee Information\n2. Add Employee\n3. Update Employee Salary\n4. Remove Employee\n0. Exit\n\n");
		printf("Please select from the above options: ");
		scanf("%d", &menu);
		printf("\n");
			if (menu >= 5)
			{
				printf("ERROR: Incorrect Option: Try Again\n\n");
				printf("1. Display Employee Information\n2. Add Employee\n3. Update Employee Salary\n4. Remove Employee\n0. Exit\n\n");
				printf("Please select from the above options: ");
				scanf("%d", &menu);
				printf("\n");
			}
		switch(menu){
		case 0:
			printf("Exiting Employee Data Program. Good Bye!!!\n");
			return 0;
		case 1:
			printf("EMP ID  EMP AGE EMP SALARY\n======  ======= ==========\n");
			for(j = 0; j < SIZE; j++)
			{
			if (emps[j].eid > 0)
			{
				printf("%d \t%d \t%.2lf\n", emps[j].eid, emps[j].eage, emps[j].esal);
			}
			}
			printf("\n");
			break;
		case 2:
			if(i<SIZE){
			printf("Adding Employee\n===============\n");
			printf("Enter Employee ID: ");
			scanf("%d", &emps[i].eid);
			printf("Enter Employee Age: ");
			scanf("%d", &emps[i].eage);
			printf("Enter Employee Salary: ");
			scanf("%lf", &emps[i].esal);
			printf("\n");
			break;
			}
			if(i>=SIZE){
			printf("Adding Employee\n================\n");
			printf("ERROR!!! Maximum Number of Employees Reached\n\n");
			break;
			}
	
		case 3:
			printf("Update Employee Information\n===========================\n");
			printf("Enter Employee ID: ");
			scanf("%d", &id);
			j=0;
			//for(j=0;j<SIZE;j++){
			do{
				if(id == emps[j].eid){
					printf("The current salary is %.2lf\n", emps[j].esal);
					printf("Enter Employee New Salary: ");
					scanf("%lf", &emps[j].esal);
					emps[i].esal = emps[j].esal;
				}
				j++;
			}while(j<SIZE);
			printf("\n");
			break;
		case 4:
			printf("Remove Employee\n===============\n");
			printf("Enter Employee ID: ");
			scanf("%d", &id);
			j=0;
			do{
				if(id == emps[j].eid){
				printf("Employee %d will be removed\n\n", id);
					do{
						emps[j].eid = emps[j+1].eid;
						emps[j].eage = emps[j+1].eage;
						emps[j].esal = emps[j+1].esal;
						j++;
					}while(j<SIZE);
				}
				j++;
			}while(j<SIZE);
			emps[SIZE-1].eid = 0;
			emps[SIZE-1].eage = 0;
			emps[SIZE-1].esal = 0;
			emps[SIZE-1].eid;
			emps[SIZE-1].eage;
			emps[SIZE-1].esal;	
		}
		i++;
	}

	printf("Exiting Employee Data Program. Good Bye!!!");
	return 0;
}
