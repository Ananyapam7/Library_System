#include<stdio.h>
#include<stdlib.h>
#include<string.h>                  
#include<ctype.h>                   
#include<time.h>

char mypass[10] = {"admin"};

void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}
// void mainmenu(void);
// void add(void);
// void delete(void);
// void edit(void);
// void search(void);
// void issue(void);
// void view(void);
// void closeapplication(void);
// int  getdata();
// int  checkid(int);
void Password();
// void issuerecord();
// void loaderanim();

void main()
{
    system("clear");
    gotoxy (40,0);
    printf("Welcome to the Library Management System for IISER Kolkata\n");
    Password();
}

void Password()
{
    char pass[20];
    char role[5];
    printf("Please Specify Your Role:\nEnter 'a' For ADMIN \nEnter 'u' For USER\n\n");
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
    }
    else
    {
        printf("Okay then, if you don't wanna play by my rules, I'll just quit\n");
    }
}