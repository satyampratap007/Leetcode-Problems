//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string str, int k) {
        int len = str.size();
        // Edge case
        if(k == 0)  return str;
        if(len <= k)    return "0";
        stack <char> st;
        
        for(int i{0}; i < len; ++i)
        {
            while(!st.empty() && k && str[i] < st.top())
            {
                st.pop();
                k--;
            }
            st.push(str[i]);
            if(st.size() == 1 && st.top() == '0')   st.pop();  // considering the case -> 10203 & k = 1
        }
        
        // if k remains
        while(!st.empty() && k)
        {
            st.pop();
            k--;
        }
        // if stack becomes empty
        if(st.empty()) 
            return "0";
        
        string ans = "";
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends