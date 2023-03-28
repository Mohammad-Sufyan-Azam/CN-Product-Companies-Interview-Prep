int sumOfDigits(int n) {
    // Write your code here
    if (n/10 == 0)
        return n;
    
    int n1 = n%10;
    n = n/10;
    return sumOfDigits(n)+n1;
}


