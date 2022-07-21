#include <bits/stdc++.h>
using namespace std;

// brute force - solved myself
vector<vector<int>> pairSum(vector<int> &arr, int s){
   // int n = arr.size();
    vector<vector<int>> ans;
    map<int,int> umap;
    for(int i : arr)
    {
        int count = umap[s-i];
        int first = i, second = s-i;
        
        while(count--)
        {
            ans.push_back({min(first,second), max(first,second)});
        }
        umap[i]++;
        
    }
    sort(ans.begin(),ans.end());
    return ans;
}


//  using hasp (after see sol.)
vector<vector<int>> pairSum(vector<int> &arr, int s){
   // int n = arr.size();
    vector<vector<int>> ans;
    map<int,int> umap;
    for(int i : arr)
    {
        int count = umap[s-i];
        int first = i, second = s-i;
        
        while(count--)
        {
            ans.push_back({min(first,second), max(first,second)});
        }
        umap[i]++;
        
    }
    sort(ans.begin(),ans.end());
    return ans;
}