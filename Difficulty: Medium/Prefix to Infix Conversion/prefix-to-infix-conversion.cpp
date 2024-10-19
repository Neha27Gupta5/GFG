//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToInfix(string s) {
        int n=s.size();
      int ptr =n-1;
      stack<string>st;
     for(int i=n-1;i>=0;i--){
         if(s[i]>='A'&&s[i]<='Z' ||
         s[i]>='a' && s[i]<='z'){
             st.push(string(s[i]));
         }
         else{
             string t1=st.top();
             st.pop();
             string t2=st.top();
             st.pop();
             st.push('('+t1+s[i]+t2+')');
         }
     }
     return st.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends