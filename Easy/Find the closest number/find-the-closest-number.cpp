//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { int ansIndex=0;
      int diff=INT_MAX;
      int l=0;
      int h=n-1;
      while(l<=h){
          int mid=(l+h)/2;
          int currDiff=abs(k-arr[mid]);
          if(currDiff<diff){
              diff=currDiff;
              ansIndex=mid;
          }
          else if(currDiff==diff && ansIndex<mid){
              ansIndex=mid;
          }
          if(arr[mid]>k){
              h=mid-1;
          }
          else if(arr[mid]<=k){
              l=mid+1;
          }
      }
      return arr[ansIndex];
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends