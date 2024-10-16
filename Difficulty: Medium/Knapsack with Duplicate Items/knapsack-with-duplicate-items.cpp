//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve( int W, int val[], int wt[] , int ind,vector<vector<int>>&dp){
        
        if(ind<0){
            return 0;
        }
        if(dp[ind][W]!=-1) return dp[ind][W];
        int nottake= solve(W,val,wt,ind-1,dp);
        int take = 0;
        if(W>=wt[ind]){
            take = val[ind]+solve(W-wt[ind],val,wt,ind,dp);
        }
        return dp[ind][W]=max(nottake,take);
        
    }
    int knapSack(int N, int W, int val[], int wt[])
    {  vector<vector<int>>dp(N,vector<int>(W+1,-1));
       int res= solve(W,val,wt,N-1,dp);
       return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends