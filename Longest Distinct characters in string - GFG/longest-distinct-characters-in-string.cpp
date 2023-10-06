//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    unordered_map <char,int> mp;
    int len = s.size();
    int i{0}, j{0};
    int maxi = 0;
    while(j < len)
    {
        mp[s[j]]++;
        while(i < j && mp[s[j]] > 1)
        {
            mp[s[i]]--;
            i++;
        }
        if(mp[s[j]] == 1)
        {
            maxi = max(maxi, j-i+1);
        }
        j++;
    }
    return maxi;
}