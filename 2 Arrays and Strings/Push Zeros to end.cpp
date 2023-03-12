/*
You have been given a random integer array/list(ARR) of size N. You have been required 
to push all the zeros that are present in the array/list to the end of it. Also, make 
sure to maintain the relative order of the non-zero elements.
Note: Change in the input array/list itself. You don't need to return or print the elements.
You need to do this in one scan of array only. Don't use extra space.
*/

#include <iostream>
using namespace std;

void swap(int a, int b, int *arr) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void pushZeroesEnd(int *arr, int n)
{
  // Write your code here
  int k = 0;
  for (int i = 0; k < n; i++, k++) {
        if (arr[i] == 0) {
            while (k < n && arr[k] == 0) {
                k++;
            }

            swap(i, k, arr);
        }
    }
}

// Main Code:
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    pushZeroesEnd(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    delete[] arr;
}
