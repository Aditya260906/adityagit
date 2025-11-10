#include<iostream>
#include<fstream>
using namespace std;

struct Student{
    int rno;
    string name;
    float marks;
};

int pos(int r) {return r * sizeof(Student);}

int main(){
    Student s;
    int choice, r;
    do {
        cout << "Enter Choice \n 1. add \t 2.update \t 3.delete \t 4.search \t 5.exit \n";
        cin >> choice;

        if(choice == 1){
            fstream f("stud.dat", ios::in | ios::out | ios::binary);
            if(!f) f.open("stud.dat", ios::out | ios::binary);

            cout << "Enter roll no. name mark" << endl ;
            cin >> s.rno >> s.name >> s.marks;;
            f.seekp(pos(s.rno));
            f.write((char*)&s, sizeof(s));
            cout << "added." << endl;
            f.close(); 
        }

        if(choice == 2){
            fstream f("stud.dat", ios::in | ios::out | ios::binary);

            cout << "Enter rno to update marks" << endl;
            cin >> r;
            f.seekg(pos(r));
            f.read((char*)&s, sizeof(s));

            if(f.gcount() > 0 && s.rno == r){
                cout << "enter marks" << endl;
                cin >> s.marks;

                f.seekp(pos(r));
                f.write((char*)&s, sizeof(s));
                cout << "updated" << endl;
            }
            else { 
                cout << "Record not found" << endl;
            }
            f.close();
        }

        if(choice == 3){
            fstream f("stud.dat", ios::in | ios::out | ios::binary);
            cout << "Enter rno" << endl; cin >> r;

            f.seekg(pos(r));
            f.read((char*)&s, sizeof(s));

            if(f.gcount() > 0 && s.rno == r){
                f.seekp(pos(r));
                Student blank = {0, "" , 0};
                f.write((char*)&blank, sizeof(s));
                cout << "Deleted" << endl;
            }
            else{
                cout << "record not found" << endl;
            }

            f.close();

        }
    
        if(choice == 4){
            fstream f("stud.dat", ios::in | ios::out | ios::binary);
            cout << "Enter rno" << endl; cin >> r;

            f.seekg(pos(r));
            f.read((char*)&s, sizeof(s));

            if(f.gcount() > 0 && s.rno == r){
                cout << "Found" << endl;
                cout << "Roll no. : " << s.rno << "\nName : " << s.name << "\nMarks : "<< s.marks << endl;
            }
            else{
                cout << "record not found" << endl;
            }

            f.close();
        }

    } while(choice != 5);
    return 0;
}