/*
Print the following pattern
Pattern for N = 4
. . . 1
. . 2 3
. 3 4 5
4 5 6 7
The dots represent spaces.
*/

#include<iostream>
using namespace std;


int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++) {
		for(int j=1; j<=n-i-1; j++)
			cout<<" ";
		
		int no = i+1;
		for(int k=1; k<=i+1; k++, no++)
			cout<<no;
		cout<<"\n";
	}
}

