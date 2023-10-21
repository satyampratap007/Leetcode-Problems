//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    // vector<int> replaceWithRank(vector<int> &arr, int N){
    //     vector <int> temp(arr);
    //     sort(temp.begin(), temp.end());
    //     unordered_map <int,int> mp;
    //     int i{1};
    //     for(auto &j : temp){
    //         if(mp.find(j) == mp.end())
    //             mp[j] = i++;
    //     }
    //     for (int i = 0; i < N; ++i){
    //         arr[i] = mp[arr[i]];            
    //     }
    //     return arr;
    // }
    vector<int> replaceWithRank(vector<int> &arr, int N){
        set<int> st(arr.begin(), arr.end());
        unordered_map<int,int> mp;
        
        int i = 1;
        for(auto &j: st)
            mp[j] = i++;
        
        for(auto &ele : arr) 
            ele = mp[ele];
        
        return arr;
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends