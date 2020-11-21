#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void returnfunc(void);
void adminmenu(void);
void usermenu(void);
void addbooks(void);
void deletebooks(void);
void editbooks(void);
void searchbooks(void);
void issuebooks(void);
void returnbooks(void);
void viewbooks(void);
int  getdata();
int  verifyid(int);

void password();

//list of global files that can be acceed form anywhere in program
FILE *fp,*ft,*fs;


COORD coord = {0, 0};
//list of global variable
int s;
char findbook;
char id_admin[10]={"admin"};
char pass_admin[10]={"admin"};

char id_user[10]={"user"};
char pass_user[10]={"user"};

/* struct database_user database[3];

database.id_user[0] = "user1";
database.pass_user[0] = "pass1";

database.id_user[1 = "user2";
database.pass_user[1] = "pass2";

database.id_user[2] = "user3";
database.pass_user[2] = "pass3";

database.id_user[3] = "user4";
database.pass_user[3] = "pass4"; */

void gotoxy (int x, int y)
{
coord.X = x; coord.Y = y; // X and Y coordinates
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct Date
{
int mm,dd,yy;
};


struct books
{
int id;
char name[20];
char author[20];
int quantity;
float price;
int count;
struct Date issued;
struct Date duedate;
};


struct books a;


int main()
{
password();
getch();
return 0;
}


void adminmenu()
{

system("cls");
int i;
gotoxy(27,3);
printf("MAIN MENU ");

gotoxy(20,5);
printf(" 1. Add Books   ");
gotoxy(20,7);
printf(" 2. Delete Books");
gotoxy(20,9);
printf(" 3. Search Books");
gotoxy(20,11);
printf(" 4. View Book list");
gotoxy(20,13);
printf(" 5. Update Book's Record");
gotoxy(20,15);
printf(" 6. Close Application");
gotoxy(20,20);
printf("Enter your choice:");
switch(getch())
{
case '1':
addbooks();
break;
case '2':
deletebooks();
break;
case '3':
searchbooks();
break;
case '4':
viewbooks();
break;
case '5':
editbooks();
break;
case '6':
{
exit(0);
}
default:
{
gotoxy(10,23);
printf("\aWrong Entry!! Please re-entered correct option");
if(getch())
adminmenu();
}

}
}


void usermenu()
{

system("cls");
int i;
gotoxy(27,3);
printf("MAIN MENU ");

gotoxy(20,5);
printf(" 1. Issue Book   ");
gotoxy(20,7);
printf(" 2. Return Book");
gotoxy(20,9);
printf(" 3. Close Application");
gotoxy(20,13);
printf("Enter your choice:");
switch(getch())
{
case '1':
issuebooks();
break;
case '2':
returnbooks();
break;
case '3':
{
exit(0);
}
default:
{
gotoxy(10,23);
printf("\aWrong Entry!!Please re-entered correct option");
if(getch())
usermenu();
}

}
}


void addbooks(void)    //funtion that add books
{
system("cls");
int i;

system("cls");
fp=fopen("library_file.dat","ab+");
if(getdata()==1)
{
fseek(fp,0,SEEK_END);
fwrite(&a,sizeof(a),1,fp);
fclose(fp);
gotoxy(21,14);
printf("The record is sucessfully saved");
gotoxy(21,15);
printf("Save any more?(Y / N):");
if(getch()=='n')
adminmenu();
else
system("cls");
addbooks();
}
}


void deletebooks()   
{
system("cls");
int d;
char another='y';
while(another=='y')  //infinite loop
{
system("cls");
gotoxy(10,5);
printf("Enter the Book ID to  delete:");
scanf("%d",&d);
fp=fopen("library_file.dat","rb+");
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id==d)
{

gotoxy(10,7);
printf("The book record is available");
gotoxy(10,8);
printf("Book name is %s",a.name);
findbook='t';
}
}
if(findbook!='t')
{
gotoxy(10,10);
printf("No record is found, press any key to return");
if(getch())
adminmenu();
}
if(findbook=='t' )
{
gotoxy(10,9);
printf("Do you want to delete it?(Y/N):");
if(getch()=='y')
{
ft=fopen("test.dat","wb+");  //temporary file for delete
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id!=d)
{
fseek(ft,0,SEEK_CUR);
fwrite(&a,sizeof(a),1,ft); //write all in tempory file except that
}                              //we want to delete
}
fclose(ft);
fclose(fp);
remove("library_file.dat");
rename("test.dat","library_file.dat"); //copy all item from temporary file to fp except that
fp=fopen("library_file.dat","rb+");    //we want to delete
if(findbook=='t')
{
gotoxy(10,10);
printf("The record is sucessfully deleted");
gotoxy(10,11);
printf("Delete another record?(Y/N)");
}
}
else
adminmenu();
fflush(stdin);
another=getch();
}
}
gotoxy(10,15);
adminmenu();
}


void searchbooks()
{
system("cls");
int d;
printf("Search Books");
gotoxy(20,10);
printf(" 1. Search By ID");
gotoxy(20,14);
printf(" 2. Search By Name");
gotoxy( 15,20);
printf("Enter Your Choice");
fp=fopen("library_file.dat","rb+"); //open file for reading propose
rewind(fp);   //move pointer at the begining of file
switch(getch())
{
case '1':
{
system("cls");
gotoxy(25,4);
printf("Search Books By Id");
gotoxy(20,5);
printf("Enter the book id:");
scanf("%d",&d);
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id==d)
{
gotoxy(20,7);
printf("The Book is available");
gotoxy(20,9);
printf("ID:%d",a.id);
gotoxy(20,10);
printf("Name:%s",a.name);
gotoxy(20,11);
printf("Author:%s ",a.author);
gotoxy(20,12);
printf("Qantity:%d ",a.quantity);
gotoxy(20,13);
printf("Price:Rs.%.2f",a.price);
findbook='t';
}

}
if(findbook!='t')  //checks whether conditiion enters inside loop or not
{
gotoxy(22,9);printf("\aNo Record Found");
}
gotoxy(20,17);
printf("Try another search?(Y/N)");
if(getch()=='y')
searchbooks();
else
adminmenu();
break;
}
case '2':
{
char s[15];
system("cls");
gotoxy(25,4);
printf("Search Books By Name");
gotoxy(20,5);
printf("Enter Book Name:");
scanf("%s",s);
int d=0;
while(fread(&a,sizeof(a),1,fp)==1)
{
if(strcmp(a.name,(s))==0) //checks whether a.name is equal to s or not
{
gotoxy(20,7);
printf("The Book is available");
gotoxy(20,9);
printf("ID:%d",a.id);
gotoxy(20,10);
printf("Name:%s",a.name);
gotoxy(20,11);
printf("Author:%s",a.author);
gotoxy(20,12);
printf("Quantity:%d",a.quantity);
gotoxy(20,13);
printf("Price:Rs.%.2f",a.price);
d++;
}

}
if(d==0)
{
gotoxy(22,9);printf("\aNo Record Found");
}
gotoxy(20,17);
printf("Try another search?(Y/N)");
if(getch()=='y')
searchbooks();
else
adminmenu();
break;
}
default :
getch();
searchbooks();
}
fclose(fp);
}


void issuebooks(void)  
{
int t;
system("cls");
int c=0;
char another='y';
while(another=='y')
{
system("cls");
gotoxy(15,4);
printf("Issue Books");
gotoxy(10,6);
printf("Enter the Book Id:");
scanf("%d",&t);
fp=fopen("library_file.dat","rb");
fs=fopen("Issue.dat","ab+");
if(verifyid(t)==0) 
{
gotoxy(10,8);
printf("The book record is available");
gotoxy(10,9);
printf("There are %d unissued books in library ",a.quantity);
gotoxy(10,10);
printf("The name of book is %s",a.name);

if (a.quantity>=0)
{
    a.quantity--;
    fseek(fp,ftell(fp)-sizeof(a),0);
    fwrite(&a,sizeof(a),1,fp);
    gotoxy(10,12);
    printf("Issued date=%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy);
    gotoxy(10,13);
    printf("The BOOK of ID %d is issued",a.id);
    a.duedate.dd=a.issued.dd+a.quantity*3;   //for return date
    a.duedate.mm=a.issued.mm;
    a.duedate.yy=a.issued.yy;
    if(a.duedate.dd>30)
    {
        a.duedate.mm+=a.duedate.dd/30;
        a.duedate.dd-=30;
        }
    
    if(a.duedate.mm>12)
    {
        a.duedate.yy+=a.duedate.mm/12;
        a.duedate.mm-=12;
        }
    gotoxy(10,14);
    printf("To be return:%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
    fseek(fs,sizeof(a),SEEK_END);
    fwrite(&a,sizeof(a),1,fs);
    fclose(fs);
    c=1;
}
}
if(c==0)
{
gotoxy(10,11);
printf("No record found");
}
gotoxy(10,15);
printf("Issue any more(Y/N):");
fflush(stdin);
another=getche();
fclose(fp);
}
system("cls");
gotoxy(1,30);
printf(" Press ENTER to return to main menu");
a:
if(getch()==13) //allow only use of enter
usermenu();
else
goto a;
}

void returnbooks(void)
{
	int t,m;
	system("cls");
	char another = 'y';
	while(another=='y')
	{
		system("cls");
		gotoxy(15,4);
		printf("***Return Book Section***");
		gotoxy(10,6);
		printf("Enter the Book Id:");
		scanf("%d",&t);
		fp = fopen("library_file.dat","rb+");
		rewind(fp);
		while(fread(&a,sizeof(a),1,fp)==1)
		{
			if(a.id==t)
			{
				m = a.quantity;
				m = m+1;
				a.quantity = m;
				findbook = 'f';
			}
		}
		if(findbook!='f')
		{
			gotoxy(10,10);
			printf("No record is found, press any key to return");

			if(getch())
			usermenu();
		}
		if(findbook=='f')
		{
			gotoxy(10,9);
			printf("The Book of ID %d is returned\n",a.id);
		}
		gotoxy(10,10);
		printf("Return any more books(y/n):");
		fflush(stdin);
		another = getch();
		fclose(fp);
	}
	
	system("cls");
	gotoxy(1,30);
	printf("Press ENTER to return to Main Menu");
	a:
	if(getch()==13)
	usermenu();
	else
	goto a;	
	
}

void viewbooks(void)  //show the list of book persists in library
{
int i=0,j;
system("cls");
gotoxy(1,1);
printf("===================Book List=====================");
gotoxy(2,2);
printf(" ID    BOOK NAME     AUTHOR       QTY     PRICE ");
j=4;
fp=fopen("library_file.dat","rb");
while(fread(&a,sizeof(a),1,fp)==1)
{
gotoxy(1,j);
printf("%d",a.id);
gotoxy(12,j);
printf("%s",a.name);
gotoxy(26,j);
printf("%s",a.author);
gotoxy(40,j);
printf("%d",a.quantity);
gotoxy(47,j);
printf("%.2f",a.price);
printf("\n\n");
j++;
i=i+a.quantity;
}
gotoxy(3,25);
printf("Total Books =%d",i);
fclose(fp);
gotoxy(35,25);
returnfunc();
}

void editbooks(void)  //Update information about book
{
system("cls");
int c=0;
int d,e;
gotoxy(20,4);
printf("Update Books Section");
char another='y';
while(another=='y')
{
system("cls");
gotoxy(15,6);
printf("Enter Book Id to be Updateed:");
scanf("%d",&d);
fp=fopen("library_file.dat","rb+");
while(fread(&a,sizeof(a),1,fp)==1)
{
if(verifyid(d)==0)
{
gotoxy(15,7);
printf("The book is availble");
gotoxy(15,8);
printf("The Book ID:%d",a.id);
gotoxy(15,9);
printf("Enter new name:");scanf("%s",a.name);
gotoxy(15,10);
printf("Enter new Author:");scanf("%s",a.author);
gotoxy(15,11);
printf("Enter new quantity:");scanf("%d",&a.quantity);
gotoxy(15,12);
printf("Enter new price:");scanf("%f",&a.price);
gotoxy(15,14);
printf("The record is modified");
fseek(fp,ftell(fp)-sizeof(a),0);
fwrite(&a,sizeof(a),1,fp);
fclose(fp);
c=1;
}
if(c==0)
{
gotoxy(15,9);
printf("No record found");
}
}
gotoxy(15,16);
printf("Modify another Record?(Y/N)");
fflush(stdin);
another=getch() ;
}
returnfunc();
}


void returnfunc(void)
{
{
printf(" Press ENTER to return to main menu");
}
a:
if(getch()==13) //to allow only use of enter
adminmenu();
else
goto a;
}


int getdata()
{
int t;
gotoxy(20,3);
printf("Enter the Information Below\n");
gotoxy(21,6);
printf("Book ID:\t");
gotoxy(30,6);
scanf("%d",&t);
if(verifyid(t) == 0)
{
gotoxy(21,13);
printf("\aThe book id already exists\a");
getch();
adminmenu();
return 0;
}
a.id=t;
gotoxy(21,7);
printf("Book Name:");gotoxy(33,7);
scanf("%s",a.name);
gotoxy(21,8);
printf("Author:");gotoxy(30,8);
scanf("%s",a.author);
gotoxy(21,9);
printf("Quantity:");gotoxy(31,9);
scanf("%d",&a.quantity);
gotoxy(21,10);
printf("Price:");gotoxy(28,10);
scanf("%f",&a.price);
gotoxy(21,11);
return 1;
}


int verifyid(int t)  //check whether the book is exist in library or not
{
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
if(a.id==t)
return 0;  //returns 0 if book exits
return 1; //return 1 if it not
}

void password(void) 
{

system("cls");
char ch,pass[10];
char username[20];
int i=0,j,iter=0;

gotoxy(15,7);
printf("Enter Username: ");
scanf("%s",username);
gotoxy(15,9);
printf("Enter Password: ");

while(ch!=13)
{
ch=getch();

if(ch!=13 && ch!=8){
putch('*');
pass[i] = ch;
i++;
}
}
pass[i] = '\0';

if((strcmp(pass,pass_admin)==0)&&(strcmp(username,id_admin)==0))
{

system("cls");
gotoxy(17,9);
printf("Password match");
gotoxy(17,10);
printf("Press any key to countinue.....");
getch();
adminmenu();
}


if((strcmp(username,id_user)==0)&&(strcmp(pass,pass_user)==0))
{   
    system("cls");
    gotoxy(17,9);
    printf("Password match");
    gotoxy(17,10);
    printf("Press any key to continue.....");
    getch(); //conio.h in windows wont work in linux
    usermenu();
}

else
{
gotoxy(15,16);
printf("\aWarning!! Incorrect Username or password");
getch();
password();
}
}
