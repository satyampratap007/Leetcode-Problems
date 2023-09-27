//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    const int mod = 1e9+ 7;
    void compute(vector<int>& arr, int n , string str, vector<int>& ans)
    {
        stack <int> st;
        if(str == "nsr")
        {
            for(int i{n-1}; i >= 0; --i)
            {
                while(!st.empty() && arr[st.top()] > arr[i]) // here we are not including the duplicate elements
                {
                    st.pop();
                }
                if(!st.empty())
                    ans[i] = st.top();
                st.push(i);
            }
        }
        else{
            for(int i{0}; i < n; ++i)
            {
                while(!st.empty() && arr[st.top()] >= arr[i])  
                {
                    st.pop();
                }
                if(!st.empty())
                    ans[i] = st.top();
                st.push(i);
            }
        }
        
    }
    int sumSubarrayMins(int n, vector<int> &arr) {
        stack <int> st;
        vector <int> nsr(n,n);
        vector <int> nsl(n,-1);

        compute(arr,n,"nsr", nsr);
        compute(arr,n,"nsl", nsl);
        int sum = 0;
        for(int i{0}; i < arr.size(); ++i)
        {
            int left = i - nsl[i];
            int right = nsr[i] - i;
            sum = (sum + (arr[i]*left*right)%mod)%mod;
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
        cout << obj.sumSubarrayMins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends