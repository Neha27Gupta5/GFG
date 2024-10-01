//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<long long> lcmAndGcd(long long a , long long b) {
    long long oga=a,ogb=b;
       while(a>0 && b>0){
           if(a>b) a=a%b;
           else b=b%a;
       }
       long long gcd;
       if(a==0) gcd=b;
       else gcd=a;
       long long lcm = (oga*ogb)/gcd;
       return {lcm,gcd};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends