/*
Given an N*N integer square matrix, rotate it by 90 degrees in anti-clockwise direction.
Try doing it without any extra space.
Note : You just need to change in the given input itself. No need to return or print anything.
*/

void rotate(int **input, const int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Taking input and printing output is handled automatically.
     */
    //O(n), O(n)
     int i=0, j=0;
     int arr[n][n];

     for(int i=n-1; i>=0; i--) {
         for(int j=0; j<n; j++) {
             arr[n-i-1][j] = input[j][i];
         }
     }

     for(int i=0; i<n; i++) {
         for(int j=0; j<n; j++) {
             input[i][j] = arr[i][j];
         }
     }
     
}

