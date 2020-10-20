# Library_System
This is a project is a part of CS3101 course on Data Structures and Algorithms in to design an interactive library system in C programming language. It should have two modes of access (i) Admin and (ii) User. There should be unique login ids for each. The system should ask for the login id and check it against a list. The admin and user ids for a person should be different. A person without a valid id should not be allowed to access the library. An Admin should typically be the librarian (or others responsible for the library). Users can be students or faculties.

The allowed operations for each of these modes are:
Admin: Addition, deletion and updation of book records
User: Acquiring and returning of books


Each book should have a unique id, number of copies available, title, author, publisher etc. Each issue of a book should have a unique id as well. The number of days for which a book can be borrowed should be dependent on the availability (more number of days for the books with a higher number of copies available). Also, there should be an upper limit on the number of books one can acquire at the same time. Books with less than 3 copies should be issued only to faculties.

The system should have an interactive interface. It should show the current status of the availability and assign books accordingly. It should also take back books. The library database should be updated accordingly. It should also give the aforementioned rights to the admin.

In addition, a search facility should be present for both these modes allowing free-text search in general and also for specific fields of a book.
