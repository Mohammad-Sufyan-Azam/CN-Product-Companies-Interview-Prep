/*
You are given a sentence contained in given string S. Write a function 
which will replace all the words within the sentence whose length is 
even and greater than equal to 4, with a space between the two equal halves of the word.
Space complexity should be O(1).
*/

#include <string.h>
#include<iostream>
using namespace std;

void insert_at(char* S, int mid, char token, int size) {
	char t = S[mid];
	S[mid] = token;
	for(int j=mid+1; j<=size; j++) {
		char t1 = S[j];
		S[j] = t;
		t = t1;
	}
}

void breakWords(char* S)
{
	int size = strlen(S);
	int count = 0;
	for(int i=size-1; i>=0; i--) {
		if (S[i] != ' ') {
			count++;
		}
		else {
			if (count%2 == 0 && count >= 4) {
				int mid = i+count/2+1;
				insert_at(S, mid, ' ', size);
				size++;
			}
			count = 0;
		}
	}
	if (count%2 == 0 && count >= 4) {
		int mid = count/2;
		insert_at(S, mid, ' ', size);
		size++;
	}
}

int main()
{
	char str[100000];
	cin.getline(str,100000);
	breakWords(str);
	cout<<str;
}
