//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> ngl(int *price, int n)
    {
        vector<int> ans(n);
        stack <int> st;
        
        for(int i{0}; i < n; ++i)
        {
            while(!st.empty() && price[st.top()] <= price[i])
            {
                st.pop();
            }
            
            if(st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
                
            st.push(i);
        }
        return ans;
        
    }
    vector <int> calculateSpan(int price[], int n)
    {
        vector <int> left = ngl(price, n);
        vector <int> ans(n,1);
        for(int i{1}; i < n; ++i)
        {
            ans[i] = i-left[i]; 
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends