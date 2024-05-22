//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

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
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends

int floor (int arr[],int n,int x){
   int l=0;
   int h=n-1;
   int index=-1;
   while(l<=h){
       int mid=(l+h)/2;
       if(arr[mid]<=x){
           index=arr[mid];
           l=mid+1;
       }
       if(arr[mid]>x){
           h=mid-1;
       }
   }
   return index;
}

int ceil(int arr[],int n,int x){
    int l=0;
    int h=n-1;
    int index=-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(arr[mid]>=x){
            index=arr[mid];
            h=mid-1;
        }
        if(arr[mid]<x){
            l=mid+1;
        }
    }
    return index;
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    
    sort(arr,arr+n);
    
    int Floor=floor(arr,n,x);
    int Ceil=ceil(arr,n,x);
    
    
    return {Floor,Ceil};
    
}