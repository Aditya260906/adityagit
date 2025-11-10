/*
✅ What is a Sequential File? (Simple Explanation)

A Sequential File stores records one after another in order, like a list.

To read or search a record, the computer must start from the beginning and go record by record until it finds the required one.

✅ Records stored in sequence
✅ Read line-by-line
✅ Slow for searching, updating, deleting
✅ Very easy to use
*/
#include <iostream>
#include <fstream> // use fstream
using namespace std;

struct Student {
    int roll, m[5];
    string name;
};

void addRec() {
    ofstream f("students.txt", ios::app);
    /*
     for writing we use ofstream
     ofstream f("student.txt", ios::app);
     */
    Student s; // we create object for student struct to access the attributes of students

    // I/P
    cout << "Roll: "; cin >> s.roll;
    cout << "Name: "; cin >> s.name;
    cout << "5 Marks: ";
    for(int i=0;i<5;i++) cin >> s.m[i];

    // inputing in file
    f << s.roll << " " << s.name; // vvvvvimp for inputing in file we use 'f << ' instead of 'cin'    ;f << s.roll << " " << s.name;
    for(int i=0;i<5;i++) f << " " << s.m[i];
    f << endl;
    cout << "Added.\n";
}

void searchRec() {
    ifstream f("students.txt");
    /*
    from reading from the file we use ifstream
    from file reading is done in line by line manner, we use sequential file allocn for that

    */
    int r, roll, m[5], found=0;
    string name;
    cout << "Roll to search: "; cin >> r;
    while(f >> roll >> name >> m[0] >> m[1] >> m[2] >> m[3] >> m[4]) { //for searching line by line nd also for deleting and updation
        if(roll == r) {
            found = 1;
            cout << "Name: " << name << "\nMarks: ";  // this is normal output
            for(int i=0;i<5;i++) cout << m[i] << " ";
            cout << endl;
        }
    }
    if(!found) cout << "Not Found.\n";
}

void updateRec() {
    ifstream f("students.txt"); // read
    ofstream t("temp.txt"); //  write
    int r, sub, newM, roll, m[5], found=0;
    string name;
    cout << "Roll: "; cin >> r;
    cout << "Subject(1-5) New Marks: "; cin >> sub >> newM;

    while(f >> roll >> name >> m[0] >> m[1] >> m[2] >> m[3] >> m[4]) {
        if(roll == r) { m[sub-1] = newM; found = 1; } // if found updating it before
        // copying records to temp
        t << roll << " " << name;
        for(int i=0;i<5;i++) t << " " << m[i];
        t << endl;
    }

    //very crucial step
    f.close(); t.close();
    remove("students.txt"); rename("temp.txt","students.txt");
    if(found) cout << "Updated.\n"; else cout << "Not Found.\n";
}

void deleteRec() { // use flag
    ifstream f("students.txt"); // read mode
    ofstream t("temp.txt"); // write mode but deletes old data as I haven't used append
    int r, roll, m[5], found=0;
    string name;
    cout << "Roll: "; cin >> r;
    while(f >> roll >> name >> m[0] >> m[1] >> m[2] >> m[3] >> m[4]) {
        if(roll == r) found = 1;
        else { // we are copying data from student.txt to temp.txt
            t << roll << " " << name;
            for(int i=0;i<5;i++) t << " " << m[i];
            t << endl;
        }
    }
    f.close(); t.close();
    remove("students.txt"); rename("temp.txt","students.txt"); // remove and rename
    if(found) cout << "Deleted.\n"; else cout << "Not Found.\n";
}

int main() {
    int ch;
    do {
        cout << "\n1.Add 2.Search 3.Update 4.Delete 5.Exit\nChoice: ";
        cin >> ch;
        if(ch==1) addRec();
        if(ch==2) searchRec();
        if(ch==3) updateRec();
        if(ch==4) deleteRec();
    } while(ch!=5);
    return 0;
}

/*
Algorithm


1. Start the program.

2. Display menu: Add, Search, Update, Delete, Exit.

3. Read the user’s choice.

For Add:
4. Open students.txt in append mode.
5. Read roll number, name, and 5 marks.
6. Write the data to the file and close it.

For Search:
7. Open students.txt in read mode.
8. Read the roll number to search.
9. Check each record line-by-line.
10. If roll matches, display name and marks.
11. If no match is found, display "Not Found".
12. Close the file.

For Update:
13. Open students.txt in read mode and temp.txt in write mode.
14. Read roll number, subject number, and new marks.
15. Copy each record to temp.txt. If roll matches, replace old mark with new mark.
16. Close files, delete original file, and rename temp.txt to students.txt.

For Delete:
17. Open students.txt in read mode and temp.txt in write mode.
18. Read roll to delete.
19. Copy all records except the matching roll.
20. Close files, delete original file, and rename temp.txt to students.txt.

21. Repeat the menu until the user selects Exit.

22. Stop.
*/