/*
Print the following pattern
Pattern for N = 4
4 4 4 4 4 4 4 
4 3 3 3 3 3 4 
4 3 2 2 2 3 4 
4 3 2 1 2 3 4 
4 3 2 2 2 3 4 
4 3 3 3 3 3 4 
4 4 4 4 4 4 4 
Input Format :
N (Total no. of rows)
Output Format :
Pattern in N lines
*/

#include <iostream>
using namespace std;

int main() {
    /*  Read input as specified in the question.
     * Print output as specified in the question.
     */
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        for(int j=1; j<=n-i-1; j++)
            cout<<" ";
        int no = i+1;
        for(int k=1; k<=i+1; k++, no++)
            cout<<no;
        int temp = no-2;
        for(int l=1; l<=i; l++, temp--)
            cout<<temp;
        cout<<"\n";
    }
}
