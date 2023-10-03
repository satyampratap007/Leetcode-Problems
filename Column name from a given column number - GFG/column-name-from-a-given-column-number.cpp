//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        string ans = "";
        while(n != 0)
        {
            int rem = n%26;
            if(rem == 0)
            {
                ans += 'Z';
            }
            else
            {
                ans += (rem + 'A' - 1);
            }
            n = (n-1)/26; // to map 1 to A 
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends