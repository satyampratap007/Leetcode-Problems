//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int at_most(vector<int>& nums, int k)
    {
        unordered_map <int,int> mp;
        int i{0}, count{0};
        for(int j{0}; j < nums.size(); ++j)
        {
            mp[nums[j]]++;
            while(mp.size() > k)
            {
                if(--mp[nums[i]] == 0)
                {
                    mp.erase(nums[i]);
                }
                i++;
            }
            count += (j-i+1);
        }
        return count;
    }
    int subarrayCount(vector<int> &arr, int N, int k) {
        return at_most(arr, k) - at_most(arr,k-1);
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.subarrayCount(arr, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends