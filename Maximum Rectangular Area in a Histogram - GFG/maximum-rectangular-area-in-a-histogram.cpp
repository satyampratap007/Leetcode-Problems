//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    
    vector <long long> nsr(long long *arr, int n)
    {
        stack <int> st;
        vector <long long> ans(n);
        for(int i = n-1; i >= 0; --i)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
                
            if(st.empty())
            {
                ans[i] = n;
            }
            else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector <long long> nsl(long long *arr, int n)
    {
        stack <int> st;
        vector <long long> ans(n);
        for(int i = 0; i < n; ++i)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
                
            if(st.empty())
            {
                ans[i] = -1;
            }
            else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    
    
    
    long long getMaxArea(long long arr[], int n)
    {
        vector <long long> right = nsr(arr, n);
        vector <long long> left = nsl(arr, n);
        
        long long maxi = INT_MIN;
        
        for(int i{0}; i <n; ++i)
        {
            long long height = arr[i];
            long long width = right[i] - left[i] - 1;
            
            long long area = height*width;
            maxi = max(area, maxi);
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends