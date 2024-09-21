//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// #define MOD 1000000007
// class Solution{

// 	public:
// // void solve(int arr[], int n, int sum, int currSum, int i, int &count) {
    
// //     if (i == n) {
// //         if (currSum == sum) {
// //             count++;  
// //         }
// //         return;
// //     }
    
  
// //     solve(arr, n, sum, currSum + arr[i], i + 1, count);

// //     solve(arr, n, sum, currSum, i + 1, count);
// // }

// // int perfectSum(int arr[], int n, int sum) {
// //     int count = 0;  
// //     solve(arr, n, sum, 0, 0, count);  
// //     return count;
// // }



// int solve(int arr[], int n, vector<vector<int>>& dp, int ind, int sum) {
//     // Base conditions
   
//     if (sum == 0) {
//         return 1; 
//     }
    

    
//     if (ind < 0 || sum<0) {
//         return 0; // No valid subset when no more elements and sum isn't zero
//     }

//     if (dp[ind][sum] != -1) {
//         return dp[ind][sum];
//     }

    
//     int notTake = solve(arr,n,dp,ind - 1,sum) % MOD; 
    
//     int take = 0;
//     if (arr[ind] <= sum) {
//         take = solve(arr, n, dp, ind - 1, sum - arr[ind]) % MOD; 
//     }


//     return dp[ind][sum] = (take + notTake) % MOD;
// }

// int perfectSum(int arr[], int n, int sum) {

//      vector<vector<int>> dp(n+1, vector<int>(sum + 1, -1));
    

//     return solve(arr, n, dp, n - 1, sum) % MOD;
// }




// };

class Solution{
const int mod = 1000000007;
	public:
	int fun(int pos, int sum, int arr[], int n, vector<vector<int>>& dp) {
// 	  
    if (sum < 0)
        return 0;
    if (pos == -1)
        return sum == 0 ? 1 : 0;
    // if(sum==0 ){
    //     if(arr[pos]==0){
    //         return 2;
    //     }else{
    //         return 1;
    //     }
        
    // }

    if (dp[pos][sum] != -1)
        return dp[pos][sum];

    dp[pos][sum] = (fun(pos -1, sum, arr, n, dp) % mod + fun(pos - 1, sum - arr[pos], arr, n, dp) % mod) % mod;
    return dp[pos][sum];
}


	int perfectSum(int arr[], int n, int sum)
	{
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
         return fun(n-1, sum, arr, n, dp);
	}
	  
};

  

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends