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

int elements_in_DB = -1;

int main()
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
            Sort();
            break;

        default:
            break;
        }

    } while (choice != 7);

    return 0;

}

void AddDB()
{
    int n;
    char temp[50];

    printf("\nEnter number of items whose records you want to add: \n");
    scanf("%d", &n);
    //printf("Enter details of items\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter data for item \n");
        printf("\nEnter name of item: ");
        while (getchar() != '\n');
        scanf("%[^\n]s", &item[elements_in_DB + 1]);
        printf("Enter Id of item: ");
        scanf("%d", &item[elements_in_DB+1].id);
        printf("Enter price of item: ");
        scanf("%d", &item[elements_in_DB + 1].price);
        printf("\n");
        elements_in_DB++;
    }
    printf("\n");
}

void Display()
{
    int count = 0, i = 0;
    printf("\ntotal elements in Database = %d ",elements_in_DB+1);



    printf("\nFollowing are the record items we have: ");

    while (count != (elements_in_DB+1))
    {
        if (item[count].id != -1)
        {
            count++;
            printf("\n");
            printf("\n");
            printf("\nThe name of the item is %s\n", item[i].name);
            printf("The id of the item is %d\n", item[i].id);
            printf("The price of the item is %d\n", item[i].price);
            printf("\n");
        }
        i++;

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

    }

    if (not_found == true)
    {
        printf("\nWe do not have that item.");
    }

    printf("\n");
}

void Update()
{
    int count;
    int searchid, i;

    printf("Enter id of item to be updated : ");
    scanf("%d", &searchid);


    bool not_found = true;

    for (i = 0; i < elements_in_DB + 1; i++)
    {
        if (searchid == item[i].id)
        {
            not_found = false;
            break;
        }

    }
    
     if(not_found == true)
         printf("\nElement not in our database !!!\n\n");

     if (not_found == false)
     {
         int newId, newPrice;
         char new_name[50];

         while (getchar() != '\n');
         printf("\nEnter New name : ");
         scanf("%[^\n]s", &new_name);

         printf("\nEnter New Id : ");
         scanf("%d", &newId);

         printf("\nEnter New price : ");
         scanf("%d", &newPrice);

         //Assigning new values to element
         item[i].id = newId;
         item[i].price = newPrice;
         strcpy(item[i].name, new_name);
     }

}

void Delete()
{
    int count = elements_in_DB;
    printf("\nElements in Datta Base = %d", elements_in_DB);

    int searchid, i = 0;
    printf("\nEnter id of item you want to delete: ");
    scanf("%d", &searchid);

    bool delete_sucess = false;

    for (int i = 0; i < count+1; ++i)
    {
        if (item[i].id == searchid)
        {
            printf("\nItem is deleted.\n");

            item[i].id = item[elements_in_DB].id;
            item[i].price = item[elements_in_DB].price;
            strcpy(item[i].name, item[elements_in_DB].name);

            //Clearing out last element
            item[elements_in_DB].id = -1;
            item[elements_in_DB].price = -1;
            item[elements_in_DB].name[0] = '\0';

            elements_in_DB--;
            delete_sucess = true;

            break;
        }
       
    }
    if (delete_sucess == false)
        printf("\nError (Item Not found)\n");
    
}

void Sort()
{
    int temp_id, temp_price;
    char temp_name[50];

    for (int i = 0; i < elements_in_DB + 1; i++)
        for (int j = 0; j < elements_in_DB - i; j++)
            if (item[j].id > item[j + 1].id)
            {
                //Saving values in temp variables
                temp_id = item[j].id;
                temp_price = item[j].price;
                strcpy(temp_name, item[j].name);

                //Assigning second to first
                item[j].id = item[j + 1].id;
                item[j].price = item[j + 1].price;
                strcpy(item[j].name, item[j + 1].name);

                //Assigning temp to second
                item[j+1].id = temp_id;
                item[j+1].price = temp_price;
                strcpy(item[j+1].name, temp_name);
            }
        

    //Displaying sorted elements
    printf("\n Sorted items are: \n");
    Display();
}
