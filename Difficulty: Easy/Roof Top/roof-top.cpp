//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find maximum number of consecutive steps
    // to gain an increase in altitude with each step.
  int maxStep(vector<int>& arr) {
    int count = 0; 
    int ans = 0; 
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i-1]) {
            count++; 
            ans = max(ans, count); 
        } else {
            count = 0; 
        }
    }

    return ans;  
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.maxStep(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends