#include <stdio.h>

#define SIZE 2

struct Emp{
	int eid;
	int eage;
	double esal;
};

int main(void){
	int menu;
	struct Emp emps[SIZE];
	int i = 0;
	int j = 0;

	printf("---=== EMPLOYEE DATA ===--- \n");
	printf("\n");

	while(1){
	printf("1. Display Employee Information\n2. Add Employee\n0. Exit\n");
	printf("\n");
	printf("Please select from the above options: ");
	scanf("%d", &menu);
	printf("\n");
		
		if(i >= 2 && menu ==2){
			printf("Adding Employee \n===============\n");
		       	printf("ERROR!!! Maximum Number of Employees Reached\n\n");
		}

		if(menu == 0){
			break;
		}

		if(menu == 1){
			printf("EMP ID  EMP AGE EMP SALARY\n======  ======= ==========\n");
			for(j=0;j<2;j++){
			printf("%d \t%d \t%.2lf\n", emps[j].eid, emps[j].eage, emps[j].esal);
			}
			printf("\n");
		}

		if(menu == 2 && i < 2){
			printf("Adding Employee\n===============\n");
			printf("Enter Employee ID: ");
			scanf("%d", &emps[i].eid);
			printf("Enter Employee Age: ");
			scanf("%d", &emps[i].eage);
			printf("Enter Employee Salary: ");
			scanf("%lf", &emps[i].esal);
			printf("\n");
		}
		
		i++;
	}

	printf("Exiting Employee Data Program. Good Bye!!!\n");
	return 0;
}
