//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int isPossible (string s);

int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		if (isPossible (s))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int isPossible (string s)
{
   unordered_map<char,int>m;
   int n=s.size();
   for(int i=0;i<n;i++){
       m[s[i]]++;
   }
   int count =0;
   for(auto i:m){
      if((i.second)%2==1 ){
          count++;
          if(count>1){
              return 0;
          }
      } 
   
   }
   return 1;
}