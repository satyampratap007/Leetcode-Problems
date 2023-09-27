//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
        long long subarrayRanges(int n,vector<int>& nums) {
        long long sum {0};
        for(int i{0}; i < n; ++i)
        {
            int min_ele = nums[i], max_ele = nums[i] ;
            for(int j{i}; j < n; ++j)
            {
                min_ele = min(min_ele, nums[j]);
                max_ele = max(max_ele, nums[j]);    
                sum += (max_ele - min_ele);
            }
        }
        return sum;   
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.subarrayRanges(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends