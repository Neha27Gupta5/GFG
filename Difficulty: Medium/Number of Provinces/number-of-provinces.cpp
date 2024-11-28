//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(vector<int>&vis,vector<vector<int>> &adj ,int node){
        vis[node]=1;
        for(int i=0;i<adj.size();i++){
            if(adj[node][i]==1 && vis[i]==0){
                dfs(vis,adj,i);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int v) {
        
        vector<int>vis(v,0);
        int count=0;
        
        for(int i=0;i<v;i++){
            if(!vis[i]){
                dfs(vis,adj,i);
                count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends