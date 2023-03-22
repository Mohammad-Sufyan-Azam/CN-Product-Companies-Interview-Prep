/* Given an array arr of length N consisting of positive and negative integers, return the 
length of the longest subarray whose sum is zero.*/

#include <bits/stdc++.h>
int lengthOfLongestSubarray(int arr[],int n)
{
    // Write your code here
    int s = 0, final_s = -1, final_e = -1, maxi = 0;
    unordered_map<int, int> hash;
    long long sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
        if (sum == 0) {
            if (maxi < i+1) {
                maxi = i+1;
                final_s = 0;
                final_e = i;
            }
        }
        else if (hash.find(sum) != hash.end()) {
            int cnt = i-hash[sum];
            if (maxi < cnt) {
                maxi = cnt;
                final_s = hash[sum]+1;
                final_e = i;
                // hash[sum] = i;
            }
        }
        else {
            hash[sum] = i;
        }
    }

    return maxi;
}

