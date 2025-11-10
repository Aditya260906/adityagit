#include <iostream>
using namespace std;

struct Product {
    int id;
    string name;
    float price, rating;
};

void display(Product p[], int n) {
    for(int i=0; i<n; i++)
        cout << p[i].id << " " << p[i].name << " " << p[i].price << " " << p[i].rating << endl;
}

void sortByPrice(Product p[], int n) {      // low → high
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(p[j].price > p[j+1].price)
                swap(p[j], p[j+1]);
}

void sortByRating(Product p[], int n) {     // high → low
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(p[j].rating < p[j+1].rating)
                swap(p[j], p[j+1]);
}

void sortByName(Product p[], int n) {       // A → Z
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(p[j].name > p[j+1].name)
                swap(p[j], p[j+1]);
}

int main() {
    Product p[50];
    int n, ch;

    cout << "Enter number of products: ";
    cin >> n;

    cout << "Enter ID Name Price Rating:\n";
    for(int i=0;i<n;i++)
        cin >> p[i].id >> p[i].name >> p[i].price >> p[i].rating;

    do {
        cout << "\n1.Display 2.Sort by Price 3.Sort by Rating 4.Sort by Name 5.Exit\nChoice: ";
        cin >> ch;

        if(ch==1) display(p, n);
        if(ch==2) { sortByPrice(p, n); cout << "Sorted by Price.\n"; }
        if(ch==3) { sortByRating(p, n); cout << "Sorted by Rating.\n"; }
        if(ch==4) { sortByName(p, n);  cout << "Sorted by Name.\n"; }

    } while(ch != 5);

    return 0;
}
