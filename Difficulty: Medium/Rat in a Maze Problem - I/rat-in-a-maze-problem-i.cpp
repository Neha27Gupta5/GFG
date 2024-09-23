//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
//     void solve(vector<vector<int>>& mat, vector<string>& ans, vector<vector<bool>>& vis, string temp, int row, int col, int n, int m) {
   
//     if (row == n-1 && col == m-1) {
//         ans.push_back(temp);
//         return;
//     }

   
//     if (row < 0 || row >= n || col < 0 || col >= m || mat[row][col] == 0 || vis[row][col]) {
//         return;
//     }

    
//     vis[row][col] = true;

    
//     solve(mat, ans, vis, temp+'U', row-1, col, n, m);
//     solve(mat, ans, vis, temp+'D', row+1, col, n, m);
//   solve(mat, ans, vis, temp+'L', row, col-1, n, m); 
//  solve(mat, ans, vis, temp+'R', row, col+1, n, m); 

  
//     vis[row][col] = false;
// }

// vector<string> findPath(vector<vector<int>>& mat) {
//     vector<string> ans;
//     int n = mat.size();
//     int m = mat[0].size();
//     vector<vector<bool>> visited(n, vector<bool>(m, false));
//     string temp = "";

    
//     solve(mat, ans, visited, temp, 0, 0, n, m);

//     return ans;
// }
void solve(vector<vector<int>>& mat, vector<string>& ans, vector<vector<bool>>& vis, string& temp, int row, int col, int n, int m) {
    // Base condition: If reached bottom-right corner, add the current path to the result
     if (row < 0 || row >= n || col < 0 || col >= m || mat[row][col] == 0 || vis[row][col]) {
        return;
    }
    
    if (row == n-1 && col == m-1) {
        ans.push_back(temp);
        return;
    }

    // If out of bounds, cell is blocked, or already visited, return
  

    // Mark the cell as visited
    vis[row][col] = true;

    // Explore all directions: Up, Down, Left, Right
    temp.push_back('U'); solve(mat, ans, vis, temp, row-1, col, n, m); temp.pop_back();
    temp.push_back('D'); solve(mat, ans, vis, temp, row+1, col, n, m); temp.pop_back();
    temp.push_back('L'); solve(mat, ans, vis, temp, row, col-1, n, m); temp.pop_back();
    temp.push_back('R'); solve(mat, ans, vis, temp, row, col+1, n, m); temp.pop_back();

    // Backtrack: Unmark the cell as visited
    vis[row][col] = false;
}

vector<string> findPath(vector<vector<int>>& mat) {
    vector<string> ans;
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    string temp = "";

    // Start solving from the top-left corner (0, 0)
    solve(mat, ans, visited, temp, 0, 0, n, m);

    return ans;
}


};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends