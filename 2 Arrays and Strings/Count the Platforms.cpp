/*
Given two arrays (both of size n), one containing arrival time of trains
and other containing the corresponding trains departure time (in the form 
of an integer) respectively. Return the minimum number of platform required, 
such that no train waits.
Arrival and departure time of a train can't be same.
*/

#include<bits/stdc++.h>

int maximum(int a, int b) {
  if (a>=b)
    return a;
  return b;
}

int platformsNeeded(int arrival[], int departure[], int n) {
     // Link: https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/

    sort(arrival, arrival+n);
    sort(departure, departure+n);
    
    int ptr1 = 0, ptr2 = 0;
    int no_of_platforms = 0;
    int max = 0;
    while(ptr1 < n && ptr2 < n) {
      if (arrival[ptr1] < departure[ptr2]) {
        no_of_platforms++;
        ptr1++;
        max = maximum(no_of_platforms, max);
      }
      else {
        no_of_platforms--;
        ptr2++;
      }
    }

    return max;
}
