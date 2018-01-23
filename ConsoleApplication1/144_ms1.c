#include <stdio.h>
// tools
void welcome(void);
void printTitle(void);
void printFooter(double grandTotal);
void flushKeyboard(void);
void pause(void);
int getInt(void);
double getDouble(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDoubleLimited(double lowerLimit, double upperLimit);
// app interface
int yes(void);
void GroceryInventorySystem(void);
int menu(void);


int yes(void)
{
	char yinput = 'a';
	int ret;
	while (yinput != 'Y' && yinput != 'y' && yinput != 'N' && yinput != 'n')
	{
		scanf("%c", &yinput);
		flushKeyboard();
		if (yinput == 'Y' || yinput == 'y') {
			ret = 1;
		}
		else if (yinput == 'N' || yinput == 'n') {
			ret = 0;
		}
		else
			printf("Only (Y)es or (N)o are acceptable: ");
	}
	return ret;
}

int menu(void)
{
	int opt;
	printf("1- List all items\n");
	printf("2- Search by SKU\n");
	printf("3- Checkout an item\n");
	printf("4- Stock an item\n");
	printf("5- Add new item or update item\n");
	printf("6- delete item\n");
	printf("7- Search by name\n");
	printf("0- Exit program\n");
	printf("> ");
	opt = getIntLimited(0, 7);
	return opt;
}
void GroceryInventorySystem(void)
{
	int num = 0;
	int done = 0;
	welcome();
	do {
		num = menu();
		if (num == 1) {
			printf("List Items under construction!\n");
			pause();
			printf("\n");
		}
		else if (num == 2) {
			printf("Search Items under construction!\n");
			pause();
			printf("\n");
		}
		else if (num == 3) {
			printf("Checkout Item under construction!\n");
			pause();
			printf("\n");
		}
		else if (num == 4) {
			printf("Stock Item under construction!\n");
			pause();
			printf("\n");
		}
		else if (num == 5) {
			printf("Add/Update Item under construction!\n");
			pause();
			printf("\n");
		}
		else if (num == 6) {
			printf("Delete Item under construction!\n");
			pause();
			printf("\n");
		}
		else if (num == 7) {
			printf("Search by name under construction!\n");
			pause();
			printf("\n");
		}
		else if (num == 0) {
			printf("Exit the program? (Y)es/(N)o : ");
			done = yes();
		}
	} while (done != 1);
}


void welcome(void)
{
	printf("---=== Grocery Inventory System ===---\n\n");
}
void printTitle(void)
{
	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
}
void printFooter(double grandTotal)
{
	printf("--------------------------------------------------------+----------------\n");
	if (grandTotal > 0) {
		printf("                                           Grand Total: |%12.2lf\n", grandTotal);
	}
}
void flushKeyboard(void)
{
	char NL;
	do {
		NL = getchar();
	} while (NL != '\n');
}

void pause(void)
{
	printf("Press <ENTER> to continue...");
	flushKeyboard();
}

int getInt(void)
{
	int no_Input;
	char kyb_Input;
	scanf("%d%c", &no_Input, &kyb_Input);
	while (kyb_Input != '\n') {
		flushKeyboard();
		printf("Invalid integer, please try again: ");
		scanf("%d%c", &no_Input, &kyb_Input);
	}
	return no_Input;
}

double getDouble(void)
{
	double no_Input;
	char kyb_Input;
	scanf("%lf%c", &no_Input, &kyb_Input);
	while (kyb_Input != '\n') {
		flushKeyboard();
		printf("Invalid number, please try again: ");
		scanf("%lf%c", &no_Input, &kyb_Input);
	}
	return no_Input;
}

int getIntLimited(int lowerLimit, int upperLimit)
{
	int value;
	scanf("%d", &value);
	while (value < lowerLimit || value > upperLimit) {
		printf("Invalid value, %d < value < %d: ", lowerLimit, upperLimit);
		scanf("%d", &value);
	}
	return value;
}

double getDoubleLimited(double lowerLimit, double upperLimit)
{
	double value;
	scanf("%lf", &value);
	while (value <= lowerLimit || value >= upperLimit) {
		printf("Invalid value, %lf< value < %lf: ", lowerLimit, upperLimit);
		scanf("%lf", &value);
	}
	return value;
}














/* output

---=== Grocery Inventory System ===---

listing header and footer with grand total:
Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn
----+---+--------------------+--------+-----+-----+-----+------------|---
--------------------------------------------------------+----------------
Grand Total: |     1234.57
listing header and footer without grand total:
Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn
----+---+--------------------+--------+-----+-----+-----+------------|---
--------------------------------------------------------+----------------
Press <ENTER> to continue...
Enter an integer: abc
Invalid integer, please try again: 10abc
Invalid integer, please try again: 10
You entered: 10
Enter an integer between 10 and 20: 9
Invalid value, 10 < value < 20: 21
Invalid value, 10 < value < 20: 15
Your entered 15
Enter a floating point number: abc
Invalid number, please try again: 2.3abc
Invalid number, please try again: 2.3
You entered: 2.30
Enter a floating point number between 10.00 and 20.00: 9.99
Invalid value, 10.000000< value < 20.000000: 20.1
Invalid value, 10.000000< value < 20.000000: 15.05
You entered: 15.05
End of tester program for milestone one!

*/
