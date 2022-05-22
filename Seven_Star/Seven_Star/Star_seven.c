#include <stdlib.h>
#include <stdio.h>

struct Item
{
	char name[10];
	int id;
	int price;
};

void AddDB(int n) {
	printf("Enter number of items whose records you want to add: \n");
	scanf("%d", &n);
	printf("Enter details of items\n");
	for (int i = 0; i < n; i++)
	{
		printf("Enter data for item %d\n", n + 1);
		printf("Enter name of item: ");
		scanf("%s", item[i].name);
		printf("Enter Id of item: ");
		scanf("%d", item[i].id);
		printf("Enter price of item: ");
		scanf("%d", item[i].price);
		printf("\n");

	}
	printf("\n");
}

void Display(int count) {
	printf("Following are the record items we have: ");
	for (int i = 0; i < count; i++)
	{
		if (Item[i].id == 0)
		{
			i++;
			count++;
			printf("\n");
			printf("The name of the item is %s\n", Item[i].name);
			printf("The id of the item is %d\n", Item[i].id);
			printf("The price of the item is %f\n", Item[i].price);
			printf("\n");
		}
		else {
			if (count == 0)
			{
				printf("The name of the item is %s\n", Item[i + 1].name);
				printf("The id of the item is %d\n", Item[i + 1].id);
				printf("The price of the item is %f\n", Item[i + 1].price);
				printf("\n");
			}
		}

		else {
		printf("The name of the item is %s\n", Item[i].name);
		printf("The id of the item is %d\n", Item[i].id);
		printf("The price of the item is %f\n", Item[i].price);
		printf("\n");
		}

	}
	printf("\n");
}

void Search(int count) {
	int searchid, i = 0;
	scanf("%d", &searchid);
	printf("Enter id of  item you want to search for:  %d", searchid);
	printf("\n");
	for (int i = 0; i < count; i++)
	{
		if (Item[i].id == searchid)
		{
			printf("The name of the item is %s\n", Item[i].name);
			printf("The id of the item is %d\n", Item[i].id);
			printf("The price of the item is %f\n", Item[i].price);
		}

		else if (Item[i].id == 0)
		{
			printf("Record of item is deleted.");
		}
		else if (i == count)
		{
			printf("We do not have that item.");
		}
	}

	printf("\n");
}

void Update(char name1, int id1, int price1, int count) {
	int searchid, i = 0;
	scanf("%d", &searchid);
	printf("Enter id of item you want to update of: %d", searchid);
	for (int i = 0; i < count; ++i)
	{
		if (Item[i].id == searchid)
		{
			printf("\n");
			printf("The current name of item is: %s", &Item[i].name);
			printf("The current id of item is: %d", &Item[i].id);
			printf("The price of current item is: %d", &item[i].price);

			printf("\n");

			printf("Enter new name of item: %s", name1);
			scanf("%s", &name1);
			printf("Enter new id of item: %d", id1);
			scanf("%s", &id1);
			printf("Enter new name of item: %d", price1);
			scanf("%s", &price1);

			printf("\n");

			break;

		}
	}
	if (i == count)
	{
		printf("That item do no longer exist.");
	}
}

void Delete(int count) {
	int searcid, i = 0;
	printf("Enter id of item you want to delete: %d", searchid);
	scanf("%d", &searchid);

	for (int i = 0; i < count; ++i)
	{
		if (Item[i].id == searchid)
		{
			printf("Item is deleted.");
		}
		else {
			printf("We do not have that item.");
		}
	}
}

int main()
{
	int choice;
	struct Item item[5];
	printf("Enter choice: %d", choice);
	scanf("%d", &choice);

	do {
		printf("1.Add record\n2.Display record\n3.Search record\n4.Delete record\n5.Update record\n6.Sort record\n7.Quit");
		switch (choice)
		{
		case 1:
			AddDB();
			break;

		case 2:
			Display();
			break;

		case 3:
			Search();
			break;

		case 4:
			Delete();
			break;

		case 5:
			Update();
			break;

		case 6:
			Sort();
			break;

		default:
			break;
		}
		while (choice != 7)
	}
	return 0;
}