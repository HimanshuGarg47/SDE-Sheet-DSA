#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
	int votes = 0, candidate = -1;
    int count = floor(n/2);
    for(int i = 0;i<n;i++)
    {
        if(votes == 0)
        {
            candidate = arr[i];
            
        }
         if(candidate == arr[i])
        {
            votes += 1;
        }
        else
            votes -=1;
        
    }
    //cout << "candidate => " << candidate << endl;
    votes = 0;
    for(int i = 0;i<n;i++)
    {
        if(candidate == arr[i])
            votes +=1;
    }
   if(votes > count)
        return candidate;
     return -1;
}