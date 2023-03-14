/*
Let’s define the beauty of an array to be equal to the value present in the array, which 
is having the maximum frequency. If there are multiple such values, then the smallest among 
such values will be selected.
Alice gave Bob an array ‘A’ of size ‘N’ and asked him to find the beauty of the frequencies 
of the values present in the array. In simple words, Bob first needs to find the frequencies 
of all values present in the array, then find the beauty of this frequency array.
Help Bob in finding the beauty of the frequencies of the values present in the array.

Sample Input 1:
2
5
1 2 1 2 3
3
7 5 5
Sample Output 1:
2
1
Explanation for Sample Input 1:
In the first test case, the frequency of 1, 2 and 3 is 2, 2 and 1, respectively. So the 
frequency array becomes [2, 2, 1]. Beauty of this array is 2 as it has the highest frequency.
In the second test case, the frequency of 7 and 5 is 1 and 2, respectively. So the frequency 
array becomes [1, 2]. In this array both elements have the same frequency, so we select the smaller one, i.e. 1.
*/

#include <bits/stdc++.h> 
using namespace std;

int mini(int a, int b) {
    if (a<=b)
        return a;
    return b;
}

int maxFrequency(vector<int> A)
{
    // Write your code here.
    unordered_map<int, int> hash;
    for(int i=0; i<A.size(); i++)
        hash[A[i]]++;
    
    unordered_map<int, int> freq;
    for(auto it: hash) {
        freq[it.second]++;
    }

    int max = -1, ans;
    for(auto it: freq) {
        if (it.second > max) {
            max = it.second;
            ans = it.first;
        }
        else if (it.second == max) {
            ans = mini(ans, it.first);
        }
    }

    return ans;
}
