//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
   void solve(int n, vector<string>&ans, string s){
        if(s.size() == n){
            ans.push_back(s);
            return;
        }
        solve(n,ans,s+'0');
        if(s.back()=='0' ||s.size()==0){
         solve(n,ans,s+'1');
        }
       
        
    }
    vector<string> generateBinaryStrings(int num){
      vector<string>ans;
      string s="";
      solve(num,ans,s);
      return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends