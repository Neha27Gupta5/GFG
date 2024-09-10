//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
      vector< pair<int ,int>>p(n);
       for(int i=0;i<n;i++){
           p[i]={start[i],end[i]};
       }
       sort(p.begin(), p.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second; 
       });
       
       int count = 1;
       int last_end_time = p[0].second;
       
       for(int i=0;i<n;i++){
           if (p[i].first > last_end_time) {  
            count++;
            last_end_time = p[i].second;  // Update the last meeting's end time
          }
       }
         return count;
       
       
       
       
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends