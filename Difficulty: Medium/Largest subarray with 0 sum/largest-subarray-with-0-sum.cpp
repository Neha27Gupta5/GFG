//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/


class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
      unordered_map<int,int>m;
      int sum=0;
      m[0]=-1;
      int length=0;
       
      for(int i=0;i<n;i++){
          sum+=arr[i];
          
           
          if(m.find(sum)!=m.end()){
              int index=m[sum];
              length=max(length,i-index);
          }else{
              m[sum]=i;
          }
      }
      return length;
    }
//     int maxLen(vector<int>& arr, int n) {
//     unordered_map<int, int> m;
//     int sum = 0;
//     int length = 0;

//     // Initialize the map with sum 0 at index -1 to handle the subarray from the start
//     m[0] = -1;

//     for (int i = 0; i < n; i++) {
//         sum += arr[i];

//         // If the sum has been seen before
//         if (m.find(sum) != m.end()) {
//             // Update the maximum length of the subarray
//             length = max(length, i - m[sum]);
//         } else {
//             // Otherwise, store the first occurrence of the sum
//             m[sum] = i;
//         }
//     }

//     return length;
// }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends