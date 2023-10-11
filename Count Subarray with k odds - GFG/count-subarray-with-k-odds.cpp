//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  // Here we need to find the exact count that's why we will use the concept of at most k
// to get the exact count of subarray
    
    int at_most(vector<int>& nums, int k)
    {
        int i{0}, count{0};
        for(int j{0}; j < nums.size();++j)
        {
            if(nums[j]&1)
            {
                k--;
            }
            while(k < 0)
            {
                if(nums[i]&1)
                {
                    k++;
                }
                i++;
            }
            count += j-i+1;  // for at most if count <= K
        }
        return count;
    }

    
    int countSubarray(int n, vector<int>& nums, int k) {
        return at_most(nums, k) - at_most(nums, k-1); 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends