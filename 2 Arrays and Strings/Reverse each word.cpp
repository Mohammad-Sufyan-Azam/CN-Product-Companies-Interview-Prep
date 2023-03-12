/*
Aadil has been provided with a sentence in the form of a string as a function parameter. The task is to implement a function so as to print the sentence such that each word in the sentence is reversed.
Example:
Input Sentence: "Hello, I am Aadil!"
The expected output will print, ",olleH I ma !lidaA".
*/

void reverse(int start, int end, char arr[]) {
    for(int i=start, ptr=0; i<=(end+start)/2; i++, ptr++) {
        char t = arr[i];
        arr[i] = arr[end-ptr];
        arr[end-ptr] = t;
    }
}

void reverseEachWord(char input[]) {
    // Write your code here
    int start = 0, i = 0;
    for(; input[i] != '\0'; i++) {
        if (input[i] == ' ') {
            reverse(start, i-1, input);
            start = i+1;
        }
    }
    reverse(start, i-1, input);
}
