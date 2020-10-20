#include<stdio.h>
#include<stdlib.h>
#include<string.h>                  //contains strcmp(),strcpy(),strlen(),etc
#include<ctype.h>                   //contains toupper(), tolower()
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
    gotoxy (40,50);
    printf("Welcome to the Library Management System for IISER Kolkata\n");
    Password();
}

void Password()
{
    char pass[20];
    printf("Please Specify Your Role:\nEnter 'a' For ADMIN \nEnter 'u' For USER\n\n");
    printf("Enter (a/u): ");
    scanf("%s", pass);
}