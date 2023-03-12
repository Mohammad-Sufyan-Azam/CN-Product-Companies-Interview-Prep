/*
You are given an integer array/list(ARR) of size N. It contains only 0s, 1s and 2s. Write a solution to sort this array/list in a 'single scan'.
'Single Scan' refers to iterating over the array/list just once or to put it in other words, you will be visiting each element in the array/list just once.
Note:
You need to change in the given array/list itself. Hence, no need to return or print anything. 
*/

#include <iostream>
using namespace std;

void swap(int a, int b, int *arr) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void sort012(int *arr, int n)
{
    // First Solution -
    // int pos0 = 0, pos2 = n-1;
    // for(int i=0; i<n && pos0<n && pos2>-1; i++) {
    //     while (arr[pos2] == 2) {
    //       pos2--;
    //     }
    //     while (arr[pos0] == 0) {
    //       pos0++;
    //     }
    //     if (i > pos2)
    //         break;
    //     if (i > pos0 && arr[i] == 0) {
    //         swap(i, pos0, arr);
    //         pos0++;
    //         if (arr[i] == 2) {
    //             swap(i, pos2, arr);
    //             pos2--;
    //         }
    //     }
    //     if (arr[i] == 2) {
    //         swap(i, pos2, arr);
    //         pos2--;
    //         if (i > pos0 && arr[i] == 0) {
    //           swap(i, pos0, arr);
    //           pos0++;
    //         }
    //     }
    // }
    // Second Solution -(Same approach)
    int pos0 = 0, pos2 = n-1;
    for(int i=0; i<=pos2; i++) {
        if (arr[i] == 0) {
            swap(pos0, i, arr);
            pos0++;
        }
        else if (arr[i] == 2) {
            swap(pos2, i, arr);
            pos2--;
            i--;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort012(arr, n);
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    delete [] arr;
}