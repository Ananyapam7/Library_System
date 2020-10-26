#include<stdio.h>
#include<stdlib.h>
#include<string.h>                  
#include<ctype.h>                   
#include<time.h>

// void gotoxy(int x,int y)
// {
//     printf("%c[%d;%df",0x1B,y,x);
// }

// struct meroDate
// {
//     int mm,dd,yy;
// };


struct book
{
    int id;
    // char name;
    // char Author;
    int quantity;
    // char publisher;
    // struct meroDate issued;
    // struct meroDate duedate;
};

int main()
{    
int i;    
struct book b[5];    
printf("Enter Records of 5 students");    
for(i=0;i<5;i++){    
printf("\nEnter id:");    
scanf("%d", &b[i].id);    
// printf("\nEnter Name:"); 
// fgets(&b[i].name, sizeof(b[i].name), stdin);
// printf("\nEnter Author:");    
// fgets(&b[i].Author, sizeof(b[i].Author), stdin);   
printf("\nEnter Quantity:");    
scanf("%d", &b[i].quantity);
// printf("\nEnter Publisher:");    
// fgets(&b[i].publisher, sizeof(b[i].publisher), stdin);   
}
printf("\nBook Information List:");    
for(i=0;i<5;i++){    
printf("\nRollno:%d, Quantity:%d",b[i].id,b[i].quantity);    
}    
   return 0;    
}   