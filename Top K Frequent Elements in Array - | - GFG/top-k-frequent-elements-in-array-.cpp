//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    typedef pair<int,int> p;
    vector<int> topK(vector<int>& nums, int k) {
        
        unordered_map <int,int> mp; // <ele, count>
        for(auto &i : nums)    mp[i]++;
        int len = nums.size();
        priority_queue <p, vector <p>, greater <p>> pq;
        
        vector <int> ans;

        for(auto &it: mp){
            pq.push({it.second,it.first});
            if(pq.size() > k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends