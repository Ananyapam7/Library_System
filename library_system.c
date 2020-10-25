#include<stdio.h>
#include<stdlib.h>
#include<string.h>                  
#include<ctype.h>                   
#include<time.h>

char mypass_admin[10] = {"admin"};
char mypass_user[10] = {"user"};

char pass[20];

int choice;

void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}

struct meroDate
{
    int mm,dd,yy;
};


struct book
{
    int id;
    char name[20];
    char Author[20];
    int quantity;
    char publisher[20];
    struct meroDate issued;
    struct meroDate duedate;
};


struct book a;


void mainmenu_user(void);
void mainmenu_admin(void);
void add(void);
void delete(void);
void edit(void);
void search(void);
void issue(void);
void view(void);
void closeapplication(void);
int  getdata();
void Password();
void issuerecord();


void main()
{
    system("clear");
    gotoxy (40,0);
    printf("Welcome to the Library Management System for IISER Kolkata\n");
    Password();
    if (strcmp(pass, mypass_admin)==0)
    {
        mainmenu_admin();
    }
    if (strcmp(pass, mypass_user)==0)
    {
        mainmenu_user();
    }
}

void Password()
{
    char role[5];
    printf("Please Specify Your Role:\nEnter 'a' For Admin \nEnter 'u' For User\n\n");
    printf("Enter (a/u): ");
    scanf("%s", role);
    if (strcmp(role,"a")==0)
    {
        printf("Enter your password for admin: ");
        scanf("%s", pass);
    }
    else if (strcmp(role,"u")==0)
    {
        printf("Enter your password for user: ");
        scanf("%s", pass);
    }
    else
    {
        printf("Okay then, if you don't wanna play by my rules, I'll just quit\n");
    }
}

void mainmenu_admin()
{
system("clear");
int i;
gotoxy(40,3);
printf(" MAIN MENU FOR ADMIN");
gotoxy(20,5);
printf("      1. Add Books");
gotoxy(20,7);
printf("      2. Delete books");
gotoxy(20,9);
printf("      3. Search Books");
gotoxy(20,11);
printf("      4. Issue Books");
gotoxy(20,13);
printf("      5. View Book list");
gotoxy(20,15);
printf("      6. Edit Book's Record");
gotoxy(20,17);
printf("      7. Close Application");
gotoxy(20,19);
printf("Enter your choice: \n");

scanf("%d", choice);



}

void mainmenu_user()
{
system("clear");
int i;
gotoxy(40,3);
printf(" MAIN MENU FOR USER");
gotoxy(20,5);
printf("      1. Search Books");
gotoxy(20,7);
printf("      2. Issue Books");
gotoxy(20,9);
printf("      3. View Book list");
gotoxy(20,11);
printf("      4. Close Application");
gotoxy(20,13);
printf("Enter your choice: ");
}