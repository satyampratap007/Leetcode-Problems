//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
    private:
    long long at_most(string s, int k)
    {
        long long final_count{0};
        int len = s.size();
        int hash[26];
        memset(hash,0,sizeof(hash));
        int dis_count {0};
        int i{0}, j{0};
        
        for(; j < len; ++j)
        {
            hash[s[j] - 'a']++;
            if(hash[s[j] - 'a'] == 1)  // abhi abhi encounter hua and uska counter 1 hai then vo distinct hai
            {
                dis_count++;
            }
            while(dis_count > k)
            {
                hash[s[i] - 'a']--;
                if(hash[s[i] - 'a'] == 0)
                {
                    dis_count--;
                }
                i++;
            }
            final_count += (j-i+1); // as we are calculating at most at each index
        }
        return final_count;
    }
    
  public:
    long long int substrCount (string s, int k) {
        // We are finding at most to find the exact number of distinct element
        return (at_most(s,k) - at_most(s, k-1));
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends