/*
For a given two strings, 'str1' and 'str2', check whether they are a permutation of each other or not.
Permutations of each other
Two strings are said to be a permutation of each other when either of the string's characters can be rearranged so that it becomes identical to the other one.

Example: 
str1= "sinrtg" 
str2 = "string"
*/

#include <bits/stdc++.h>
using namespace std;

bool isPermutation(char input1[], char input2[]) {
    
    // // O(nlogn), O(1)
    // int n = strlen(input1), m = strlen(input2);
    // if (n != m)
    //     return false;
    
    // sort(input1, input1+n);
    // sort(input2, input2+m);

    // for(int i=0; i<n; i++) {
    //     if (input1[i] != input2[i])
    //         return false;
    // }
    // return true;

    // O(n), O(n)
    unordered_map<char, int> hash1;
    int n = strlen(input1), m = strlen(input2);
    if (n != m)
        return false;
    
    for(int i=0; i<n; i++) {
        hash1[input1[i]]++;
        hash1[input2[i]]--;
    }

    for(auto it: hash1) {
        if (it.second != 0) {
            return false;
        }
    }
    return true;
}
