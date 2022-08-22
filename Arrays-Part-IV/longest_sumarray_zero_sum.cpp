#include <bits/stdc++.h>
using namespace std;

int LongestSubsetWithZeroSum(vector<int> arr)
{
    unordered_map<int, int> umap;
    long int prefix_sum = 0;
    int max_c = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        prefix_sum += arr[i];
        if (prefix_sum != 0)
        {
            if (umap.find(prefix_sum) != umap.end())
                max_c = max((i - umap[prefix_sum]), max_c);

            else
                umap.insert({prefix_sum, i});
        }
        else
            max_c = i + 1;
    }
    return max_c;
    // Write your code here
}