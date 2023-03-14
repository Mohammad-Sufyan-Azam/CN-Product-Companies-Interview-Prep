/*
You have been given an array/list of integers 'ARR' of size 'N'. Your task is to find two things-
1. The number of elements that are occurring an Odd number of times.
2. The number of elements that are occurring Even a number of times.
For Example:
ARR = [2, 1, 2, 1, 5, 5, 2]    
Output: 1 2 

2 occurs three(odd) times.
1 occurs two(even) times.
5 occurs two(even) times.

So, the total 1 element is occurring an odd number of times and 2 elements are occurring an even number of times.
For each test case, print two single space-separated integers representing the number of odd occurring elements 
and number of even occurring elements respectively.

The output of each test case will be printed a separate line.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> countEvenOdd(vector<int> &arr, int n)
{
	// Write your code here.
	unordered_map<int, int> hash;
	for(int i=0; i<arr.size(); i++) {
		hash[arr[i]] = 0;
	}
	for(int i=0; i<arr.size(); i++) {
		hash[arr[i]]++;
	}
	int odd = 0, even = 0;
	for(auto it : hash) {
		if (it.second%2 != 0)
			odd += 1;
		else
			even += 1;
	}
	vector<int> res(2);
	res[0] = odd;
	res[1] = even;

	return res;
}

