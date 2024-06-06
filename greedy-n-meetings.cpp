//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    struct meet{
        int start;
        int end;
        int pos;
    };
    bool static comp(struct meet m1, struct meet m2){
        if(m1.end<m2.end)
        return true;
        else if(m1.end>m2.end)
        return false;
        else if(m1.pos<m2.pos)
        return true;
        return false;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        struct meet me[n];
        for(int i=0;i<n;i++){
            me[i].start=start[i];
            me[i].end=end[i];
            me[i].pos=i+1;
            
        }
        
        sort(me,me+n,comp);
        int count=1;
        int e=me[0].end;
        for(int i=1;i<n;i++){
            if(me[i].start>e){
                count++;
                e=me[i].end;
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
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
