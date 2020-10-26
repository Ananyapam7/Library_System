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



// void add()
// {
//     printf("\nEnter details of book %d\n\n", i+1);

//     printf("Enter ID: ");
//     scanf("%d", &arr_book[i].id);

//     printf("Enter Name: ");
//     scanf("%s", arr_book[i].name);

//     printf("Enter Author: ");
//     scanf("%s", arr_book[i].author);

//     printf("Enter Quantity: ");
//     scanf("%d", &arr_book[i].quantity);

//     printf("Enter Price: ");
//     scanf("%f", &arr_book[i].price);
// }

// void show()
// {

// }

// void remove()
// {

// }

// void search()
// {
//     int attr,i;
//     printf("\nUsing what attribute do you want to search:\n");
//     printf("1. ID\n");
//     printf("2. Name\n");
//     printf("3. Author\n");
//     scanf("%d",&attr);
//     switch (attr)
//     {
//     case 1:
//         printf("Hello");
//         break;
    
//     default:
//         break;
//     }
//     // for(i=0;i<n;++i)
//     //     if([i]==srch)
//     //         break;
     
//     // if(i<n)
//     //     printf("Element found at index %d",i);
//     // else
//     //     printf("Element not found");
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
    int choice_menu;
    while(choice_menu!=7)
    {
    printf("Library Management System\n");
    printf("1. Add Books\n");
    printf("2. Remove Books\n");
    printf("3. Show Books\n");
    printf("4. Search Books\n");
    printf("5. Issue Books\n");
    printf("6. Return Books\n");
    printf("7. Return Books\n");
    printf("Enter your choice: ");
    scanf("%d", &choice_menu);
    switch (choice_menu)
    {
    case 1:
        i = INITIAL-1;
        char choice_add = 'y';
        while(choice_add == 'y')
        {
            i++;
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
            printf("Continue adding books? (y/n):");
            scanf("%s", &choice_add);
        }
        break;
    
    case 3:
        for(int j = 0; j < i; j++ )
        {
            printf("%d\t%s\t%s\t%d\t\t%.2f\n",
            arr_book[j].id,arr_book[j].name,arr_book[j].author, arr_book[j].quantity, arr_book[j].price);
        }
        break;
    
    default:
        break;
    }

    }
    return 0;
}