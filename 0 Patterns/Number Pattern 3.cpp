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
*/

#include <iostream>
using namespace std;

void printPattern(int n){
	for(int i=1; i<=2*n-1; i++) {
		int no = n;
		if (i<=n) {
			for(int j=1; j<=2*n-1; j++) {
				if (j < i) {
					cout << no << " ";
					no--;
				}
				else if (j <=n) {
					cout << no << " ";
				}
				else if (j<=2*n-i) {
					cout<<no<<" ";
				}
				else {
					no++;
					cout<<no<<" ";
				}
			}
		}
		else {
			for(int j=1; j<=2*n-1; j++) {
				if (j < 2*n-i) {
					cout << no << " ";
					no--;
				}
				else if (j <= n) {
					cout << no << " ";
				}
				else if (j<=i) {
					cout<<no<<" ";
				}
				else {
					no++;
					cout<<no<<" ";
				}
			}
		}
		cout<<"\n";
	}
}


int main() {
    int n;
    cin >> n;
    printPattern(n);
}


