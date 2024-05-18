//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void solve(vector<int> adj[],int v, vector<int>&ans, vector<int>&vis){
          queue<int>q;
       q.push(v);
       vis[v]=1;
       while(!q.empty()){
           int top=q.front();
           q.pop();
           ans.push_back(top);
           for(int i=0;i<adj[top].size();i++){
               if(vis[adj[top][i]]==-1){
                   q.push(adj[top][i]);
                   vis[adj[top][i]]=1;
               }
              
           }
       }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int>ans;
    vector<int>vis(V,-1);
    // for(int i=0;i<V;i++){
    //     if(vis[i]==-1){
    //         solve(adj,i,ans,vis);
    //     }
    // }
    solve(adj,0,ans,vis);
  return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends