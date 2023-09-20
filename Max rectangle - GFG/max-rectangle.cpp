//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  //calculating the nsl and nsr
    void req(vector <int> &arr, vector <int> &ans, int n, string s)
    {
        stack <int> st;
        if(s == "nsr")
        { 
            for(int i{n-1};i >= 0; --i)
            {
                while(!st.empty() && arr[st.top()] >= arr[i])
                {
                    st.pop();
                }
                if(!st.empty()){
                    ans[i] = st.top();
                }
                st.push(i);
            }
        }
        else{
            
            for(int i{0};i < n; ++i)
            {
                while(!st.empty() && arr[st.top()] >= arr[i])
                {
                    st.pop();
                }
                if(!st.empty()){
                    ans[i] = st.top();
                }
                st.push(i);
            }
        }
    }
    int area_histogram(vector <int> &levels, int n)
    {
        vector <int> left(n , -1);
        vector <int> right(n , n);
        req(levels,left,n,"nsl");
        req(levels, right, n, "nsr");
        int maxi = INT_MIN;
        for(int i{0}; i < n; ++i)
        {
            int height = levels[i];
            int width = right[i] - left[i] - 1;
            int area = height * width;
            maxi = max(maxi,area);
        }
        return maxi;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        int maxi = INT_MIN;
        vector<int> levels(m,0);
        
        for(int i{0}; i < n; ++i)
        {
            for(int j{0}; j < m; ++j)
            {
                if(M[i][j] == 0)
                {
                    levels[j] = 0;
                }else{
                    levels[j] += M[i][j];
                }
            }
            maxi = max(maxi,area_histogram(levels, m));
        }
        return maxi;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends