#include <stdio.h>

#define MAX_BOOKS			10
#define MAX_TITLE_SIZE		20

// Struct for Book
struct Book
{
	int _isbn;
	float _price;
	int year;
	char _title[MAX_TITLE_SIZE];
	int qty;
};

// Prototype Functions
void menu();
void displayInventory(const struct Book book[], const int size);
void searchInventory(const struct Book book[], const int isbn, const int size);
void addBook(struct Book book[], int *size);
void checkPrice(const struct Book book[], const int size);


// Main fuction
int main(void)
{
	struct Book book[MAX_BOOKS];	// An array of Book representing the inventory
	int size = 0;					// Number of books in the inventory. The inventory is initially empty.
	int i = 0;

	printf("Welcome to the Book Store\n");
	printf("=========================\n");

	do
	{
		menu();
		scanf("%d", &i);
		while (i < 0 || i > 3)
		{
			printf("Invalid input, try again: \n");
			menu();
			scanf("%d", &i);
		}
		if (i == 0)
			printf("Goobye!\n");
		else if (i == 1)
			displayInventory(book, size);
		else if (i == 2)
			addBook(book, &size);
		else
			checkPrice(book, size);
	} while (i != 0);
}

// Fuction implementations
void menu()
{
	printf("Please select from the following options:\n");
	printf("1) Display the inventory.\n");
	printf("2) Add a book to the inventory.\n");
	printf("3) Check price.\n");
	printf("0) Exit.\n\n");
	printf("Select: ");
}

void displayInventory(const struct Book book[], const int size)
{
	if (size == 0)
	{
		printf("The inventory is empty!\n");
		printf("===================================================\n\n");
	}
	else
	{
		printf("===================================================\n");
		printf("ISBN      Title               Year Price  Quantity\n");
		printf("---------+-------------------+----+-------+--------\n");
		for (int i = 0; i < size; i++)
			printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", book[i]._isbn, book[i]._title, book[i].year, book[i]._price, book[i].qty);
		printf("===================================================\n\n");
	}
}

void searchInventory(const struct Book book[], const int isbn, const int size)
{
	printf("Not impltemented.\n");
}

void addBook(struct Book book[], int *size)
{
	if (*size == MAX_BOOKS)
	{
		printf("The inventory is full.\n");
	}
	else
	{
		printf("ISBN: ");
		scanf("%d", &book[*size]._isbn);
		printf("Title: ");
		scanf("%*c%[^\n]", book[*size]._title);
		printf("Year: ");
		scanf("%d", &book[*size].year);
		printf("%Price: ");
		scanf("%f", &book[*size]._price);
		printf("Quantity: ");
		scanf("%d", &book[*size].qty);
		printf("The book is successfully added to the inventory.\n\n");
		*size = *size + 1;
	}
}

void checkPrice(const struct Book book[], const int size)
{
	printf("Not impltemented.\n");
}
