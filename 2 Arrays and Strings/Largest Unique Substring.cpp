/*
Given a string S, find the largest substring with no repetition i.e. largest substring which contain all unique characters.
*/

// input - given string
#include <bits/stdc++.h>
using namespace std;
// output - output string that contains largest unique substring

void findLargestUniqueSubstring(char input[], char output[]) {
	// Write your code here
	int n = strlen(input);
	int s = 0, e = 0, p1 = 0, p2 = 0;
	unordered_map<char, int> hash;
	int ans = -1;
	for(e=0; e<n; e++) {
		if(hash.find(input[e]) == hash.end()) {
			hash[input[e]] = 1;
			if(e-s+1>ans) {
				ans =max(ans, e-s+1);
				p2=e;
				p1=s;
			}
		}
		else {
			while(input[s] != input[e]) {
				hash.erase(input[s]);
				s++;
			}
			s++;
		}
	}
	// cout<<ans<<"\n";
	int ptr = 0;
	for(int i = p1; i <= p2; i++) {
		output[ptr++] = input[i];
		// cout<<output[i];
	}
	// cout<<p1<<" "<<p2<<"\n";
	output[ptr] = '\0';
	
	// cout<<"\n";
}

