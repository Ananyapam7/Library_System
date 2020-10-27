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
    int choice_menu; // the choices in the menu screen
    char choice_add; // the choice variable to continue adding books, takes values y/n
    int choice_search; // the choice against which attribute the user wants to search the books, ID, name and author
    int issue_id; // user input of the id of the book which he wants to issue
    int return_id; // user input of the id of the book which he wants to return
    int remove_id; // user input of the id of the book which he wants to remove
    int k =0; // the variable used throughout to iterate over the structure array
    int found =0; // the variable used throughout to indicate that a book is present or not
    while(choice_menu!=7)
    {
    printf("\t\t\t\t\t\tLibrary Management System\n");
    printf("1. Add Books\n");
    printf("2. Remove Book\n");
    printf("3. Show Books\n");
    printf("4. Search Book\n");
    printf("5. Issue Book\n");
    printf("6. Return Book\n");
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
    
    case 2:
        printf("Enter ID of the book you want to remove: ");
        scanf("%d", &remove_id);
        found = 0;
        for (k=0;k<num_books;k++)
        {
        if (remove_id == arr_book[k].id)
            {
                printf("Found the book you wanted to remove\n\n");
                printf("ID\tName\tAuthor\tQuantity\tPrice\n");
                printf("%d\t%s\t%s\t%d\t\t%.2f\n",
                arr_book[k].id,arr_book[k].name,arr_book[k].author, arr_book[k].quantity, arr_book[k].price);
                for (int pos = k; pos < num_books - 1; pos++)
                {
                    arr_book[pos] = arr_book[pos+1];
                }
                printf("\nBook removed Succesfully \n!");
                num_books--;
                found =1;
                k++;
            }
        if (found ==0)
        {
            printf("Sorry book not found\n");
        }
        }


    case 3:
        printf("ID\tName\tAuthor\tQuantity\tPrice\n");
        for(int j = 0; j < num_books; j++)
        {
            printf("%d\t%s\t%s\t%d\t\t%.2f\n",
            arr_book[j].id,arr_book[j].name,arr_book[j].author, arr_book[j].quantity, arr_book[j].price);
        }
        break;
    
    case 4:
        printf("Enter attribute by which you want to search books\n");
        printf("1. ID\n");
        printf("2. Name\n");
        printf("3. Author\n");
        scanf("%d", &choice_search);
        if (choice_search ==1)
        {
            found =0;
            int search_id;
            printf("Enter ID :");
            scanf("%d", &search_id);
            for (k=0;k<num_books;k++)
            {
            if (arr_book[k].id == search_id && arr_book[k].quantity>0)
            {
                printf("Found the book you were looking for!\n\n");
                printf("ID\tName\tAuthor\tQuantity\tPrice\n");
                printf("%d\t%s\t%s\t%d\t\t%.2f\n",
                arr_book[k].id,arr_book[k].name,arr_book[k].author, arr_book[k].quantity, arr_book[k].price);
                found =1;    
            }
            }
            if (found ==0)
            {
                printf("Sorry book not found");
            }
        }
        else if(choice_search ==2)
        {
            char search_name[20];
            printf("Enter the name of the book you were looking for :");
            scanf("%s", search_name);
            found = 0;
            for (k=0;k<num_books;k++)
            {
            if (strcmp(search_name, arr_book[k].name)==0 && arr_book[k].quantity>0)
            {
                printf("Found the book you were looking for!\n\n");
                printf("ID\tName\tAuthor\tQuantity\tPrice\n");
                printf("%d\t%s\t%s\t%d\t\t%.2f\n",
                arr_book[k].id,arr_book[k].name,arr_book[k].author, arr_book[k].quantity, arr_book[k].price);
                found =1;
            }
            }
            if (found ==0)
            {
                printf("Sorry book not found\n");
            }
        }

        else if(choice_search ==3)
        {
            char search_author[20];
            printf("Enter the name of the book you were looking for :");
            scanf("%s", search_author);
            found = 0;
            for (k=0;k<num_books;k++)
            {
            if (strcmp(search_author, arr_book[k].author)==0 && arr_book[k].quantity>0)
            {
                printf("Found the book you were looking for!\n\n");
                printf("ID\tName\tAuthor\tQuantity\tPrice\n");
                printf("%d\t%s\t%s\t%d\t\t%.2f\n",
                arr_book[k].id,arr_book[k].name,arr_book[k].author, arr_book[k].quantity, arr_book[k].price);
                found =1;
            }
            }
            if (found ==0)
            {
                printf("Sorry book not found\n");
            }
        }

        else
        {
            printf("Enter a valid choice !\n");
        }
        break;

    case 5:
        printf("Enter the ID of the book which you want to issue: ");
        scanf("%d",&issue_id);
        k =0;
        found =0;
        for (k=0;k<num_books;k++)
        {
        while (arr_book[k].id == issue_id && arr_book[k].quantity>0)
        {
            arr_book[k].quantity--;
            printf("ID\tName\tAuthor\tQuantity\tPrice\n");
            printf("%d\t%s\t%s\t%d\t\t%.2f\n",
            arr_book[k].id,arr_book[k].name,arr_book[k].author, arr_book[k].quantity, arr_book[k].price);
            printf("Book Issued Successfully!\n");
            printf("Return date :");
            printf("%d",3*arr_book[k].quantity);
            printf(" days\n\n");
            found =1;   
        }
        }
        if (found ==0)
        {
            printf("Sorry book not found\n");
        }
        break;

    case 6:
        printf("Enter the ID of the book which you want to return : ");
        scanf("%d",&return_id);
        found =0;
        for (k=0;k<num_books;k++)
        {
        if (arr_book[k].id == return_id)
        {
            arr_book[k].quantity++;
            printf("Successfully returned the book\n");
            found =1;    
        }
        }
        if (found ==0)
        {
            printf("Sorry this book ID does not belong to our library\n");
        }
        break;
    
    default:
        break;
    }

    }
    return 0;
}
