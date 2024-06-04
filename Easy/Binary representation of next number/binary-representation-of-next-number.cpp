//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        
        int i=0;
        
        while(i<s.size() && s[i]=='0'){
            s=s.substr(i+1);
        }
        int n=s.size();
        i=n-1;
        if(s.size()==0){
            s=s+'1';
            return s;
        }
        if(s[n-1]=='0'){
            s[n-1]='1';
            return s;
        }
        
        else{
            while(i>=0 && s[i]!='0'){
                s[i]='0';
                i--;
            }
          if(i>=0){
              s[i]='1';
              return s;
          }
          else{
             string ans = '1'+s;
             return ans;
          }
        }
        return s;
     }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends