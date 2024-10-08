//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  
//   memoization ..............
    // int solve(vector<int>& height, int n,vector<int>&dp){
    //     if(n==1){
    //         return abs(height[1]-height[0]);
    //     }
    //     if(n==0){
    //         return 0;
    //     }
    //     if(n<0){
    //         return INT_MAX;
    //     }
    //     if(dp[n]!=-1){
    //         return dp[n];
    //     }
    //     int s1=solve(height,n-1,dp)+abs(height[n-1]-height[n]);
    //     int s2=solve(height,n-2,dp)+abs(height[n-2]-height[n]);
    //     return dp[n]=min(s1,s2);
    // }
    
    //  int minimumEnergy(vector<int>& height, int n) {
    //     vector<int>dp(n,-1);
    //     return solve(height,n-1,dp);
    // }
    
    int solve(vector<int>& height, int n,vector<int>&dp){
        if(n==1){
            return abs(height[1]-height[0]);
        }
        if(n==0){
            return 0;
        }
        if(n<0){
            return INT_MAX;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int s1=solve(height,n-1,dp)+abs(height[n-1]-height[n]);
        int s2=solve(height,n-2,dp)+abs(height[n-2]-height[n]);
        return dp[n]=min(s1,s2);
    }
    // int minimumEnergy(vector<int>& height, int n) {
    //     vector<int>dp(n,-1);
    //     dp[0]=0;
    //     dp[1]=abs(height[0]-height[1]);
    //     for(int i=2;i<n;i++){
    //     int s1=dp[i-1]+abs(height[i-1]-height[i]);
    //     int s2=dp[i-2]+abs(height[i-2]-height[i]);
    //     dp[i]=min(s1,s2);
    //     }
    //     return dp[n-1];
    // }
    
        int minimumEnergy(vector<int>& height, int n) {
        
        int s0=0;
        if(n<=1){
            return s0;
        }
        int s1=abs(height[0]-height[1]);
        
        for(int i=2;i<n;i++){
        int s_1=s1+abs(height[i-1]-height[i]);
        int s_2=s0+abs(height[i-2]-height[i]);
        int curr=min(s_1,s_2);
        
        s0=s1;
        s1=curr;
        }
        return s1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends