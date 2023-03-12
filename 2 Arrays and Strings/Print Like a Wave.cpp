/*
For a given two-dimensional integer array/list of size (N x M), print 
the array/list in a sine wave order, i.e, print the first column top 
to bottom, next column bottom to top and so on.
*/

#include <iostream>
using namespace std;

void wavePrint(int **input, int nRows, int mCols)
{
    //Write your code here
    for(int c=0; c<mCols; c++) {
        for(int r=0; r<nRows; r++) {
            if (c%2==0) {
                cout<<input[r][c]<<" ";
            }
            else {
                cout<<input[nRows-r-1][c]<<" ";
            }
        }
    }
}

// Main Code:
int main()
{
    int nRows, mCols;
    cin >> nRows >> mCols;
    int **input = new int *[nRows];
    for (int i = 0; i < nRows; i++)
    {
        input[i] = new int[mCols];
        for (int j = 0; j < mCols; j++)
        {
            cin >> input[i][j];
        }
    }
    wavePrint(input, nRows, mCols);
    for (int i = 0; i < nRows; i++)
    {
        delete[] input[i];
    }
    delete[] input;
}
