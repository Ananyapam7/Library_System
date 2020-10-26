#include<stdio.h>
#include<string.h>
#include<stdlib.h>                  
#include<ctype.h>                   
#include<time.h>
#define MAX 3

struct book
{
    int id;
    char name[20];
    char author[20];
    int quantity;
    float marks;
};

int main()
{
    // int MAX;
    printf("\t\t\t\t\t\tLibrary Setup\n");
    printf("\t\tYou need to add some preliminary books to your library to continue further\n\n");
    printf("How many books do you want to add\n");
    // scanf("%d", MAX);
    struct book arr_book[MAX];
    int i;

    for(i = 0; i < MAX; i++ )
    {
        printf("\nEnter details of book %d\n\n", i+1);

        printf("EnterID: ");
        scanf("%d", &arr_book[i].id);

        printf("Enter Name: ");
        scanf("%s", arr_book[i].name);

        printf("Enter Author: ");
        scanf("%s", arr_book[i].author);

        printf("Enter Quantity: ");
        scanf("%d", &arr_book[i].quantity);

        printf("Enter Price: ");
        scanf("%f", &arr_book[i].marks);
    }

    printf("\n");

    printf("ID\tName\tAuthor\tQuantity\tPrice\n");

    for(i = 0; i < MAX; i++ )
    {
        printf("%d\t%s\t%s\t%d\t\t%.2f\n",
        arr_book[i].id,arr_book[i].name,arr_book[i].author, arr_book[i].quantity, arr_book[i].marks);
    }

    return 0;
}