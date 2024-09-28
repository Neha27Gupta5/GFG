//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   int solve(vector<int>& arr, vector<int>& dp, int k, int i, int n) {

    if (i == n - 1) {
        return 0;
    }

 
    if (dp[i] != -1) {
        return dp[i];
    }

    int mini = INT_MAX;

   
    for (int step = 1; step <= k; step++) {
        if (i + step < n) {
         
            int cost = abs(arr[i + step] - arr[i]) + solve(arr, dp, k, i + step, n);
            mini = min(mini, cost);
        }
    }


    return dp[i] = mini;
}

int minimizeCost(int k, vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, -1);  
    return solve(arr, dp, k, 0, n); 
}

};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends