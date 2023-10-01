//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    int ans = 0;
	    int k = pat.size(), n = txt.size();
	    
	    unordered_map<char, int> mp; // <char, count>
	    
	    for(auto i : pat)
	        mp[i]++;       // storing the pat in the map
	    
	    int count = mp.size(); // to minimize the cost of checking the certain char in map and and again
	    int i{0}, j{0};    
	    while(j < n)
	    {
	        if(mp.find(txt[j]) != mp.end())
	        {
	            mp[txt[j]]--;
	            if(mp[txt[j]] == 0) 
	                count--;
	        }
	        if(j-i+1 < k){
	            j++;
	        }
	        else
	        {
	            if(count == 0)
	                ans++;
	            // As if the ith index element contribute in making the anagram
	            //in the previous window then we need to add again in the map to 
	           // check for the next anagram in the next window
	            if(mp.find(txt[i]) != mp.end()){
	                mp[txt[i]]++;           
                    if(mp[txt[i]]==1)
                        count++;
	            }
	            i++;
	            j++;
	        }
	    }
	    return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends