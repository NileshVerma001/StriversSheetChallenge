//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool comp(struct Job j1, struct Job j2) {
        return j1.profit > j2.profit;
    }

    vector<int> JobScheduling(Job arr[], int n) { 
        sort(arr, arr + n, comp);

        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }

        vector<int> schedule(maxDeadline + 1, -1); 

        int countJobs = 0, maxProfit = 0;

        // Iterate through all jobs
        for (int i = 0; i < n; i++) {

            for (int j = arr[i].dead; j > 0; j--) {
                if (schedule[j] == -1) {
                    schedule[j] = arr[i].id;
                    countJobs++;
                    maxProfit += arr[i].profit;
                    break;
                }
            }
        }

        // Return the number of jobs and the total profit
        return {countJobs, maxProfit};
    }

};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends
