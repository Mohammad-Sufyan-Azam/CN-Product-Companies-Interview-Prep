/*
For a given two strings, 'str1' and 'str2', check whether they are a permutation of each other or not.
Permutations of each other
Two strings are said to be a permutation of each other when either of the string's characters can be rearranged so that it becomes identical to the other one.

Example: 
str1= "sinrtg" 
str2 = "string"

The character of the first string(str1) can be rearranged to form str2 and hence we can say that the given strings are a permutation of each other.
*/

#include <bits/stdc++.h>

bool isPermutation(char input1[], char input2[]) {
    // // O(nlogn), O(1)
    // int size1 = 0, size2 = 0;
    // for(int i=0; input1[i] != '\0'; i++)
    //     size1++;
    // for(int i=0; input2[i] != '\0'; i++)
    //     size2++;
    
    // if(size1 != size2)
    //     return false;
    
    // sort(input1, input1+size1);
    // sort(input2, input2+size2);
    
    // for(int i=0; i<size1; i++)
    //     if (input1[i] != input2[i])
    //         return false;

    // return true;

    // O(n), O(n)
    int size1 = 0, size2 = 0;
    for(int i=0; input1[i] != '\0'; i++)
        size1++;
    for(int i=0; input2[i] != '\0'; i++)
        size2++;
    
    if(size1 != size2)
        return false;

    map<char, int> map1;
    for(int i=0; input1[i] != '\0'; i++) {
        map1[input1[i]] += 1;
        map1[input2[i]] -= 1;
    }
    map<char, int>::iterator it = map1.begin();
    for(; it != map1.end(); it++) {
        if (it->second != 0)
            return false;
    }
    return true;
}