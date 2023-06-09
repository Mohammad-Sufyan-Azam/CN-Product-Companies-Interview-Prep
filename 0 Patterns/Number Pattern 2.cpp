/*
Print the following pattern for n number of rows.
Note: each line consist of equal number of characters + spaces. 
Suppose you are printing xth line for N=n. You need to print 1..x followed by (n-x) spaces, 
again (n-x) spaces followed by x..1
For eg. N = 5 
1        1
12      21
123    321
1234  4321
1234554321
*/

#include<iostream>
using namespace std;

int main() {
	// Write your code here
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		int no = 1;
		for(int j=1; j<=i; j++, no++)
			cout<<no;
		for(int k=1; k<=2*(n-i); k++)
			cout<<" ";
		no--;
		for(int j=1; j<=i; j++, no--)
			cout<<no;
		cout<<"\n";
	}
}
