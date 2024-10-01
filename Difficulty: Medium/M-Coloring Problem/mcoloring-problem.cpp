//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
   
  bool possible(bool graph[101][101], vector<int>& color, int node, int c, int n) {
        for (int i = 0; i < n; i++) {
            if (graph[node][i] && color[i] == c) {
                return false;
            }
        }
        return true;
    }

    bool solve(bool graph[101][101], int m, int n, vector<int>& color, int node) {
        if (node == n) {
            return true;
        }

        for (int c = 0; c < m; c++) {
            if (possible(graph, color, node, c, n)) {
                color[node] = c;
                if (solve(graph, m, n, color, node + 1)) {
                    return true;
                }
                color[node] = -1;
            }
        }
        return false;
    }

    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> color(n, -1);
        return solve(graph, m, n, color, 0);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends