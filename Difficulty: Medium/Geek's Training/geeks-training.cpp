//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int solve(vector<vector<int>>& arr , vector<vector<int>>&dp ,int row, int prev,int n){
        if(row==n-1){
            int maxi=INT_MIN;
            for(int i=0;i<3;i++){
                if(i!=prev){
                    maxi=max(maxi,arr[row][i]);
                }
            }
            return maxi;
        }
        if(dp[row][prev]!=-1){
            return dp[row][prev];
        }
        int ans=INT_MIN;
        
        for(int i=0;i<3;i++){
            if(i!=prev){
                int temp = arr[row][i]+solve(arr,dp,row+1,i,n);
                ans=max(ans,temp);
            }
        }
        return dp[row][prev]=ans;
    }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        vector<vector<int>>dp(n,vector<int>(4,-1));
        
       return solve(arr ,dp, 0 ,3,n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends