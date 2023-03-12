/*
Given an integer array A of size n. Find and print all the leaders present 
in the input array. An array element A[i] is called Leader, if all the 
elements following it (i.e. present at its right) are less than or equal to A[i].
Print all the leader elements separated by space and in the same order they 
are present in the input array.
*/

#include <vector>

void Leaders(int* arr,int len)
{
	/* Don't write main().
	 * Don't read input, it is passed as function argument.
	 * Print your output exactly in the same format as shown. 
	 * Don't print any extra line.
	*/
	// O(n), O(n)
	if (len == 0)
		return;
	else if (len == 1) {
		cout<<arr[0]<<"\n";
		return;
	}
	
	int max = arr[len-1];
	vector<int> temp;
	for(int i=len-2; i>=0; i--) {
		if (arr[i] >= max) {
			temp.push_back(arr[i]);
			max = arr[i];
		}		
	}

	for(int i=temp.size()-1; i>=0; i--)
		cout<<temp[i]<<" ";
	
	cout<<arr[len-1]<<"\n";
}

