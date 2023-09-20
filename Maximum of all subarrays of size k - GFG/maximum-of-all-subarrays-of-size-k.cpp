//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    // **Using the concept of NGL**
    // Store the ngl in the array
    // and we will iterate till nge index lies outside the window then that will be the maximum of that particular window.
    // we are storing n if stack is empty as we need something which is out of bound to check for the max

    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector <int> ans;
       
        stack <int> st;
        vector <int> nge(n);
        for(int i = n-1; i >= 0; --i)
        {
            while(!st.empty() && arr[st.top()] <= arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                nge[i] = n;
            }
            else{
                nge[i] = st.top();
            }
            st.push(i);
        }
        
        int j = 0;
        for(int i{0} ; i <= n-k; ++i)
        {
            if(j < i)
                j = i;
            
            while(nge[j] < i+k)
            {
                j = nge[j];
            }
            ans.push_back(arr[j]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends