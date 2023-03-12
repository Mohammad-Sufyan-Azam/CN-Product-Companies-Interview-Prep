/*
Print the following pattern for the given number of rows.
Pattern for N = 5
 1    2   3    4   5
 11   12  13   14  15
 21   22  23   24  25
 16   17  18   19  20
 6    7    8   9   10
Input format : N (Total no. of rows)
Output format : Pattern in N lines
*/

#include <iostream>
using namespace std;

// n - number of rows given
void printPattern(int n){
	// Write your code here
	int limit = n/2;
	if (n%2 != 0)
		limit++;
	
	int no;
	for(int i=1; i<=n; i++) {
		if (i <= limit) {
			no = (i-1) * 2 * n + 1;
			for (int j = 1; j <= n; j++, no++) {
				cout << no << " ";
			}
			no = (i-1) * 2 * n + 1;;
		}
		else if (n%2 == 0 && i == limit+1) {
			no += n;
			for(int j=1; j<=n; j++, no++)
				cout<<no << " ";
			no -= n;
		} 
		else {
			if (i == limit+1)
				no -= n;
			else
				no -= 2*n;
			
			for (int j = 1; j <= n; j++, no++)
				cout << no << " ";
			
			no -= n;
		}
		cout<<"\n";
	}
}

int main() {
    int n;
    cin>>n;
    printPattern(n);
}
