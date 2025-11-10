#include <iostream>
using namespace std;

void bubbleSort(string a[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(a[j] > a[j+1])  // alphabetical comparison
                swap(a[j], a[j+1]);
        }
    }
}

int main() {
    string books[50];
    int n;

    cout << "Enter number of books: ";
    cin >> n;

    cout << "Enter book titles:\n";
    for(int i=0; i<n; i++)
        cin >> books[i];

    bubbleSort(books, n);

    cout << "\nBooks Sorted Alphabetically:\n";
    for(int i=0; i<n; i++)
        cout << books[i] << endl;

    return 0;
}


/*Sure ✅
Here is a **slightly detailed but still short** algorithm, perfect for journals and viva:

---

## ✅ **Algorithm (Bubble Sort for Book Titles)**

1. Start the program.

2. Ask the user to enter the number of books `n`.

3. Create a string array to store book titles.

4. Read `n` book titles from the user and store them in the array.

5. Apply **Bubble Sort** to arrange titles alphabetically:

   * Repeat the process for `n-1` passes.
   * In each pass, compare two adjacent titles.
   * If the first title comes **after** the second alphabetically, swap them.
   * After every pass, the largest title (in alphabetical order) moves toward the end.

6. After sorting completes, print all book titles in alphabetical order.

7. Stop the program.

---

### ✅ Small viva explanation

* We use a string array to store titles.
* Bubble sort compares titles alphabetically using `>` operator.
* Titles get arranged from **A → Z**.
* Sorting improves ease of browsing in an online bookstore.

---

If you want, I can add **author + price** fields and sort based on title using bubble sort.
*/