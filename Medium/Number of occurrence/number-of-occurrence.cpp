//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
  void lowerbound(int nums[], int target, int h, int &lb , int n) {
        int l = 0;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (nums[mid] == target) {
                lb = min(lb, mid);
                h = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } 
        }
    }

    void upperbound(int nums[], int target, int l, int &ub,int n) {
        int h = n - 1;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (nums[mid] == target) {
                ub = max(ub, mid);
                l = mid + 1;
            } else if (nums[mid] > target) {
                    h = mid - 1;
            }
        }
    }
	int count(int nums[], int n, int target) {
	  
        int l = 0;
        int h = n - 1;
        int lb = -1;
        int ub = -1;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (nums[mid] == target) {
                lb = ub = mid;
                lowerbound(nums, target, mid - 1, lb,n);
                upperbound(nums, target, mid + 1, ub,n);
                break; 
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        // cout<<lb<<" "<<ub<<endl;
        if(lb==-1 && ub==-1){
            return 0;
        }
        return (ub-lb+1);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends