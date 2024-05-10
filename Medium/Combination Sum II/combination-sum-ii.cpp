//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void solve( vector<vector<int>>&ans,vector<int> &arr,vector<int>&temp,int i,int k,int sum){
        if(sum==k){
            ans.push_back(temp);
            return ;
        }
        if(i==arr.size() || sum>k){
            return;
        }
        
           for (int j = i; j < arr.size(); ++j) {
        if (j > i && arr[j] == arr[j - 1]) 
            continue;
        temp.push_back(arr[j]);
        solve(ans, arr, temp, j + 1, k, sum + arr[j]);
        temp.pop_back();
    }
        
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
         sort(arr.begin(), arr.end()); 
    vector<vector<int>> ans;
    vector<int> temp;
    solve(ans, arr, temp, 0, k, 0);
    return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends