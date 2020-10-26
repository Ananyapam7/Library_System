#include<stdio.h>
#include<string.h>
#include<stdlib.h>                  
#include<ctype.h>                   
#include<time.h>
#define MAX 100

struct book
{
    int id;
    char name[20];
    char author[20];
    int quantity;
    float price;  
};
// hello bro
// void add()
// {

// }

// void show()
// {

// }

// void remove()
// {

// }

// void search()
// {

// }

// void issue_book()
// {

// }

// void return_book()
// {

// }

int main()
{
    int INITIAL;
    printf("\t\t\t\t\t\tLibrary Setup\n");
    printf("\t\tYou need to add some preliminary books to your library to continue further\n\n");
    printf("How many books do you want to add: ");
    scanf("%d", &INITIAL);
    struct book arr_book[MAX];
    int i;

    for(i = 0; i < INITIAL; i++ )
    {
        printf("\nEnter details of book %d\n\n", i+1);

        printf("Enter ID: ");
        scanf("%d", &arr_book[i].id);

        printf("Enter Name: ");
        scanf("%s", arr_book[i].name);

        printf("Enter Author: ");
        scanf("%s", arr_book[i].author);

        printf("Enter Quantity: ");
        scanf("%d", &arr_book[i].quantity);

        printf("Enter Price: ");
        scanf("%f", &arr_book[i].price);
    }

    printf("\n");

    printf("ID\tName\tAuthor\tQuantity\tPrice\n");

    for(i = 0; i < INITIAL; i++ )
    {
        printf("%d\t%s\t%s\t%d\t\t%.2f\n",
        arr_book[i].id,arr_book[i].name,arr_book[i].author, arr_book[i].quantity, arr_book[i].price);
    }

    return 0;
}