#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Binary power function for O(logn) power calculations
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

long long ways(int n)
//If the places are  three 
{   if (n==3){
    return 24;
}  

//For rest n, 3*p(3*n-1), you can come upto this through permutations and combinations
 long long p = binpow(4,n-3);
 return 3*p*(3*n-1);
}

//Main function
int main(){
int n;
cin >> n;
cout<< ways(n);
return 0;
}