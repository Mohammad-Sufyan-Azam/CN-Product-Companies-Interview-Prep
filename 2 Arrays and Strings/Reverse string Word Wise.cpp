/*
Reverse the given string word wise. That is, the last word in given 
string should come at 1st place, last second word at 2nd place and 
so on. Individual words should remain as it is.
*/

#include <iostream>
using namespace std;

void reverse(int s, int e, char arr[]) {
    int last = e-1; //6 ..7.. 8
    for(int i=s; i<(s+e)/2; i++) {
        char t = arr[i];
        arr[i] = arr[last];
        arr[last] = t;
        last--;
    }
}

void reverseStringWordWise(char input[]) {
    // Write your code here
    // O(n)
    int size = 0;
    for(; input[size] != '\0'; size++);
    
    reverse(0, size, input);
    // cout<<input<<"\n";
    int start = 0, end = 0;
    for(int i=0; i<size; i++) {
        if (input[i] != ' ') {
            end++;
        }
        else {
            // cout<<"s="<<start<<" e="<<end;
            reverse(start, end, input);
            // cout<<" | "<<input<<"\n";
            start = i+1;
            end = i+1;
        }
    }
    // cout<<"s="<<start<<" e="<<end<<"\n";
    reverse(start, end, input);
}
