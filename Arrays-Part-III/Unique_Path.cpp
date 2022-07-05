#include <bits/stdc++.h> 
using namespace std;
// Detail explanation link - https://takeuforward.org/data-structure/grid-unique-paths-count-paths-from-left-top-to-the-right-bottom-of-a-matrix/
// Combinatorics approach
int uniquePaths(int m, int n) {
    int nn = m+n-2;
    int r = m-1,res = 1;
    for(int i = 1;i<=r;i++)
    {
       res = res * (nn-r+i)/i;
    }
    return res;
    
}


// dynamic programming approach
int grid(int i,int j,int &m,int &n,vector<vector<int>> &dp)
{
    if(i == m-1 && j==n-1)return 1;
    
    if(i == m || j == n)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    return dp[i][j] = grid(i+1,j,m,n,dp) + grid(i,j+1,m,n,dp);
}
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return grid(0,0,m,n,dp);
	// Write your code here.
}


// brute force approach
void grid(int i,int j,int m,int n,int &count)
{
    if(i == m && j == n)
    {
        count++;
        return;
    }
    if(i < m)
    grid(i+1,j,m,n,count);
    
    if(j < n)
    grid(i,j+1,m,n,count);
    
}


int uniquePaths(int m, int n) {
	// Write your code here.
     int count = 0;
    grid(1,1,m,n,count);
    return count;
}
