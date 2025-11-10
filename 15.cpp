#include <iostream>
#include <fstream>
using namespace std;

struct Emp {
    int id;
    string name, dept, addr;
};

int main() {
    int ch, id, found;
    Emp e;

    do {
        cout << "\n1.Add 2.Display 3.Delete 4.Exit\nChoice: ";
        cin >> ch;

        // ADD employee
        if(ch == 1) {
            ofstream f("emp.txt", ios::app);
            cout << "ID Name Dept Address: ";
            cin >> e.id >> e.name >> e.dept >> e.addr;
            f << e.id << " " << e.name << " " << e.dept << " " << e.addr << endl; // writing in the file
            cout << "Added.\n";
            f.close();
        }

        // DISPLAY employee by ID
        if(ch == 2) {
            ifstream f("emp.txt");
            cout << "Enter employee ID: ";
            cin >> id;
            found = 0;

            /*
            for writing :- f << e.name << " " << e.id....
            for searching use while or updating or deleting :- f >> e.id >> e.name >> ......

            AND FOR DELETING AND UPDATING USE TEMP FILE STORE DESIRED DATA IN TEMP FILE AND THEN DELETE MAIN FILE (EMP) AND RENAME TEMP FILE TO EMP
            OPEN IN BOTH READ AND WRITE
            */


            while(f >> e.id >> e.name >> e.dept >> e.addr) {  // for searching sequentially, it reads employees sequentially for searching
                if(e.id == id) {
                    found = 1;
                    cout << "Name: " << e.name << "\nDept: " << e.dept 
                         << "\nAddress: " << e.addr << endl;
                }
            }
            if(!found) cout << "Employee not found.\n";
            f.close();
        }

        // DELETE employee by ID
        if(ch == 3) {
            ifstream f("emp.txt");
            ofstream t("temp.txt");
            cout << "Enter employee ID to delete: ";
            cin >> id;
            found = 0;

            while(f >> e.id >> e.name >> e.dept >> e.addr) {
                if(e.id == id) found = 1;
                else t << e.id << " " << e.name << " " << e.dept << " " << e.addr << endl;
            }

            f.close();
            t.close();
            //remove("emp.txt");
            // rename("temp.txt", "emp.txt");
            //first remove then rename
            remove("emp.txt");
            rename("temp.txt", "emp.txt");

            if(found) cout << "Deleted.\n";
            else cout << "Employee not found.\n";
        }

    } while(ch != 4);

    return 0;
}
