//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int k,vector<int>&arr,int i,vector<int>&dp){
        if(i==0){
            return 0;
        }
        if(i<0){
            return INT_MAX;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int mini=INT_MAX;
        for(int s=1;s<=k;s++){
            int cost=solve(k,arr,i-s,dp);
            if(i-s>=0){
                cost+=abs(arr[i]-arr[i-s]);
            }
            mini=min(mini,cost);
        }
        return dp[i]=mini;
    }
    int minimizeCost(int k, vector<int>& arr) {
        vector<int>dp(arr.size(),-1);
       return solve(k,arr,arr.size()-1,dp);
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