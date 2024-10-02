//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int rotateDelete(vector<int> &arr) {
          int n = arr.size();
    int k = 1; 
    
    while (n > 1) {
    
        int lastElement = arr.back();
        arr.pop_back();
        arr.insert(arr.begin(), lastElement);
        
        
        int id = n - k; 
        if (id < 0) id = 0;
        arr.erase(arr.begin() + id);
        
      
        k++;
        n--;
    }
    
 
    return arr[0];

    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.rotateDelete(arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends