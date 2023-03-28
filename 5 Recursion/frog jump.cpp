/*
There is a frog on the '1st' step of an 'N' stairs long staircase. The frog wants to reach the 'Nth' stair. 
'HEIGHT[i]' is the height of the '(i+1)th' stair.If Frog jumps from 'ith' to 'jth' stair, the energy lost in 
the jump is given by absolute value of ( HEIGHT[i-1] - HEIGHT[j-1] ). If the Frog is on 'ith' staircase, he can 
jump either to '(i+1)th' stair or to '(i+2)th' stair. Your task is to find the minimum total energy used by the 
frog to reach from '1st' stair to 'Nth' stair.
*/

#include <bits/stdc++.h> 
int min(int a, int b) {
    if (a >= b)
        return b;
    return a;
}

int memoization(vector<int>& dp, vector<int>& heights, int n) {
    // Time: O(2*n), Space: O(n)
    if (dp[n-1] != -1)
        return dp[n-1];
    
    if (n == 1) {
        dp[n-1] = 0;
        return dp[n-1];
    }
    if (n == 2) {
        dp[n-1] = abs(heights[0]-heights[1]);
        return dp[n-1];
    }

    int one_jump = memoization(dp, heights, n-1) + abs(heights[n-1]-heights[n-2]);
    int two_jump = memoization(dp, heights, n-2) + abs(heights[n-1]-heights[n-3]);

    dp[n-1] = min(one_jump, two_jump);
    return dp[n-1];
}

int tabulation(vector<int>& heights, int n) {
    // // Time: O(n), Space: O(n)
    // vector<int> dp(n, -1);
    // dp[0] = 0;
    // dp[1] = abs(heights[1]-heights[0]);
    // for(int i=2; i<n; i++) {
    //     int one_jump = dp[i-1]+abs(heights[i-1]-heights[i]);
    //     int two_jump = dp[i-2]+abs(heights[i-2]-heights[i]);
    //     dp[i] = min(one_jump, two_jump);
    // }

    // return dp[n-1];

    // Space Optimization
    // // Time: O(n), Space: O(1)
    int first_prev = 0;
    if (n==1)
        return 0;
    int second_prev = abs(heights[1]-heights[0]);
    for(int i=2; i<n; i++) {
        int one_jump = first_prev + abs(heights[i-1]-heights[i]);
        int two_jump = second_prev + abs(heights[i-2]-heights[i]);
        first_prev = second_prev;
        second_prev = min(one_jump, two_jump);
    } 

    return second_prev;
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    // return memoization(dp, heights, n);  // top-down
    return tabulation(heights, n);      // bottom-up
}


