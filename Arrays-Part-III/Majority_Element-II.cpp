#include <bits/stdc++.h> 
using namespace std;
vector<int> majorityElementII(vector<int> &arr)
{
    vector<int> res;
    int con = floor(float(arr.size()/3));
    //cout << "floor => " << con << endl;
    map<int,int> umap;
    for(int i : arr)
    {
        if(umap.find(i) == umap.end())
        {
             umap[i] = 1;
        } 
        else
        {
              if(umap[i]!=0)
              {
                   umap[i]+=1;
               
              }  
            }
            if(umap[i] > con)
                {
                     res.push_back(i);
                    umap[i] = 0;
                }
            
        }
        
    
    return res;
    // Write your code here.

}