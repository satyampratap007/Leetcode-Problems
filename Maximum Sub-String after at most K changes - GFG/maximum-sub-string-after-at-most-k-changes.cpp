//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int characterReplacement(string s, int k){
		    vector<int> mp(26);
		    int ans{0}, max_f {0};
		    int i{0};
		    for(int j{0}; j < s.size(); ++j)
		    {
		        mp[s[j] - 'A']++;
		        max_f = max(max_f, mp[s[j] - 'A']);
		        while(((j-i+1) - max_f) > k)
		        {
		            mp[s[i] - 'A']--;
		            i++;
		        }
		        ans = max(ans, j-i+1);
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends