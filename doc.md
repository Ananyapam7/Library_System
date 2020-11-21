# Library Management System in C 
Course: CS3101
##### Requirements:
Design an interactive library system in C programming language. It should have two modes of access (i) Admin and (ii) User. There should be unique login ids for each. The system should ask for the login id and check it against a list. The admin and user ids for a person should be different. A person without a valid id should not be allowed to access the library. An Admin should typically be the librarian (or others responsible for the library). Users can be students or faculties.

The allowed operations for each of these modes are:
Admin: Addition, deletion and updation of book records
User: Acquiring and returning of books


Each book should have a unique id, number of copies available, title, author, publisher etc. Each issue of a book should be recorded as well. The number of days for which a book can be borrowed should be dependent on the availability (more number of days for the books with a higher number of copies available). Also, there should be an upper limit on the number of books one can acquire at the same time. Books with less than 3 copies should be issued only to faculties.

The system should have an interactive interface. It should show the current status of the availability and assign books accordingly. It should also take back books. The library database should be updated accordingly. It should also give the aforementioned rights to the admin.

In addition, a search facility should be present for both these modes allowing free-text search in general and also for specific fields of a book.

## Documentation
This code is written on Windows 10 operating system and is compiled using the gcc compiler provided by Dev C++

### Header Files
#### <windows.h>

#### <conio.h>

#### <stdio.h>

#### <stdlib.h>

#### <string.h>

### Control Flow
The system begins by calling password() which then checks if the person is a user or an admin by verifying a valid username and password and opens the menu accordingly.

#### void password()
This function is used by the admin and user to login into system. They are required to enter user id and password before they are allowed to enter the system .The user id and password will be verified and if invalid id is there user or admin is  not allowed to enter in the system.
If valid username and password is entered by the user and admin, they will be allowed to go to the usermenu and adminmenu respectively. Note that this is not a secure way of entering passwords as no hashing has been used and hence should not be implimented in commercial systems.
```C
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
    getch(); 
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
```

#### void usermenu()
This function will be called after the user logs in the system. It has two functions inside it. 


##### void issuebooks()

##### void returnbooks()

#### void adminmenu()
This function will is called after the admin enters valid credentials to log in to the system to further use the following functions :
1. Add Books
2. Delete Books
3. Search Books
4. View Book List
5. Update Book's Record
6. Closing the application

##### void addbooks()
This function is accessible to admin only. To access this function the admin needs to input the number preceding "Add Books" (in this case 1) in the MAIN MENU. After chosing "Add Books", input "Book ID"(integer type), Book Name, Author, Quantity and Price. The information of the books is stored in the binary file "library_file.dat".
```C
void addbooks(void)
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
```

##### void deletebooks()
This function is accessible to admin only. To access this function the admin needs to input the number preceding "Delete Books" (in this case 2) in the MAIN MENU. Afterwards enter the id of the book to be deleted. Hit "Y" to confirm deletion.
```C
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
fwrite(&a,sizeof(a),1,ft); 
}                              
}
fclose(ft);
fclose(fp);
remove("library_file.dat");
rename("test.dat","library_file.dat");
fp=fopen("library_file.dat","rb+"); 
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
```

##### void searchbooks()


##### void updatebooks()
This function is accesible to admin only. The admin needs to input the number preceding "Update Book's Record" (in this case 5) in the MAIN MENU. Then enter the id of the book to whose record need to be updated. Next, enter the new name (if it is desired to keep the previous name, enter the previous name), new author, new quantity and the new price.
```C
void editbooks(void)  
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
```

### Other User-Defined Functions

#### void gotoxy (int x, int y)
This is used in various parts of the program to move the output cursor to different parts of the screen mainly for the aesthetics.
```C
COORD coord = {0, 0};
void gotoxy (int x, int y)
{
coord.X = x; coord.Y = y; // X and Y coordinates
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
```
#### void returnfunc()
```C
void returnfunc()
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
```

#### int verifyid(int t)  
This function is to check whether the book already exists in the library or not
```C
int verifyid(int t)  
{
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
if(a.id==t)
return 0;  //returns 0 if book exits
return 1; //return 1 if it not
}
```


### Structures Used

#### struct Date()
```C
struct Date
{
int mm,dd,yy;
};
```

#### struct books()
```C
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
```

#### Contributors and Modularizations:
Divyanshu Kumar

Arundhati Roy

Sanwayee Biswas

Abhay Kumar

Praful Rahangdale

Ananyapam De