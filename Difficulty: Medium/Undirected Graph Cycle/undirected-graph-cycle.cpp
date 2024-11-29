//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
   bool bfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
    queue<pair<int, int>> q;
    q.push({node, -1}); 
    vis[node] = 1;

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int current = p.first;
        int parent = p.second;

        for (auto it : adj[current]) {
            if (vis[it] == 1 && it != parent) {
             
                return true;
            } else if (vis[it] == 0) {
               
                q.push({it, current});
                vis[it] = 1;
            }
        }
    }
    return false; 
}

// bool isCycle(vector<vector<int>>& adj) {
//     int n = adj.size();
//     vector<int> vis(n, 0);

//     for (int i = 0; i < n; i++) {
//         if (!vis[i]) {
//             if (bfs(i, adj, vis)) {
//                 return true;
//             }
//         }
//     }
//     return false;
// }

bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis) {
    vis[node] = 1; // Mark the current node as visited

    for (auto it : adj[node]) {
        if (vis[it] == 1 && it != parent) {
            // A visited neighbor that is not the parent indicates a cycle
            return true;
        } else if (vis[it] == 0) {
            // If the neighbor is not visited, perform DFS on it
            if (dfs(it, node, adj, vis)) {
                return true;
            }
        }
    }

    return false; // No cycle found
}

bool isCycle(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> vis(n, 0);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (dfs(i, -1, adj, vis)) { // Use DFS instead of BFS
                return true;
            }
        }
    }
    return false;
}


};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends