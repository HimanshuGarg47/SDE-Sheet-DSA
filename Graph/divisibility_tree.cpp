#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int ans = 0;
    
    int dfs(vector<vector<int>> &graph, int node)
    {
        if(graph[node].empty())
        return 1;
        
        int count_node = 1;
        for(auto i : graph[node])
        {
             count_node += dfs(graph, i);
        }
        if(count_node%2 == 0)
        {
            ans++;
            return 0;
        }
        else
        return count_node;
    }
    
	int minimumEdgeRemove(int n, vector<vector<int>>edges){
	    int i = 0;
	    
	    vector<vector<int>> graph(n+1, vector<int>());
	    for(auto vec: edges)
	    {
	        graph[min(vec[0], vec[1])].push_back(max(vec[0], vec[1]));
	    }
	    
	    
	    for(auto li: graph)
	    {
	        if(!li.empty())
	        {
	            for(int i = 0;i<li.size(); i++)
	        {
	            cout << li[i] << " ";
	        }
	        cout << endl;
	        }
	        
	    
	    }
	    
	    dfs(graph, 1);
	    return ans;
	    
	    
	}
};

int main()
{
   
}