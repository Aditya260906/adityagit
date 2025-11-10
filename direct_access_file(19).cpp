/*
Direct Access File is a file where data can be accessed directly using a file pointer without reading previous records.
✅ Used Functions in C++
Function	Work
seekg()	move file pointer for reading
seekp()	move file pointer for writing
read()	read record
write()	write record
*/

#include <iostream>
#include <fstream>
using namespace std;

struct Book {
    int id;
    char title[30], author[30];
    bool avail;
};

int pos(int id) { return id * sizeof(Book); } // calculates the position of the book record

int main() {

    int ch;
    Book b;
    do {
        cout << "\n1.Add 2.Search 3.Update 4.Delete 5.Exit\nChoice: ";
        cin >> ch;

        if(ch==1) {
            fstream f("books.dat", ios::in | ios::out | ios::binary);
            if(!f) f.open("books.dat", ios::out | ios::binary);

            cout << "ID Title Author Available(1/0): ";
            cin >> b.id >> b.title >> b.author >> b.avail;
            f.seekp(pos(b.id));
            // // move file ptr to a specified id for writing
            // f.seekp(pos(b.id));
            f.write((char*)&b, sizeof(b));
            //add / write book details in the file
            // f.write((char*)&b, sizeof(b));
            cout << "Added.\n";
                f.close();
        }

        if(ch==2) {
            fstream f("books.dat", ios::in | ios::out | ios::binary);

            int id;
            cout << "Enter ID: ";
            cin >> id;
            f.seekg(pos(id)); // move the file pointer to a specified book id
            f.read((char*)&b, sizeof(b)); //read book details from the file
            if(f.gcount()>0 && b.id==id) {
                //After reading from a file, gcount() tells how many bytes were actually read.
                cout << "Title: " << b.title << "\nAuthor: " << b.author
                     << "\nAvailable: " << (b.avail? "Yes":"No") << endl;
            } else cout << "Not Found.\n";
                f.close();
        }

        if(ch==3) {
            fstream f("books.dat", ios::in | ios::out | ios::binary);

            int id;
            cout << "Enter ID to Update: ";
            cin >> id;
            f.seekg(pos(id));
            f.read((char*)&b, sizeof(b));
            if(f.gcount()>0 && b.id==id) {
                cout << "Enter New Availability(1/0): ";
                cin >> b.avail;
                f.seekp(pos(id));
                f.write((char*)&b, sizeof(b));
                cout << "Updated.\n";
            } else cout << "Not Found.\n";
                f.close();
        }

        if(ch==4) {
            fstream f("books.dat", ios::in | ios::out | ios::binary);

            int id;
            cout << "Enter ID to Delete: ";
            cin >> id;
            Book blank = {0,"","",0};
            f.seekp(pos(id));
            f.write((char*)&blank, sizeof(blank));
            cout << "Deleted.\n";
                f.close();
        }

    } while(ch!=5);

    return 0;
}


/*
Algorithm:

1. Start the program.
2. Display menu with choices: Add, Search, Update, Delete, Exit.
3. Read the user's choice.

Add Record:
4. Open "books.dat" in read/write binary mode.
5. Read Book ID, Title, Author and Availability from user.
6. Move file pointer to (ID * sizeof(Book)).
7. Write the book structure to the file.
8. Close the file.

Search Record:
9. Open "books.dat" in read mode.
10. Read Book ID to search.
11. Move file pointer to (ID * sizeof(Book)).
12. Read structure from that position.
13. If record exists and ID matches → display details, else print "Not Found".
14. Close the file.

Update Record:
15. Open "books.dat" in read/write binary mode.
16. Read Book ID to update.
17. Move pointer and read record.
18. If ID matches → read new availability, move pointer back and rewrite record.
19. If not matched → print "Not Found".
20. Close the file.

Delete Record:
21. Open "books.dat" in read/write mode.
22. Read Book ID to delete.
23. Create a blank record.
24. Move pointer and overwrite old record with blank.
25. Close the file.

26. Repeat menu until user chooses Exit.
27. Stop.
*/

