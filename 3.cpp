#include <iostream>
using namespace std;

int main(){
    int a[100], n, ch, sum, mx;
    cout<<"Enter size: ";
    cin>>n;

    cout<<"Enter elements:\n";
    for(int i=0;i<n;i++) cin>>a[i];

    do {
        cout<<"\n1.Display 2.Sum 3.Max 4.Exit\nChoice: ";
        cin>>ch;

        if(ch==1){
            for(int i=0;i<n;i++) cout<<a[i]<<" ";
            cout<<endl;
        }
        if(ch==2){
            sum=0;
            for(int i=0;i<n;i++) sum+=a[i];
            cout<<"Sum = "<<sum<<endl;
        }
        if(ch==3){
            mx=a[0];
            for(int i=1;i<n;i++)
                if(a[i]>mx) mx=a[i];
            cout<<"Max = "<<mx<<endl;
        }
    }while(ch!=4);

    return 0;
}
