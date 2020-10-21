#include<stdio.h>
#include<stdlib.h>
#include<string.h>                  
#include<ctype.h>                   
#include<time.h>
#include <openssl/sha.h>

char mypass[10] = {"admin"};

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
    char stname[20];
    char name[20];
    char Author[20];
    int quantity;
    float Price;
    int count;
    int rackno;
    int floorno;
    char *cat;
    struct meroDate issued;
    struct meroDate duedate;
};


struct book a;


void mainmenu(void);
void add(void);
void delete(void);
void edit(void);
void search(void);
void issue(void);
void view(void);
void closeapplication(void);
int  getdata();
int  checkid(int);
void Password();
void issuerecord();
void loaderanim();


void main()
{
    system("clear");
    gotoxy (40,0);
    printf("Welcome to the Library Management System for IISER Kolkata\n");
    mainmenu();
    Password();
}

void Password()
{
    char pass[20];
    char role[5];
    printf("Please Specify Your Role:\nEnter 'a' For Admin \nEnter 'u' For User\n\n");
    printf("Enter (a/u): ");
    scanf("%s", role);
    if (strcmp(role,"a")==0)
    {
        printf("Enter password for admin: ");
        scanf("%s", pass);
    }
    else if (strcmp(role,"u")==0)
    {
        system("clear");
        gotoxy (50,0);
        printf("Welcome User\n");
        printf("Enter choice: \n");
        switch(getch())
        {
            case '1':
            add();
            break;
            
            case '2':
            delete();
            break;

            case '3':
            search();
            break;
            
            case '4':
            issue();
            break;
            
            case '5':
            view();
            break;
            
            case '6':
            edit();
            break;
            }
    else
    {
        printf("Okay then, if you don't wanna play by my rules, I'll just quit\n");
    }
}
}

void mainmenu()
{
system("clear");
int i;
gotoxy(40,3);
printf(" MAIN MENU ");
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
printf("Enter your choice: ");
}