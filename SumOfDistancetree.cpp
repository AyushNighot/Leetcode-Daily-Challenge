Intuition
. If we call dfs for each node and calculate sum of distance for each node it will be O(n*n).
. Let dp[i] denotes sum of distances of all nodes from i then dp[curr] = dp[prev] + nodes in the subtree of curr + (n-nodes in the subtree of curr).
. Let's say we know dp[0] = 8 , dp[1] = dp[0] - subtree[1] + n - subtree[1] = 8 - 1 + 6 - 1 = 12.

-------------------------------------------------------------------------------------------------------------------------------------------------------

Approach
First calculate answer for 0th node and also calculate nodes in each subtree via precomuptation.
Now , considering 0th node as root node , calculate answer for each node using above rec relation and subtree array..


---------------------------------------------------------------------------------------------------------------------------------------------------
Complexity
Time complexity:
O(n)

Space complexity:
O(n)

---------------------------------------------------------------------------------------------------------------------------------------------------

Code
class Solution {
public:
    void dfs(vector<int> adj[],int n,int node,int prev,vector<int> &height,vector<int> &subtree){
        subtree[node]++;
        for(auto &ele:adj[node]){
            if(ele!=prev){
                height[ele] = 1 + height[node];
                dfs(adj,n,ele,node,height,subtree);
                subtree[node] += subtree[ele];
            }
        }
    }
    void rec(vector<int> adj[],int n,int node,int prev,vector<int> &subtree,vector<int> &dp){
        for(auto &ele:adj[node]){
            if(ele!=prev){
                dp[ele] = dp[node] - subtree[ele] + (n-subtree[ele]);
                rec(adj,n,ele,node,subtree,dp);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges){
        vector<int> adj[n];
        for(auto &ele:edges){
            int u = ele[0], v = ele[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> height(n,0),subtree(n,0); // distance from 0 to all other nodes;
        vector<int> dp(n,0); // dp[i] = sum of distances from node i to all other nodes;
        dfs(adj,n,0,-1,height,subtree);
        for(int i=0;i<n;i++) dp[0] += height[i];
        rec(adj,n,0,-1,subtree,dp);
        return dp;
    }
};
