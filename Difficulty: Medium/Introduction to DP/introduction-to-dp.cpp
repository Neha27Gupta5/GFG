//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
int mod=1000000007;
class Solution {
  public:
    long long int topDown(int n) {
        vector<long long int>dp(n+1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=(dp[i-1]+dp[i-2])%mod;
        }
        return dp[n]%mod;
    }
    long long int bottomUp(int n) {
      long long int prev=1;
       long long int prev2=0;
       for(int i=2;i<=n;i++){
           long long int curr=(prev+prev2)%mod;
           prev2=prev;
           prev=curr;
       }
       return prev%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends