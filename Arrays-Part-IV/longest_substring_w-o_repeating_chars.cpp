#include <bits/stdc++.h>
using namespace std; 
// optimized solution 1
int uniqueSubstrings(string input)
{
  unordered_set<int> uset;
  int l = 0, r = 0, n = input.length(), max_len = INT_MIN;
  while (r < n)
  {
    if (uset.find(input[r]) != uset.end())
      while (l < r && uset.find(input[r]) != uset.end())
      {

        uset.erase(input[l]);
        l++;
      }
    else
    {
      uset.insert(input[r]);
      max_len = max(max_len, r - l + 1);
      r++;
    }
  }
  return max_len;
}


// optimized solution 2
int uniqueSubstrings(string input)
{
    unordered_map<int,int> umap;   // store index of element to reduce left pointer movement
    int l = 0, max_len = INT_MIN;
    for(int r = 0;r < input.length(); r++) // r < n
    {
        if(umap.find(input[r]) != umap.end())
        {
            l = max(umap[input[r]] + 1,l);  //IMP!! ele found is beyond l, we are not going to update, bcz we are not removing the previous left index who was duplicate
        }
        
           umap[input[r]] = r;
            max_len = max(max_len,r-l+1);
            
        
    }
    return max_len;
    
}