/*
Print the following pattern for the given number of rows.
Assume N is always odd.
Note : There is space after every star.
Pattern for N = 7
*
 * *
  * * *
   * * * *
  * * *
 * *
* 

*/

#include<iostream>
using namespace std;


int main(){
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		if (i <= n / 2 + 1) {
			for (int j = 1; j < i; j++)
				cout << " ";
			for (int j = 1; j <= i; j++)
				cout << "* ";
		}
		else {
			for(int j=1; j<=n-i; j++)
				cout << " ";
			for(int j=1; j<=n-i+1; j++)
				cout<<"* ";
		}
		cout<<"\n";
	}
}




