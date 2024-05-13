//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
//   bool bfs(int i,vector<vector<int>>adjList,vector<int>&vis){
//       int num=0;
//       int edges=0;
//       queue<int>q;
//       q.push(i);
//       while(!q.empty()){
//           int top=q.front();
//           q.pop();
//           num++;
//           edges+=adjList[top].size();
//           int j=0;
//           while(j<adjList[top].size()){
//               if(vis[adjList[top][j]]!=1){
//                   q.push(adjList[top][j]);
//                   vis[adjList[top][j]]=1;
//               }
//               j++;
//           }
//       }
//       if(num*(num-1)!=edges) return false;
//       return true;
//   }
//     int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
//       vector<vector<int>>adjList(v+1);
//       for (auto& v : edges) {
//     adjList[v[0]].push_back(v[1]);
//     adjList[v[1]].push_back(v[0]);
//       }
//       vector<int>vis(v+1);
//       int ans=0;
//       for(int i=1;i<=v;i++){
//           if(vis[i]!=1){
//               vis[i]=1;
//               if(bfs(i,adjList,vis)){
//                   ans++;
//               }
//           }
//       }
//       return ans;
//     }



bool bfs(int i, vector<vector<int>>& adjList, vector<int>& vis) {
    int num = 0;
    int edges = 0;
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        num++;
        edges += adjList[top].size();
        for (int j = 0; j < adjList[top].size(); j++) {
            if (vis[adjList[top][j]] != 1) {
                q.push(adjList[top][j]);
                vis[adjList[top][j]] = 1;
            }
        }
    }
    if (num * (num - 1) != edges) return false;
    return true;
}

int findNumberOfGoodComponent(int e, int v, vector<vector<int>>& edges) {
    vector<vector<int>> adjList(v + 1);
    for (auto& edge : edges) {
        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
    }
    vector<int> vis(v + 1);
    int ans = 0;
    for (int i = 1; i <= v; i++) {
        if (vis[i] != 1) {
            vis[i] = 1;
            if (bfs(i, adjList, vis)) {
                ans++;
            }
        }
    }
    return ans;
}

};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends