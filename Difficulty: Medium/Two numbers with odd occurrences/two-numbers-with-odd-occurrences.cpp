//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int arr[], long long int n)  
    { 
        
        long long int res=0;
        for(int i=0;i<n;i++){
            res=res^arr[i];
        }
        int place=0;
        while(res>0){
            place++;
            if((res&1)==1){
                break;
            }
            
            
            res=res>>1;
            
        }
        
    //      int place = 0;
    // while((res & 1) == 0) { 
    //     place++;
    //     res = res >> 1;  
    // }
    //     
    long long int grp1=0;
        long long int grp2=0;
        
        for(int i=0;i<n;i++){
            if((arr[i] & (1 << (place-1))) != 0){
                grp1^=arr[i];
            }else{
                grp2^=arr[i];
            }
        }

 if(grp2>grp1){
     return {grp2,grp1};
 }
 return {grp1,grp2};
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends