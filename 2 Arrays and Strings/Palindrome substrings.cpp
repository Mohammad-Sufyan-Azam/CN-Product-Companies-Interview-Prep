/*
Given a string S, count and return the number of substrings of S that are palindrome.
Single length substrings are also palindromes. You just need to calculate the count, not the substrings.
*/
#include <string.h>
using namespace std;

bool ispalin(string s) {
	for(int i=0; i<s.size()/2; i++) {
		if (s[i] != s[s.size()-i-1])
			return false;
	}
	return true;
}

int countPalindromeSubstrings(char arr[]) {
	// Write your code here
	int n = 0, count = 0;
	for(; arr[n] != '\0'; n++);

	// O(n^2), O(n)
	for(int i=0; i<n; i++) {

		int s = i, e = i;
		while( (s>=0 && e < n) && arr[s] == arr[e] ) {
			s--;
			e++;
			count++;
		}

		s = i, e = i+1;
		while( (s>=0 && e < n) && arr[s] == arr[e] ) {
			s--;
			e++;
			count++;
		}
	}

	return count;
}

