#include <stdio.h>

#define distRate1 0.69
#define distRate2 0.49

struct Rental
{
	int id;
	double baseDay;
	double earnings;
};

double addPositive(double amount, double newAmount);
double addPositive(double amount, double newAmount)
{
	if (newAmount > 0)
		amount += newAmount;
	return amount;
}

int main()
{
	const int numOfcar = 2;
	int option;
	int flag;
	int tID;
	int i = 0;

	struct Rental vRent[] = { {123, 9.95, 0 },{124, 19.95, 0 } };

	int duration;
	double basePrice,kmCost;
	double charge;
	double km;

	printf("***** Rental Vehicle Management App *****\n\n");

	do
	{
		printf("1.) Rental Status \n");
		printf("2.) Apply Charges \n");
		printf("0.) Log out \n\n");
		printf("Please enter an option to continue: ");
		scanf("%d", &option);

		switch (option)
		{
		case 0:
			break;
		
		case 1:
			printf("\n-- Rental Vehicle Status --\n\n");
			printf("ID#      Earnings\n");
			printf("-------- ----------\n");
			
			for (i = 0; i < numOfcar; i++)
			{
				printf("%8d", vRent[i].id);
				printf("%10.2lf\n", vRent[i].earnings);
			}
			printf("\n");
			break;
		
		case 2:
			flag = -1;
			printf("\n-- Rental Charges --\n\n");
			printf("Enter vehicle ID: ");
			scanf("%d", &tID);

			for (i = 0; i < numOfcar && flag == -1; i++)
			{
				if (tID == vRent[i].id) 
				{
					flag = i;
				}
			}

			if (flag != -1)
			{
				printf("Enter Rental Period (in Days): ");
				scanf("%d",&duration);

				basePrice = vRent[flag].baseDay*duration;

				printf("Enter kilometers driven: ");
				scanf("%lf", &km);
				if (km <= 100)
					kmCost = km * distRate1;
				else kmCost = 100 * distRate1+(km-100) * distRate2;

				charge = basePrice + kmCost;

				vRent[flag].earnings = addPositive(vRent[flag].earnings, charge);
				
				printf("\nBase   kmCost Total\n");
				printf("====== ====== ======\n");

				printf("%6.2lf %6.2lf %6.2lf\n\n", basePrice, kmCost, vRent[flag].earnings);
			}
			else
			{
				printf("ERROR: Vehicle ID does not exist. \n\n");
			}

			break;

		default:
			printf("Error: Please enter a valid option to continue \n\n");
			break;
		}
	} while (option != 0);

	return 0;
}
