/* It is festive time of the year. And Vidit and Parikh loves this festive season, as they get to go to Mela.
Mela brings home their favourite game: "Bursting Balloons". The player has to stand at the leftmost corner of 
the platform. And there are N balloons, lined up from left to right. The aim of the player is to destroy all 
these balloons. Now, a balloon can only be destroyed if player shoots its head. So, to do the needful, he/ she 
shoots an arrow from the left to the right side of the platform, from an arbitrary height he/she chooses. The 
arrow moves from left to right, at a chosen height H until it finds a balloon. The moment when an arrow touches 
a balloon, the balloon gets destroyed and disappears and the arrow continues its way from left to right at a 
height decreased by 1. Therefore, if the arrow was moving at height H, after destroying the balloon it travels 
on height H-1. The player wins this game, if he destroys all the balloons in minimum arrows.
Vidit challenges Parikh to play this game. You have to tell minimum arrows used by Parikh to win the game.*/


#include<bits/stdc++.h>
using namespace std;
int main() {

	// Write your code here
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
	
	// // O(n2), O(n)
	// int arrows = n;
	// unordered_map<int,  int> visited;
	// for(int i=0; i<n; i++) {
	// 	if (visited[i] == 1) {
	// 		continue;
	// 	}
	// int looking_for = arr[i]-1;
	// 	for(int j=i+1; j<n; j++) {
	// 		if (arr[j] == looking_for && visited[j] != 1) {
	// 			arrows--;
	// 			looking_for--;
	// 			visited[j] = 1;
	// 		}
	// 	}
	// }
	// cout<<arrows<<"\n";

	// O(n), O(n)
	int arrows = 0;
	/* 
	arrows = 1
	17->0
	16->1
	*/
	unordered_map<int, int> arrows_present;		// arrow_height:  no_of_arrows_at_that_height
	for(int i=0; i<n; i++) {
		if (arrows_present[arr[i]] <= 0) {
			arrows_present[arr[i]-1]++;
			arrows++;
		}
		else if (arrows_present[arr[i]] > 0) {
			arrows_present[arr[i]]--;
			arrows_present[arr[i]-1]++;
		}
	}
	
	cout<<arrows<<"\n";
	return 0;
}

