//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> nextGreaterElement(int N, vector<int>& arr) {
        stack <int> st;
        vector <int> ans(N);
        
        for(int i{2*N-1}; i >= 0 ; --i)
        {
            int ind =  i%N;
            
            while(!st.empty() && st.top() <= arr[ind])
            {
                st.pop();
            }
          if(i < N){
               if(st.empty())
                {
                    ans[ind] = -1;
                }
                else{
                    ans[ind] = st.top();
                }
            //   cout << ans[ind] << "\n";
          }
            
            st.push(arr[ind]);
        }
        return ans;
        
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
        vector<int> ans = obj.nextGreaterElement(N, arr);
        for (auto &it : ans) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends