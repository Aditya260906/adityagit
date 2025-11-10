#include <iostream>
using namespace std;

struct Emp {
    int id;
    string name, dept;
    float salary;
};

void display(Emp e[], int n) {
    for(int i=0; i<n; i++)
        cout << e[i].id << " " << e[i].name << " " << e[i].dept << " " << e[i].salary << endl;
}

void sortByID(Emp e[], int n) {           // Ascending
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(e[j].id > e[j+1].id)
                swap(e[j], e[j+1]);
}

void sortByName(Emp e[], int n) {         // Alphabetical
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(e[j].name > e[j+1].name)
                swap(e[j], e[j+1]);
}

void sortBySalary(Emp e[], int n) {       // Descending
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(e[j].salary < e[j+1].salary)
                swap(e[j], e[j+1]);
}

int main() {
    Emp e[100];
    int n, ch;

    cout << "Enter number of employees: ";
    cin >> n;

    cout << "Enter ID Name Dept Salary:\n";
    for(int i=0;i<n;i++)
        cin >> e[i].id >> e[i].name >> e[i].dept >> e[i].salary;

    do {
        cout << "\n1.Display 2.Sort by ID 3.Sort by Name 4.Sort by Salary 5.Exit\nChoice: ";
        cin >> ch;

        if(ch==1) display(e, n);
        if(ch==2) { sortByID(e, n); cout << "Sorted by ID.\n"; }
        if(ch==3) { sortByName(e, n); cout << "Sorted by Name.\n"; }
        if(ch==4) { sortBySalary(e, n); cout << "Sorted by Salary.\n"; }

    } while(ch != 5);

    return 0;
}
