#include <iostream>
using namespace std;

int main() {
    int a[100], n, ch, pos, x, f;
    cout << "Enter size: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(int i=0;i<n;i++) cin >> a[i];

    do {
        cout << "\n1.Display 2.Search 3.Delete 4.Exit\nChoice: ";
        cin >> ch;

        if(ch==1){
            for(int i=0;i<n;i++) cout<<a[i]<<" ";
            cout<<endl;
        }

        if(ch==2){
            cout<<"Enter value: ";
            cin>>x;
            f=0;
            for(int i=0;i<n;i++)
                if(a[i]==x){ cout<<"Found at "<<i+1<<endl; f=1; }
            if(!f) cout<<"Not found\n";
        }

        if(ch==3){
            cout<<"Enter position to delete: ";
            cin>>pos;
            if(pos<1 || pos>n) cout<<"Invalid\n";
            else{
                for(int i=pos-1;i<n;i++)
                    a[i]=a[i+1];
                n--;
                cout<<"Deleted\n";
            }
        }

    }while(ch!=4);

    return 0;
}
