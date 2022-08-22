#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> nums, int target, int n)
{

    vector<vector<int>> res;
    int n = nums.size();
    if(n == 0)
    return res;
    sort(nums.begin(), nums.end());
    int prev_front, prev_back;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int front = j + 1, back = n - 1, sum_target = target - nums[i] - nums[j];

            while (front < back)
            {
                if (sum_target < target)
                    ++front;
                else if (sum_target > target)
                    --back;
                else
                {
                    vector<int> temp = {nums[i],nums[j],nums[front],nums[back]};
                    res.push_back(temp);
                    // prev_front = nums[front], prev_back = nums[back];
                    // return "Yes";
                while (front < back && nums[front] == temp[2])
                    ++front;
                while (front < back && nums[back] == temp[3])
                    --back;
                }
            }
            while (j + 1 < n && nums[j] == nums[j + 1])
                ++j;
        }
        while (i + 1 < n && nums[i] == nums[i + 1])
            ++i;
    }
return res;
}
