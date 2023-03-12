/*
Given 2 sorted arrays (in increasing order), find a path through the intersections that produces maximum sum and return the maximum sum.
That is, we can switch from one array to another array only at common elements.
If no intersection element is present, we need to take sum of all elements from the array with greater sum.
*/

#include <vector.h>

long max(long a, long b) {
    if (a>=b)
        return a;
    return b;
}

long maxPathSum(int a1[], int a2[], int m, int n)
{
    /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
     */
    vector<int> intersected_points;
    int i=0, j=0;
    while(i < m && j < n) {
        if (a1[i] < a2[j]) {
            i++;
        }
        else if (a1[i] > a2[j]) {
            j++;
        }
        else {
            intersected_points.push_back(a1[i]);
            i++;
            j++;
        }
    }
    // cout<<"Array: ";
    // for(int a=0; a<intersected_points.size(); a++)
    //     cout<<intersected_points[a]<<" ";
    // cout<<"\n";

    long maxSum = 0;
    i = 0;
    int ptr1 = 0, ptr2 = 0;
    bool flag1 = 0, flag2 = 0;

    while(true) {
        if (ptr1 >= m && ptr2 >= n)
            break;

        long sum1 = 0, sum2 = 0;
        for(; ptr1<m; ptr1++) {
            if (i < intersected_points.size() && a1[ptr1] == intersected_points[i]) {
                sum1 += a1[ptr1];
                flag1 = 1;
                ptr1++;
                break;
            }
            sum1 += a1[ptr1];
        }

        for (; ptr2 < n; ptr2++) {
          if (i < intersected_points.size() &&  a2[ptr2] == intersected_points[i]) {
            sum2 += a2[ptr2];
            flag2 = 1;
            ptr2++;
            break;
          }
          sum2 += a2[ptr2];
        }
        // cout<<"Numbers: "<<sum1<<" "<<sum2<<"\n";
        maxSum += max(sum1, sum2);

        if (flag1 == 1 && flag2 == 1) {
          i++;
          flag1 = 0;
          flag2 = 0;
        }
    }

    return maxSum;
}

