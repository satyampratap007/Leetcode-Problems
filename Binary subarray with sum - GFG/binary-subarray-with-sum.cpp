//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
//   Sliding Window
    // int numberOfSubarrays(vector<int>& arr, int N, int t){
    //     return helper(arr,N,t) - helper(arr,N,t-1);
    // }
    // int helper(vector<int>& arr, int N, int t){
    //     int i{0}, count{0};
    //     for(int j{0}; j < N; ++j)
    //     {
    //         t -= arr[j];
    //         while(t < 0)
    //             t += arr[i++];
    //         count += (j-i+1);
    //     }
    //     return count;
    // }
    
    
    
    // Prefix sum and map
    
    
    int numberOfSubarrays(vector<int>& arr, int N, int t){
        int p_sum = 0;
        unordered_map <int, int> mp({{0,1}});
        int count = 0;
        for(int i{0};i < N; ++i)
        {
            p_sum += arr[i];
            count += mp[p_sum - t]; // if found
            mp[p_sum]++;
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