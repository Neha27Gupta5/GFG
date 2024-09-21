//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   int find(string s){
       int n=s.size();
       vector<int>dp(n+1);
       unordered_map<char,int>m;
      
       dp[0]=1;
       
       for(int i=1;i<=n;i++){
           dp[i]=2*dp[i-1];
           if(m.find(s[i-1])!=m.end()){
               int lastindex=m[s[i-1]];
               dp[i]-=dp[lastindex-1];
           }
           m[s[i-1]]=i;
       }
       return dp[n];
   }
    string betterString(string str1, string str2) {
       int a=find(str1);
       int b=find(str2);
       
       if(a>=b){
           return str1;
       }else{
           return str2;
       }
    }
    

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends