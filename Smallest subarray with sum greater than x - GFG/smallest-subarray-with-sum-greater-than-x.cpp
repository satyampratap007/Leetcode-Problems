//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int nums[], int len, int target)
    {
        // Think like sliding window
        int curr_sum{0};
        int i{0}, j{0};
        int mini = INT_MAX;
        while(j < len)
        {
            curr_sum += nums[j];
            while(curr_sum > target)
            {
                curr_sum -= nums[i];
                mini = min(mini, j-i+1);
                i++;
            }
            j++;
        }
        return (mini== INT_MAX) ? 0 : mini;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends