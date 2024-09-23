//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
      int n = arr.size();
    long long sumExpected = (long long)n * (n + 1) / 2; 
    long long sumObtained = 0;
    long long sumOfSquaresExpected = (long long)n * (n + 1) * (2 * n + 1) / 6;
    long long sumOfSquaresObtained = 0;

    for (int i = 0; i < n; i++) {
        sumObtained += arr[i];
        sumOfSquaresObtained += (long long)arr[i] * arr[i];
    }

    long long diff = sumExpected - sumObtained; 
    long long diffSquares = sumOfSquaresExpected - sumOfSquaresObtained; 

 

    long long sumXY = diffSquares / diff;
    int missing = (diff + sumXY) / 2;
    int repeated = sumXY - missing; 

    return {repeated, missing};
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends