#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {

        // store the resultant
        vector<vector<int>> ans;

        // sorting vector to get combinations in sorted order eg. [1,2,2] not [2,1,2]
        //  (helpful in avoid duplicatis in future)
        sort(candidates.begin(), candidates.end());

        // map for avoiding duplicates vectors
        map<vector<int>, int> umap;

        // calling function
        solve(candidates, 0, target, ans, umap, vector<int>());

        // convert hashmap to list of list
        for (auto it : umap)
        {
            ans.emplace_back(it.first);
        }

        // return the solution
        return ans;
    }

    void solve(vector<int> &candidates, int i, int target, vector<vector<int>> &ans, map<vector<int>, int> &umap, vector<int> temp)
    {
        // we are checking till vector size
        if (i == candidates.size())
        {
            if (target == 0)
            {
                umap[temp] = 1;
            }

            return;
        }

        // we only include element if it is feasible or lte target
        if (candidates[i] <= target)
        {
            temp.push_back(candidates[i]);
            solve(candidates, i + 1, target - candidates[i], ans, umap, temp);
            temp.pop_back();
        }

        // remove duplicates calls eg. [1,1,2,2,2,3,3,3] if i at 0th index than we hould not call 1th index again leads to same subset
        while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1])
            i++;

        solve(candidates, i + 1, target, ans, umap, temp);
    }
};
int main()
{
}