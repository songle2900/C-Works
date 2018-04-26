#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


// Define statements:
#define LINEAR			1
#define FORM			0
#define STOCK			1
#define	CHECKOUT		0
#define MAX_ITEM_NO		21
#define MAX_QTY			999
#define SKU_MAX			999
#define	SKU_MIN			100

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

double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item, int linear);
void listItems(const struct Item item[], int noOfItems);
int locateItem(const struct Item item[], int num_Recor, int sku, int* index);

void search(const struct Item item[], int NoOfRecs);
void updateItem(struct Item* itemptr);
void addItem(struct Item item[], int *NoOfRecs, int sku);
void addOrUpdateItem(struct Item item[], int* NoOfRecs);
void adjustQuantity(struct Item item[], int NoOfRecs, int stock);

int yes(void)
{
	char yinput;
	int ret = 0;
	scanf("%c", &yinput);
	flushKeyboard();
	while (yinput != 'Y' && yinput != 'y' && yinput != 'N' && yinput != 'n')
	{
		printf("Only (Y)es or (N)o are acceptable: ");
		scanf("%c", &yinput);
		flushKeyboard();
	}
	if (yinput == 'Y' || yinput == 'y')
		ret = 1;
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
		scanf("%d%c", &no_Input, &kyb_Input);
		flushKeyboard();
		if (kyb_Input != '\n')
			printf("Invalid integer, please try again: ");
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
		scanf("%lf%c", &no_Input, &kyb_Input);
		if (kyb_Input != '\n')
		{
			flushKeyboard();
			printf("Invalid number, please try again: ");
		}
	}
	return no_Input;
}

int getIntLimited(int lowerLimit, int upperLimit)
{
	int value;
	value = getInt();
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
	value = getDouble();
	while (value < lowerLimit || value > upperLimit)
	{
		printf("Invalid value, %lf< value < %lf: ", lowerLimit, upperLimit);
		scanf("%lf", &value);
	}
	return value;
}


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
	if (linear == 0) {

		printf("        SKU: %d\n", item.sku);
		printf("       Name: %s\n", item.name);
		printf("      Price: %.2lf\n", item.price);
		printf("   Quantity: %d\n", item.quantity);
		printf("Minimum Qty: %d\n", item.mQuantity);
		if (item.isTaxed != 0) {
			printf("   Is Taxed: %s\n", "Yes");
		}
		else {
			printf("   Is Taxed: %s\n", "No");
		}
		if (item.quantity <= item.mQuantity)
		{
			printf("WARNING: Quantity low, please order ASAP!!!\n");
		}

	}
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
}

int locateItem(const struct Item item[], int num_Recor, int sku, int* index)
{
	int i;
	for (i = 0; i < num_Recor; i++)
	{
		if (item[i].sku == sku)
		{
			*index = i;
			return 1;
		}
	}
	return 0;
}

void search(const struct Item item[], int NoOfRecs) {
	int ctr;
	int i;
	int i_Locate;
	printf("Please enter the SKU: ");
	ctr = getIntLimited(SKU_MIN, SKU_MAX);
	i_Locate = locateItem(item, NoOfRecs, ctr, &i);
	if (i_Locate == 1) {
		displayItem(item[i], FORM);
	}
	else
		printf("Item not found!\n");
}


void updateItem(struct Item* itemptr) 
{
	int y_input;
	struct Item item;
	printf("Enter new data:\n");
	item = itemEntry((*itemptr).sku);
	printf("Overwrite old data? (Y)es/(N)o: ");
	y_input = yes();
	if (y_input == 1)
	{
		*itemptr = item;
		printf("--== Updated! ==--\n");
	}
	else printf("--== Aborted! ==--\n");
}


void addItem(struct Item item[], int *NoOfRecs, int sku) {
	struct Item insItem;
	int y_input;
	if (*NoOfRecs == MAX_ITEM_NO) {
		printf("Can not add new item; Storage Full!\n");
	}
	else {
		insItem = itemEntry(sku);
		printf("Add Item? (Y)es/(N)o: ");
		y_input = yes();
		if (y_input == 1) {
			item[*NoOfRecs] = insItem;
			item[*NoOfRecs].isTaxed = insItem.isTaxed;
			(*NoOfRecs)++;
			printf("--== Added! ==--\n");
		}
		else
			printf("--== Aborted! ==--\n");
	}
}


void addOrUpdateItem(struct Item item[], int* NoOfRecs) {
	int new_sku;
	int i;
	int j;
	int y_input;
	printf("Please enter the SKU: ");
	new_sku = getIntLimited(SKU_MIN, SKU_MAX);
	j = locateItem(item, *NoOfRecs, new_sku, &i);
	if (j == 1) {
		displayItem(item[i], FORM);
		printf("Item already exists, Update? (Y)es/(N)o: ");
		y_input = yes();
		if (y_input == 1) {
			updateItem(&item[i]);
		}
		else {
			printf("--== Aborted! ==--\n");
		}
	}
	else addItem(item, NoOfRecs, new_sku);
}


void adjustQuantity(struct Item item[], int NoOfRecs, int stock) {
	int SKU, num, num2;
	int i;
	printf("Please enter the SKU: ");
	SKU = getIntLimited(SKU_MIN, SKU_MAX);
	num = locateItem(item, NoOfRecs, SKU, &i);
	if (num == 0)
		printf("SKU not found in storage!\n");
	else {
		displayItem(item[i], FORM);
		printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ", stock ? "to stock" : "to checkout", stock ? (MAX_QTY - item[i].quantity) : item[i].quantity);
		num2 = getIntLimited(0, stock ? (MAX_QTY - item[i].quantity) : item[i].quantity);
		if (num2 == 0)
			printf("--== Aborted! ==--\n");
		else {
			if (stock == STOCK) {
				item[i].quantity = item[i].quantity + num2;
				printf("--== Stocked! ==--\n");
			}
			else if (stock == CHECKOUT) {
				item[i].quantity = item[i].quantity - num2;
				printf("--== Checked out! ==--\n");
				if (item[i].quantity <= item[i].mQuantity)
					printf("Quantity is low, please reorder ASAP!!!\n");
			}
		}
	}
}