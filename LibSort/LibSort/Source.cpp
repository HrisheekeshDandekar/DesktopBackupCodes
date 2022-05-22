#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#pragma warning(disable : 4996)

struct Item
{
    char name[50];
    int id;
    int price;
};

struct Item item[50];

void AddDB();
void Display();
void Search();
void Update();
void Delete();
void Sort();

int maina()
{
    int choice;
    printf("Sorting is not working.\n");
    do
    {
        printf("1.Add record\n2.Display record\n3.Search record\n4.Delete record\n5.Update record\n6.Sort record\n7.Quit");
        printf("\n\nEnter choice: ");
        scanf("%d", &choice);

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
            //Sort();
            //break;

        default:
            break;
        }

    } while (choice != 7);

    return 0;

}

void AddDB()
{
    int n;
    printf("Enter number of items whose records you want to add: \n");
    scanf("%d", &n);
    //printf("Enter details of items\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter data for item \n");
        printf("\nEnter name of item: ");
        scanf("%[^\n]%*c",item[i].name);
        //fgets(item[i].name, 50, stdin);
        //getline(item[i].name, 50, stdin);
         
        printf("Enter Id of item: ");
        scanf("%d", &item[i].id);
        printf("Enter price of item: ");
        scanf("%d", &item[i].price);
        printf("\n");

    }
    printf("\n");
}

void Display()
{
    int count;
    printf("\nEnter number upto which position to display: ");
    scanf("%d", &count);


    printf("\nFollowing are the record items we have: ");
    for (int i = 0; i < count; i++)
    {
        if (item[i].id == 0)
        {
            i++;
            count++;
            printf("\n");
            printf("\n");
            printf("\nThe name of the item is %s\n", item[i].name);
            printf("The id of the item is %d\n", item[i].id);
            printf("The price of the item is %d\n", item[i].price);
            printf("\n");
        }
        else if (count == 0)
        {
            printf("The name of the item is %s\n", item[i + 1].name);
            printf("The id of the item is %d\n", item[i + 1].id);
            printf("The price of the item is %d\n", item[i + 1].price);
            printf("\n");
        }
        else
        {
            printf("The name of the item is %s\n", item[i].name);
            printf("The id of the item is %d\n", item[i].id);
            printf("The price of the item is %d\n", item[i].price);
            printf("\n");
        }
    }
    printf("\n");
}

void Search()
{
    int count;
    printf("\nEnter number of items to be searched: ");
    scanf("%d", &count);

    bool not_found = true;

    int searchid, i = 0;
    scanf("%d", &searchid);
    printf("\nEnter id of  item you want to search for:  %d\n", searchid);
    for (int i = 0; i < count; i++)
    {
        if (item[i].id == searchid)
        {
            printf("\nThe name of the item is %s\n", item[i].name);
            printf("\nThe id of the item is %d\n", item[i].id);
            printf("\nThe price of the item is %d\n", item[i].price);
            not_found = false;
        }
        /*else if (item[i].id == 0)
        {
            printf("\nRecord of item is deleted.");
        }*/
    }
    /* if (item[i].id == 0)
     {
         printf("We do not have this item.");
     }
     */
    if (not_found == true)
    {
        printf("\nWe do not have that item.");
    }

    printf("\n");
}

void Update()
{
    int count;
    printf("\nEnter number of items you want to update : ");
    scanf("%d", &count);

    int id1;
    printf("Enter new id of new item: ");
    scanf("%d", &id1);

    char name1[30];

    bool not_found = true;

    int searchid, i, price1;
    printf("\nEnter search id of element : ");
    scanf("%d", &searchid);
    printf("Enter id of item you want to update of: %d", searchid);

    for (i = 0; i < count; ++i)
    {
        if (item[i].id == searchid)
        {
            printf("\n");
            printf("\nThe current name of item is: %s", item[i].name);
            printf("\nThe current id of item is: %d", item[i].id);
            printf("\nThe price of current item is: %d", item[i].price);

            printf("\n");

            printf("\nEnter new name of item: %s", name1);
            scanf("%s", &name1);
            printf("\nEnter new id of item: %d", id1);
            scanf("%d", &id1);
            printf("\nEnter new price of item (old price %d) : ", item[i].price);
            scanf("%d\n", &price1);

            not_found = false;
        }
    }
    if (not_found == true)
    {
        printf("\nWe do not have that item.");
    }
}

void Delete()
{
    int count;
    printf("Enter total elements : ");
    scanf("%d", &count);

    int searchid, i = 0;
    printf("Enter id of item you want to delete: ");
    scanf("%d", &searchid);

    for (int i = 0; i < count; ++i)
    {
        if (item[i].id == searchid)
        {
            printf("Item is deleted.\n");
        }
        else {
            printf("We do not have that item.");
        }
    }
}

/* Bubble sort
void Sort()
{
    int count;
    int n;
    while (count < n - 1)
    {
        for (int i = 0; i < n - count - 1; i++)
        {
            if (item[i].id > item[i + 1].id)
            {
                Item temp = item[i];
                item[i] = item[i + 1];
                item[i + 1] = temp;

            }
        }
        count++;
    }
    printf("\n Sorted items are: ");
    Display();
}
*/