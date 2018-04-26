#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// Define stotalInventements:
#define LINEAR	1
#define FORM	0;


// Constant TAX value:
const double TAX = 1.13;


// Item structure:
struct Item
{
	double price;
	int sku;
	int isTaxed;
	int quantity;
	int mQuantity;
	char name[21];
};


// Function Prototypes
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


// Function Prototypes
double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item, int linear);
void listItems(const struct Item item[], int noOfItems);
int locateItem(const struct Item item[], int num_Recor, int sku, int* index);


// Function ImplementotalInvention
int yes(void)
{
	char yinput = 0;
	int ret = 0;
	while (yinput != 'Y' && yinput != 'y' && yinput != 'N' && yinput != 'n')
	{
		scanf("%c", &yinput);
		flushKeyboard();
		if (yinput != 'Y' && yinput != 'y' && yinput != 'N' && yinput != 'n') {
			printf("Only (Y)es or (N)o are acceptable: ");
		}
	}
	if (yinput == 'Y' || yinput == 'y')
	{
		ret = 1;
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
		if (num == 1)
		{
			printf("List Items under construction!\n");
			pause();
			printf("\n");
		}
		else if (num == 2)
		{
			printf("Search Items under construction!\n");
			pause();
			printf("\n");
		}
		else if (num == 3)
		{
			printf("Checkout Item under construction!\n");
			pause();
			printf("\n");
		}
		else if (num == 4)
		{
			printf("Stock Item under construction!\n");
			pause();
			printf("\n");
		}
		else if (num == 5)
		{
			printf("Add/Update Item under construction!\n");
			pause();
			printf("\n");
		}
		else if (num == 6)
		{
			printf("Delete Item under construction!\n");
			pause();
			printf("\n");
		}
		else if (num == 7)
		{
			printf("Search by name under construction!\n");
			pause();
			printf("\n");
		}
		else if (num == 0)
		{
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
	if (grandTotal > 0)
	{
		printf("                                           Grand Total: |%12.2lf\n", grandTotal);
	}
}

void flushKeyboard(void)
{
	char NL;
	do
	{
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
	while (kyb_Input != '\n')
	{
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
	while (kyb_Input != '\n')
	{
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
	while (value < lowerLimit || value > upperLimit)
	{
		printf("Invalid value, %d < value < %d: ", lowerLimit, upperLimit);
		scanf("%d", &value);
	}
	return value;
}

double getDoubleLimited(double lowerLimit, double upperLimit)
{
	double value;
	scanf("%lf", &value);
	while (value <= lowerLimit || value >= upperLimit)
	{
		printf("Invalid value, %lf< value < %lf: ", lowerLimit, upperLimit);
		scanf("%lf", &value);
	}
	return value;
}



// Function ImplementotalInventions
double totalAfterTax(struct Item item)
{
	double totalInvent;
	totalInvent = item.price*item.quantity;
	if (item.isTaxed != 0)
		totalInvent = totalInvent*(1 + TAX);
	return totalInvent;
}

int isLowQuantity(struct Item item)
{
	int m = 0;
	if (item.quantity < item.mQuantity)
		m = 1;
	return m;
}

struct Item itemEntry(int sku)
{
	struct Item c_item;
	c_item.sku = sku;
	printf("        SKU: %d\n", sku);
	printf("       Name: ");
	scanf("%20[^\n]", c_item.name);
	flushKeyboard();
	printf("      Price: ");
	c_item.price = getDouble();
	printf("   Quantity: ");
	c_item.quantity = getInt();
	printf("Minimum Qty: ");
	c_item.mQuantity = getInt();
	printf("   Is Taxed: ");
	c_item.isTaxed = yes();
	return c_item;

};

void displayItem(struct Item item, int linear)
{
	if (linear == 1)
	{
		if (item.isTaxed == 1)
			printf("|%3d|%-20s|%8.2lf|%5s| %3d | %3d |%12.2lf|", item.sku, item.name, item.price, "Yes", item.quantity, item.mQuantity, totalAfterTax(item));
		else printf("|%3d|%-20s|%8.2lf|%5s| %3d | %3d |%12.2lf|", item.sku, item.name, item.price, "No", item.quantity, item.mQuantity, totalAfterTax(item));
		if (item.quantity < item.mQuantity)
			printf("***");
		printf("\n");
	}
	else if (item.quantity < item.mQuantity && item.isTaxed == 1)
	{
		printf("        SKU: %d\n", item.sku);
		printf("       Name: %s\n", item.name);
		printf("      Price: %.2lf\n", item.price);
		printf("   Quantity: %d\n", item.quantity);
		printf("Minimum Qty: %d\n", item.mQuantity);
		printf("   Is Taxed: %s\n", "Yes");
		printf("WARNING: Quantity low, please order ASAP!!!\n");
	}
	else
	{
		printf("        SKU: %d\n", item.sku);
		printf("       Name: %s\n", item.name);
		printf("      Price: %.2lf\n", item.price);
		printf("   Quantity: %d\n", item.quantity);
		printf("Minimum Qty: %d\n", item.mQuantity);
		printf("   Is Taxed: %s\n", "No");
	}
	return;
}

void listItems(const struct Item item[], int noOfItems)
{
	int i;
	double grandTotal = 0;
	printTitle();
	for (i = 0; i < noOfItems; i++)
	{
		printf("%-4d", i + 1);
		displayItem(item[i], LINEAR);
		grandTotal = grandTotal + totalAfterTax(item[i]);
	}
	printFooter(grandTotal);
	return;
}
int locateItem(const struct Item item[], int num_Recor, int sku, int* index)
{
	int i, m = 0;
	for (i = 0; i < num_Recor; i++)
	{
		if (item[i].sku == sku)
		{
			*index = i;
			m = 1;
		}
	}
	return m;
}