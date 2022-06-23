#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool findTargetInMatrix(vector<vector<int>> &mat, int m, int n, int target)
{

    int lo = 0;
    if (!m)
        return false;
    int hi = (m * n) - 1;

    while (lo <= hi)
    {
        int mid = (lo + (hi - lo) / 2);
        if (mat[mid / n][mid % n] == target)
        {
            return true;
        }
        if (mat[mid / n][mid % n] < target)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return false;
    // Write your code here.
}