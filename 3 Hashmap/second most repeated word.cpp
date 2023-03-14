/*
You are given an array of strings ‘ARR’. You have to find out the second most repeated word in the array ‘ARR’. 
It is guaranteed every string occurs a unique number of times in the array. If there is only one unique string in the array, return an empty string.
Example:-
N = 5
S = [‘aaa’, ‘bbb’, ‘ccc’, ‘aaa’, ‘bbb’, ‘aaa’]

ANSWER:- The answer should be ‘bbb’ as it is repeated 2 times and is the second most repeated word in the array [after the word ‘aaa’ which is repeated 3 times].
*/

#include <bits/stdc++.h>
using namespace std;

string second_repeat(vector<string> &arr, int n){
    // Write your code here.
    unordered_map<string, int> count;
    for(int i=0; i<arr.size(); i++)
        count[arr[i]]++;
    
    if (count.size() <= 1)
        return "";
    
    int max = -1, second_max = -1;
    string res;
    for(auto it: count) {
        if (max < it.second) {
            max = it.second;
            // cout<<max<<" ";
        }
    }
    for(auto it: count) {
        if (second_max < it.second && it.second != max) {
            second_max = it.second;
            // cout<<second_max<<" ";
            res = it.first;
        }
    }
    // cout<<"\n";

    return res;
}
