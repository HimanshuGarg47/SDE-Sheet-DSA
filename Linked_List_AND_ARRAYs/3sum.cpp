#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;

        int i, j, k, n, sum;

        i = 0;
        n = nums.size();

        sort(nums.begin(), nums.end());

        while (i < n - 2)
        {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
            {
                j = i + 1;
                k = n - 1;
                sum = 0 - nums[i];
                while (j < k)
                {

                    if (nums[j] + nums[k] == sum)
                    {

                        ans.push_back(vector<int>({nums[i], nums[j], nums[k]}));

                        while (j < k && (nums[j] == nums[j + 1]))
                            j++;
                        while (j < k && (nums[k] == nums[k - 1]))
                            k--;
                        j++;

                        k--;
                    }
                    else if (sum > 0)
                    {

                        k--;
                    }

                    else
                    {
                        j++;
                    }
                }
            }

            i++;
        }

        return ans;
    }
};
int main()
{
}