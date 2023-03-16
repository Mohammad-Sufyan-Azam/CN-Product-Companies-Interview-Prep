/*
You are given an array of integers 'ARR' of length 'N' and an integer Target. Your task is to return all pairs of elements such that they add up to Target.
Note:
We cannot use the element at a given index twice.
*/

#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> twoSum(vector<int>& arr, int target, int n)
{
	// Write your code here. 
	unordered_map<int, int> hash;
	vector<pair<int,int>> res;
	
	for(int i=0; i<arr.size(); i++) {
		if (hash[target-arr[i]] > 0) {
			pair<int, int> p = { arr[i], target - arr[i] };
			res.push_back(p);
			hash[target-arr[i]]--;
		}
		else {
			hash[arr[i]]++;
		}
	}

	if (res.size() == 0) {
		res.push_back(make_pair<int, int>(-1, -1));
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int target;
	cin >> target;
	vector<pair<int, int>> res = twoSum(arr, target, n);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i].first << " " << res[i].second << endl;
	}
	return 0;
}
