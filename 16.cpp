#include <iostream>
using namespace std;

struct Student {
    int roll;
    string name;
    float marks;
};

void display(Student s[], int n) {
    for(int i=0; i<n; i++)
        cout << s[i].roll << " " << s[i].name << " " << s[i].marks << endl;
}

void sortByRoll(Student s[], int n) {
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-i-1; j++)
            if(s[j].roll > s[j+1].roll)
                swap(s[j], s[j+1]);
}

void sortByName(Student s[], int n) {
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-i-1; j++)
            if(s[j].name > s[j+1].name)      // alphabetical
                swap(s[j], s[j+1]);
}



void sortByMarks(Student s[], int n) {
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-i-1; j++)
            if(s[j].marks < s[j+1].marks)    // descending
                swap(s[j], s[j+1]);
}

int main() {
    Student s[100];
    int n, ch;

    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter Roll, Name, Marks:\n";
    for(int i=0; i<n; i++)
        cin >> s[i].roll >> s[i].name >> s[i].marks;

    do {
        cout << "\n1.Display 2.Sort by Roll 3.Sort by Name 4.Sort by Marks 5.Exit\nChoice: ";
        cin >> ch;

        if(ch==1) display(s, n);
        if(ch==2) { sortByRoll(s, n); cout << "Sorted by Roll.\n"; }
        if(ch==3) { sortByName(s, n); cout << "Sorted by Name.\n"; }
        if(ch==4) { sortByMarks(s, n); cout << "Sorted by Marks.\n"; }

    } while(ch != 5);

    return 0;
}
