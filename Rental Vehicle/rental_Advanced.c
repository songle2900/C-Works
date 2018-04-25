#include <stdio.h>

#define distRate1 0.69		// Rate per Kilometer from 0km to 100km (inclusive)
#define distRate2 0.49		// Rate per Kilometer above 100km

// Structure Declaration for Vehicle Rentals
struct Rental
{
	int id;					// ID of the Rental Vehicle
	double baseDay;			// Daily Base Price
	double earnings;		// Total earnings from this rental
};

/* Prototype functions addPositive, taxCalc & subtractPositive */

/* Implement Function addpositive Here */
double addPositive(double amount, double newAmount);
double addPositive(double amount, double newAmount)
{
	if (newAmount > 0)
		amount += newAmount;
	return amount;
}

/* Implement Function taxCalc Here */
double taxCalc(double price, double rate);
double taxCalc(double price, double rate)
{
	double taxes = 0;
	taxes = price * (rate/100);
	return taxes;
}

/* Implement Function subtractPositive Here */
double subtractPositive(double amount, double newAmount);
double subtractPositive(double amount, double newAmount)
{
	if (newAmount > 0)
		amount -= newAmount;
	return amount;
}

/* main program */
int main()
{
	const int noVehicles = 3;		// Number of Vehicles [Changed to 3]
	int option;					// Variable to store option selected
	int flag;					// Flag to support vehicle ID find
	int tempID;					// To hold user input for vehicle ID
	int i = 0;					// Variable for "for-loop" counters

	// Initialize the struct Vehicle Rental [ New addition for 3 Rentals]
	struct Rental vRent[] = { {123, 9.95, 0 },{124, 19.95, 0 }, {125, 29.95, 0 } };

	double taxRate = 14;		// Tax rate is 14%
	double discount = 5;		// Discount amount for rentals (in CAD)


	/* Declar Your Variables Here */
	int duration;
	double basePrice,kmCost;
	double charge;
	double km;
	char applyDiscount;

	printf("***** Rental Vehicle Management App *****\n\n");

	do
	{
		// Display the option list
		printf("1.) Rental Status \n");
		printf("2.) Apply Charges \n");
		printf("3.) Apply Taxes to All Rentals \n");
		printf("4.) Apply Gift Card \n");
		printf("0.) Log out \n\n");
		printf("Please enter an option to continue: ");

		scanf("%d", &option);

		switch (option)
		{
		case 0: // Exit the program
			break;

		case 1: // Rental Vehicle Status
			printf("\n-- Rental Vehicle Status --\n\n");
			printf("ID#      Earnings\n");
			printf("-------- ----------\n");

			// Use "%8d %10.2lf" formatting to display ID and Earnings for each rental
			for (i = 0; i < noVehicles; i++)
			{
				printf("%8d", vRent[i].id);
				printf("%10.2lf\n", vRent[i].earnings);
			}
			printf("\n");
			break;

		case 2: // Caluculate Rental Charges
			flag = -1;
			printf("\n-- Rental Charges --\n\n");
			printf("Enter vehicle ID: ");
			scanf("%d", &tempID);

			// Finding the correct vehicle index
			for (i = 0; i < noVehicles && flag == -1; i++)
			{
				if (tempID == vRent[i].id) 
				{
					flag = i;
				}
			}

			if (flag != -1)
			{
				// Capture #days for the rental from the user input
				printf("Enter Rental Period (in Days): ");
				scanf("%d",&duration);

				// Calculate the base price (baseDay * Days)
				basePrice = vRent[flag].baseDay*duration;

				// Calculate cost for Kilometers driven
				printf("Enter kilometers driven: ");
				scanf("%lf", &km);
				if (km <= 100)
					kmCost = km * distRate1;
				else kmCost = 100 * distRate1+(km-100) * distRate2;

				// Add base Price and cost for kilometer driven in to a new variable "charge"
				charge = basePrice + kmCost;

				/* Call addPositive function with current earnings for the rental and
				charge(calculated above) as arguments and assign the returned
				result back to earnings
				*/
				vRent[flag].earnings = addPositive(vRent[flag].earnings, charge);

				// Apply Discount with a prompt for Y or N
				printf("Apply Discount: ");
				scanf("%c", &applyDiscount);
				if (applyDiscount == 'y' || applyDiscount == 'Y')
					vRent[flag].earnings = subtractPositive(vRent[flag].earnings, discount);

				// Display Base Charge, cost for km and the Total
				printf("\nBase   kmCost DiscStatus Total\n");
				printf("====== ====== ========== ======\n");;
				// Use "%6.2lf %6.2lf %10c %6.2lf" formatting inside a printf statement
				printf("%6.2lf %6.2lf %6.2lf\n\n", basePrice, kmCost, applyDiscount, vRent[flag].earnings);
			}
			else
			{
				printf("ERROR: Vehicle ID does not exist. \n\n");
			}

			break;

		case 3: // Apply Taxes to all Earnings
			printf("\n-- Apply Taxes To all Accounts--\n\n");

			printf("ID#      Earnings   Taxes\n");
			printf("-------- ---------- ------\n");

			for (i = 0; i < noVehicles && flag == -1; i++)
				if 

			// Iterate over all Rentals. For each rental, calculate the taxes by calling taxCalc 
			// by passing current earnings and tax rate
			// Then call addPositive with current earnings and the taxes returned from taxCalc function
			// Then use "%8d %10.2lf %6.2lf" formatting -to display ID, Earnings and taxes for each rental

			break;

		case 4: // Apply Gift Card
			flag = -1;
			printf("\n-- Apply Gift Card --\n\n");
			printf("Enter vehicle ID: ");
			scanf("%d", &tempID);


			// Finding the correct vehicle index
			for (i = 0; i < noVehicles && flag == -1; i++) {
				if (tempID == vRent[i].id) {
					flag = i;
				}
			}
			if (flag != -1) {

				// Capture Gift card amount


				/* call function subtractPositive with current earnings for the rental and Gift card
				amount as arguments and assign the returned result back to earnings
				*/


			}
			else {
				printf("ERROR: Vehicle ID does not exist.\n\n");
			}

			printf("\n");

			break;

		default:
			printf("Error: Please enter a valid option to continue \n\n");
			break;
		}
	} while (option != 0);

	return 0;
}
