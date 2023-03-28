/*
Given a string ‘STR’ of length 'N'. Implement the atoi function. If there are no numbers in the string, return 0.
In other words, given a string ‘STR’ convert the string to an integer.
Example :
Give string : ”123456”, we return the integer value ‘123456’.
The string can contain any ascii characters. If the character in the string is not a number, ignore it.
Example :
Given string : ”#messi10”, we return 10 as other characters “messi” are not numbers hence we skip them.
*/

#include <bits/stdc++.h> 

int recurse(string str, int n) {
    if (n == -1)
        return 0;
    
    int ans = recurse(str, n-1);
    if (str[n] <= '9' && str[n] >= '0') {
        ans = ans*10 + (str[n]-'0');
        // cout<<ans;
    }
    return ans;
}


int atoi(string str) {
    // Write your code here.
    // cout<<"\n";
    int ans = recurse(str, str.size()-1);
    // int ans = recursive(str, 0, str.size()-1, false);    // for bottom-up approach
    if (str[0] == '-')
        return -ans;
    return ans;
}

