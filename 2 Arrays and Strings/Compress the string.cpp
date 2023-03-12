/*
Write a program to do basic string compression. For a character which is consecutively repeated more than once, 
replace consecutive duplicate occurrences with the count of repetitions.
Example: If a string has 'x' repeated 5 times, replace this "xxxxx" with "x5".
The string is compressed only when the repeated character count is more than 1.
Note: Consecutive count of every character in the input string is less than or equal to 9.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* intToString(int no, char *t) {
    int size = 0;
    int n = no;
    while(n>0) {
        n/=10;
        size++;
    }
    n = no;
    int i = 0;
    // cout<<"size="<<size<<" ";
    t[size] = '\0';
    while(n>0) {
        int bg = n%10;
        n/=10;
        // cout<<bg<<" ";
        t[size-i-1] = (char)(bg+'0');
        // cout<<"t["<<size-i-1<<"]="<<t[size-i-1]<<" ";
        i++;
    }
    // cout<<"\n";
    return t;
}

string getCompressedString(string &input) {
    // Write your code here.
    char t[100];
    // cout<<intToString(12, t)<<"\n";
    if (input.size() <= 1)
        return input;
    
    string s="";
    s += input[0];
    char token = input[0];
    int size = 1;
    for(int i=1; i<input.size(); i++) {
        if (input[i] == token) {
            size++;
        }
        else {
            if (size == 1) {
                s += input[i];
                size = 1;
                token = input[i];
            } else {
              s += intToString(size, t);
              s += input[i];
              size = 1;
              token = input[i];
            }
        }
    }

    if (size > 1) {
        s += intToString(size, t);
    }

    return s;
}
