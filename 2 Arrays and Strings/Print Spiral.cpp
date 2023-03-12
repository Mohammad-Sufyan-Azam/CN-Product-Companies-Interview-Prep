/*
For a given two-dimensional integer array/list of size (N x M), print it in a spiral form. That is, you need to print in the order followed for every iteration:
a. First row(left to right)
b. Last column(top to bottom)
c. Last row(right to left)
d. First column(bottom to top)
 Mind that every element will be printed only once.
*/

void spiralPrint(int **arr, int nRows, int nCols)
{
    //Write your code here
    if (nRows == 0 && nCols == 0)
        return;
    
    int r = 0, c = 0;
    int count = 0;
    for(int i=0; ; i++) { //i=2, r=2, c=2, nRows=5, nCols=6    
        // cout<<"r="<<r<<" c="<<c<<"\n";
        bool down = false;
        for(; c<nCols-i; c++) {
            cout<<arr[r][c]<<" ";
            // cout<<"Rarr["<<r<<"]["<<c<<"]="<<arr[r][c]<<"\n";
            count++;
        }
        c--; r++;
        for(; r<nRows-i; r++) {
            cout<<arr[r][c]<<" ";
            down = true;
            // cout<<"Darr["<<r<<"]["<<c<<"]="<<arr[r][c]<<"\n";
            count++;
        }
        
        r--; c--;
        if (down) {
          for (; c >= i; c--) {
            cout<<arr[r][c]<<" ";
            // cout << "Larr[" << r << "][" << c << "]=" << arr[r][c] << "\n";
            count++;
          }
        }
        c++; r--;
        for (; r >= i+1; r--) {
            cout << arr[r][c] << " ";
            // cout<<"Uarr["<<r<<"]["<<c<<"]="<<arr[r][c]<<"\n";
            count++;
        }
        r++; c++;
        // cout<<"r="<<r<<" c="<<c<<"\n\n";
        if (count >= nRows*nCols)
            break;
    }

}
