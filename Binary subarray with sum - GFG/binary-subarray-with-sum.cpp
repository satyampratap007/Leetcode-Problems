//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    int numberOfSubarrays(vector<int>& arr, int N, int t){
        return helper(arr,N,t) - helper(arr,N,t-1);
    }
    int helper(vector<int>& arr, int N, int t){
        int i{0}, count{0};
        for(int j{0}; j < N; ++j)
        {
            t -= arr[j];
            while(t < 0)
                t += arr[i++];
            count += (j-i+1);
        }
        return count;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int target; 
        cin >> target;
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin >> arr[i];
        Solution obj;
        cout<<obj.numberOfSubarrays(arr, N, target)<<endl;
    }
    return 0;
}
// } Driver Code Ends