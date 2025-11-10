#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    int roll;
    char name[30];
    float marks;
};

int pos(int r) { return r * sizeof(Student); }

int main() {
    int ch, r;
    Student s;

    do {
        cout << "\n1.Add 2.Search 3.Update 4.Delete 5.Exit\nChoice: ";
        cin >> ch;



        if(ch==1) {
            fstream f("stud.dat", ios::in | ios::out | ios::binary);
            if(!f) f.open("stud.dat", ios::out | ios::binary);

            cout << "Roll Name Marks: ";
            cin >> s.roll >> s.name >> s.marks;
            f.seekp(pos(s.roll));
            f.write((char*)&s, sizeof(s));
            cout << "Added.\n";
            f.close();

        }

        if(ch==2) {
            fstream f("stud.dat", ios::in | ios::out | ios::binary);

            cout << "Roll: "; cin >> r;
            f.seekg(pos(r));
            f.read((char*)&s, sizeof(s));
            if(f.gcount()>0 && s.roll==r)
                cout << s.name << " " << s.marks << endl;
            else
                cout << "Not Found.\n";
            f.close();

        }

        if(ch==3) {
            fstream f("stud.dat", ios::in | ios::out | ios::binary);

            cout << "Roll: "; cin >> r;
            f.seekg(pos(r));
            f.read((char*)&s, sizeof(s));
            if(f.gcount()>0 && s.roll==r) {
                cout << "New Marks: ";
                cin >> s.marks;
                f.seekp(pos(r));
                f.write((char*)&s, sizeof(s));
                cout << "Updated.\n";
            } else cout << "Not Found.\n";
            f.close();

        }

        if(ch==4) {
            fstream f("stud.dat", ios::in | ios::out | ios::binary);

            cout << "Roll: "; cin >> r;
            Student blank = {0,"",0};
            f.seekp(pos(r));
            f.write((char*)&blank, sizeof(blank));
            cout << "Deleted.\n";
            f.close();
        }


    } while(ch!=5);

    return 0;
}


/*

# ✅ **Algorithm (Elaborated but short)**

1. Start the program.
2. Display menu: Add, Search, Update, Delete, Exit.
3. For Add:

   * Open file in binary read/write mode.
   * Read roll, name, marks.
   * Move pointer to `roll * sizeof(Student)`.
   * Write the student structure.
4. For Search:

   * Open file.
   * Read roll number.
   * Move pointer to its position.
   * Read structure and display if roll matches.
5. For Update:

   * Open file.
   * Move pointer to record and read.
   * If exists, modify marks and write back.
6. For Delete:

   * Overwrite that record with a blank structure.
7. Repeat until Exit.
8. Stop.

---

Would you like a **sample output** page or a **flowchart** to attach in journal?
*/