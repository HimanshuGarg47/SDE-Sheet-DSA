#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-consecutive-sequence/

int parent(unordered_set<int> &umap, int i)
{
    if (umap.find(i + 1) == umap.end())
        return 1;
    else
        return 1 + parent(umap, i + 1);
}
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
    unordered_set<int> umap;
    for (auto i : arr)
        umap.insert(i);

    int max_c = 0;
    for (auto i : arr)
    {
        if (umap.find(i - 1) == umap.end())
        {
            int temp = parent(umap, i);
            max_c = max(temp, max_c);
        }
    }
    return max_c;
    // Write your code here.
}