//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:

int findPlatform(int arr[], int dep[], int n) {


    // Sort the arrival and departure arrays
    sort(arr, arr + n);
    sort(dep, dep + n);

    int plat_needed = 1, max_platforms = 1;
    int i = 1, j = 0;

    // Iterate through the sorted arrays
    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            plat_needed++;
            i++;
        } else {
            plat_needed--;
            j++;
        }
        if (plat_needed > max_platforms)
            max_platforms = plat_needed;
    }

    return max_platforms;
}
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends
