//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        int ans = helper(arr , n-1);
        // vector <int> dp(n,-1);
        // int ans = tabulation(arr,dp, n);
	    return ans;
    }
    // 	Recurrence
// 	int helper(int *arr, int n)
// 	{
// 	    if(n == 0)  return arr[n];
// 	   int ist = INT_MIN;
// 	   if(n > 1)
// 	   {
// 	        ist = arr[n] + helper(arr, n-2);
// 	   }
// 	   int not_p = 0 + helper(arr, n-1);
// 	   return max(ist,not_p);
// 	}

    // int tabulation(int *arr, vector<int>& dp, int n)
    // {
    //     dp[0] = arr[0];
    //     for(int i{1}; i < n; ++i)
    //     {
    //         int pick = arr[i];  
    //         if(i > 1) pick += dp[i-2];
    //         int not_pick = 0 + dp[i-1];
    //         dp[i] = max(pick , not_pick);
    //     }
    //     return dp[n-1];
    // }
    int helper(int *arr, int n)
    {
        int prev = arr[0];
        int prev2 = 0;
        
        for(int i{1}; i <= n; ++i)
        {
            int pick = arr[i];  
            if(i > 1) pick += prev2;
            int not_pick = prev;
            int curri = max(pick , not_pick);
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }


};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends