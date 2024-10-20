//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
  int evenlyDivides(int n) {
    int count = 0;
    int num = abs(n);  

    while (num > 0) {
        int lastdigit = num % 10;
        
        
        if (lastdigit != 0 && n % lastdigit == 0) {
            count++;
        }
        
        num = num / 10;
    }
    
    return count;
}
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends