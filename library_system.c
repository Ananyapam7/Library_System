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
    int num_books; //the most important varaible, keeps track of the count of books

    for(num_books = 0; num_books < INITIAL; num_books++ )
    {
        printf("\nEnter details of book %d\n\n", num_books+1);

        printf("Enter ID: ");
        scanf("%d", &arr_book[num_books].id);

        printf("Enter Name: ");
        scanf("%s", arr_book[num_books].name);

        printf("Enter Author: ");
        scanf("%s", arr_book[num_books].author);

        printf("Enter Quantity: ");
        scanf("%d", &arr_book[num_books].quantity);

        printf("Enter Price: ");
        scanf("%f", &arr_book[num_books].price);
    }

    printf("\n");

    printf("ID\tName\tAuthor\tQuantity\tPrice\n");

    for(int num_show = 0; num_show < INITIAL; num_show++ )
    {
        printf("%d\t%s\t%s\t%d\t\t%.2f\n",
        arr_book[num_show].id,arr_book[num_show].name,arr_book[num_show].author, arr_book[num_show].quantity, arr_book[num_show].price);
    }
    int choice_menu;
    int issue_id;
    char choice_add;
    while(choice_menu!=7)
    {
    printf("\t\t\t\t\t\tLibrary Management System\n");
    printf("1. Add Books\n");
    printf("2. Remove Books\n");
    printf("3. Show Books\n");
    printf("4. Search Books\n");
    printf("5. Issue Books\n");
    printf("6. Return Books\n");
    printf("7. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice_menu);
    switch (choice_menu)
    {
    case 1:
        choice_add = 'y';
        while(choice_add == 'y')
        {
            num_books = num_books+1;
            printf("\nEnter details of book %d\n\n", num_books+1);
            printf("Enter ID: ");
            scanf("%d", &arr_book[num_books].id);
            printf("Enter Name: ");
            scanf("%s", arr_book[num_books].name);
            printf("Enter Author: ");
            scanf("%s", arr_book[num_books].author);
            printf("Enter Quantity: ");
            scanf("%d", &arr_book[num_books].quantity);
            printf("Enter Price: ");
            scanf("%f", &arr_book[num_books].price);
            // strcpy(arr_book[i].status,"Available");
            printf("Continue adding books? (y/n):");
            scanf("%s", &choice_add);
        }
        break;
    
    case 3:
        printf("ID\tName\tAuthor\tQuantity\tPrice\n");
        for(int j = 0; j < num_books; j++)
        {
            printf("%d\t%s\t%s\t%d\t\t%.2f\n",
            arr_book[j].id,arr_book[j].name,arr_book[j].author, arr_book[j].quantity, arr_book[j].price);
        }
        break;
    
    case 5:
        printf("Enter the ID of the book which you want to issue: ");
        scanf("%d",&issue_id);
        int k =0;
        int issue_found =0;
        while (arr_book[k].id == issue_id && arr_book[k].quantity>0)
        {
            arr_book[k].quantity--;
            printf("ID\tName\tAuthor\tQuantity\tPrice\n");
            printf("%d\t%s\t%s\t%d\t\t%.2f\n",
            arr_book[k].id,arr_book[k].name,arr_book[k].author, arr_book[k].quantity, arr_book[k].price);
            printf("Book Issued Successfully!\n");
            printf("Return date :");
            printf("%d",3*arr_book[k].quantity);
            printf(" days\n");
            issue_found =1;
            k++;    
        }
        if (issue_found ==0)
        {
            printf("Sorry book not found");
        }
    default:
        break;
    }

    }
    return 0;
}
