//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class Solution
// {
//     public:
//     string smallestWindow(string s, string p) {
//             unordered_map <char, int> mp;
//             int len = s.length();
//             for(auto &i : t)
//             {
//                 mp[i]++;
//             }
//             int count = mp.size(); // to reduce the overhead of continuous checking

//             string ans = "";
//             int ans_len = INT_MAX;
//             int i{0}, j{0};
//             int res_i = -1, res_j = -1;

//             while(j < len){
//                 if(mp.find(s[j]) != mp.end())
//                 {
//                     if(--mp[s[j]] == 0){
//                         count--;
//                     }
//                 }
//                 while(count == 0) {
//                     if(ans_len > (j-i+1)) {
//                         res_i = i;
//                         res_j = j;
//                         ans_len = j-i+1;
//                     }
//                     if(mp.find(s[i]) != mp.end()){
//                         if (++mp[s[i]] > 0) {
//                             count++;
//                         }
//                     }
//                     i++;
//                 }
//                 j++;
//             }         
//             return (ans_len == INT_MAX)? "" : s.substr(res_i,res_j-res_i+1);
//         }
    
// };
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow(string s, string p) {
           vector<int>umap1(26,0);
        vector<int>umap2(26,0);
        //   map<char,int>umap1;
        // map<char,int>umap2;
        for(int i=0;i<p.size();i++){
            umap2[p[i]-'a']++;
        }
        int mini=INT_MAX;
        int l=0,r=0;
        int m=s.size();
        int size=p.size();
        int count=0;
        int i=0,j=0;
        while(i<m){
           if(count<size){
               umap1[s[i]-'a']++;
               if(umap2[s[i]-'a']>0 &&  umap1[s[i]-'a']<=umap2[s[i]-'a']){
                   count++;
               }
           }
           if(count==size){
             
                while(count==size){
                     
                       if(mini>i-j+1){
                   mini=min(mini,i-j+1);
                   l=j;
                   r=i;
               }
                   
                   umap1[s[j]-'a']--;
                   if(umap2[s[j]-'a']>0 && umap1[s[j]-'a']<umap2[s[j]-'a']){
                       count--;
                   }
                 
                   j++;
               }
           }
          
           i++;
        }
        if(mini==INT_MAX){
            return "-1";
        }
        return s.substr(l,mini);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends