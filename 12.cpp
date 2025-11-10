/*12. Write a C++ program to store first year percentage of students in array. 
Write function for sorting array of floating point numbers in ascending order using  
a) Merge Sort  b) Bubble sort and display top five scores. */

#include <iostream>
using namespace std;

void bubbleSort(float a[], int n) {
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j] > a[j+1])
                swap(a[j], a[j+1]);
}

void merge(float a[], int l, int m, int r) {
    int n1 = m-l+1, n2 = r-m;
    float L[n1], R[n2];
    //creating temporary arrays to store left and right parts
     

    for(int i=0;i<n1;i++) L[i] = a[l+i];
    for(int i=0;i<n2;i++) R[i] = a[m+1+i];
    // Copy actual array values into temp arrays

    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
        a[k++] = (L[i] < R[j]) ? L[i++] : R[j++];
    // ➡ Compare both arrays
    // ➡ Put smaller value back into main array
    while(i<n1) a[k++] = L[i++];
    while(j<n2) a[k++] = R[j++];
    //➡ Copy remaining elements
}

void mergeSort(float a[], int l, int r) {
    if(l < r) {
        int m = (l+r)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}



void topFive(float a[], int n) {
    cout << "\nTop Five Scores:\n";
    for(int i=n-1, c=0; i>=0 && c<5; i--, c++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    float a[50];
    int n, ch;

    cout << "Enter number of students: ";
    cin >> n;
    cout << "Enter percentages:\n";
    for(int i=0;i<n;i++) cin >> a[i];

    do {
        cout << "\n1.Bubble Sort 2.Merge Sort 3.Display Top 5 4.Exit\nChoice: ";
        cin >> ch;

        if(ch==1) {
            bubbleSort(a, n);
            cout << "Sorted using Bubble Sort.\n";
        }
        if(ch==2) {
            mergeSort(a, 0, n-1);
            cout << "Sorted using Merge Sort.\n";
        }
        if(ch==3) {
            topFive(a, n);
        }

    } while(ch != 4);

    return 0;
}



/*

## ✅ **Algorithm**

1. Start the program.

2. Read the number of students `n`.

3. Declare an array to store `n` floating-point percentages.

4. Accept `n` percentage values from the user.

5. Display a menu with following choices:

   * Bubble Sort
   * Merge Sort
   * Display Top 5
   * Exit

6. Read the user’s choice.

### ✅ **Bubble Sort**

7. For each element in the array, compare it with the next element.
8. If the current element is greater than the next, swap them.
9. Repeat this process until the whole array becomes sorted in ascending order.
10. Display a message “Sorted using Bubble Sort”.

### ✅ **Merge Sort**

11. Recursively divide the array into two halves until single elements remain.
12. Merge the two sorted halves by comparing elements and putting them back in sorted order.
13. After merging all parts, the array becomes sorted.
14. Display a message “Sorted using Merge Sort”.

### ✅ **Display Top Five**

15. After array is sorted, print the last five elements (highest percentages), or print all if less than five students.

16. Keep showing menu until the user selects Exit.

17. Stop the program.



*/