//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // int leastInterval(int N, int K, vector<char> &tasks) {
    //     // Firstly store the count
    //     unordered_map <char,int> mp;
    //     for(auto &i: tasks){
    //         mp[i]++;
    //     }
    //     // now  store into the p_q to maintain the count of each task
    //     priority_queue <int> pq;
    //     for(pair<char,int> i: mp)
    //         pq.push(i.second);
            
    //     int final_time = 0;
    //     int cycle = K+1;
        
    //     while(!pq.empty()){
    //         int time = 0;
    //         vector <int> temp;
    //         for(int i{0}; i < cycle; ++i){ // as we know until k there won't be similar task therefore we will simply pop from the pq
    //             if(!pq.empty()){
    //                 temp.push_back(pq.top());
    //                 pq.pop();
    //                 time++;
    //             }
    //         }
    //         for(auto &i: temp){
    //             if(--i){
    //                 pq.push(i);
    //             }
    //         }
    //         final_time += !pq.empty() ? cycle : time;
    //     }
    //     return final_time;
    // }
    // int leastInterval(int N, int K, vector<char> &tasks) {
    //     vector <int> mp(26,0);
    //     for(auto &i: tasks){
    //         mp[i-'A']++;
    //     }
    //     // now  store into the p_q to maintain the count of each task
    //     priority_queue <int> pq;
    //     for(auto &i : mp)
    //         if(i > 0)
    //             pq.push(i);
            
    //     int final_time = 0;
    //     int cycle = K+1;
        
    //     while(!pq.empty()){
    //         int time = 0;
    //         vector <int> temp;
    //         for(int i{0}; i < cycle; ++i){ // as we know until k there won't be similar task therefore we will simply pop from the pq
    //             if(!pq.empty()){
    //                 temp.push_back(pq.top());
    //                 pq.pop();
    //                 time++;
    //             }
    //         }
    //         for(auto &i: temp){
    //             if(--i){
    //                 pq.push(i);
    //             }
    //         }
    //         final_time += !pq.empty() ? cycle : time;
    //     }
    //     return final_time;
    // }
    
    int leastInterval(int n, int k, vector<char> &t) {
        // code here
        int mx=0,mx_cnt=0;
        unordered_map<char,int>m;
        for(auto c : t){
            m[c]++;
            mx=max(mx,m[c]);
        }
        for(auto it: m){
            if(it.second==mx)mx_cnt++;
        }
        int val=mx_cnt+(mx-1)*(k+1);
        return max(val,n);
    }
    
    
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends