#include <bits/stdc++.h> 
using namespace std;
int subarraysXor(vector<int> &arr, int x)
{
   map<int,int> umap;
    int xr = 0, Y, count = 0;
    for(int i = 0;i<arr.size();i++)
    {
        xr ^= arr[i];
       
        if(xr == x)
            count++;
        Y = xr ^ x;
        if(umap.find(Y)!=umap.end())
        {
            count+= umap[Y];
        }
         umap[xr] +=1;
        
    }
    return count;
}