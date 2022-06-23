#include <bits/stdc++.h> 
int modularExponentiation(int x, int n, int m) {
	// Write your code here.
    int ans = 1;
    while(n > 0)
    {
        if(n&1)
        {
           ans = (1LL * ans*x)%m;
            n--;
        }
      
            x = (1LL * x*x)%m;
            n >>= 1;
       
        
    }
    return ans;
}