#include <iostream>
using namespace std;

int main() {
    int a[100], n, ch, pos, x, f;
    cout << "Enter size: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(int i=0;i<n;i++) cin >> a[i];

    do {
        cout << "\n1.Display 2.Insert 3.Search 4.Exit\nChoice: ";
        cin >> ch;

        if(ch==1){
            for(int i=0;i<n;i++) cout << a[i] << " ";
            cout << endl;
        }

        if(ch==2){
            cout << "Enter pos & value: ";
            cin >> pos >> x;
            if(pos<1 || pos>n+1) cout << "Invalid\n";
            else{
                for(int i=n;i>=pos;i--) a[i] = a[i-1];
                a[pos-1] = x;
                n++;
                cout << "Inserted\n";
            }
        }

        if(ch==3){
            cout << "Enter value to search: ";
            cin >> x;
            f=0;
            for(int i=0;i<n;i++)
                if(a[i]==x){ cout<<"Found at "<<i+1<<endl; f=1; }
            if(!f) cout << "Not found\n";
        }

    }while(ch!=4);

    return 0;
}
