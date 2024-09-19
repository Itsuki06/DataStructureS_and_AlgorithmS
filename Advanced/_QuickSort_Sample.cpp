#include <iostream>

using namespace std;

void Get(int a[], int n) {
    cout << "\n[ ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "]\n";
}

void QuickSort(int a[], int left, int right) {
    int i = left;
    int j = right;
    int key = a[(left + right)/2];

    while (i < j) {
        while (a[i] < key)
            i++;
        while (a[j] > key)
            j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    
    if (left < j) 
        QuickSort(a, left, j);
    if (right > i)
        QuickSort(a, i, right);
}

int main() {
    int n;
    cout << "Nhap so cac so nguyen: ";
    cin >> n;

    int a[n];

    cout << "Nhap day so nguyen: \n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << " \n--- Day so vua nhap ---\n ";
    Get(a, n);

    QuickSort(a, 0, (n - 1));
    cout << " \n--- Day so sau khi sap xep ---\n ";
    Get(a, n);

    return 0;
}