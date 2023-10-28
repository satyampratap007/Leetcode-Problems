//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end(), greater<int>());
        priority_queue<int,vector<int>, greater<int>> pq;
        for(int i{0}; i < K; ++i)
        {
            for(int j{0}; j < K; ++j){
                int curr = A[i] + B[j]; // storing the curr sum 
                if(pq.size() < K)
                {
                    pq.push(curr);
                }
                else{
                    if(pq.top() < curr){
                        pq.pop();
                        pq.push(curr);
                    }
                    else{ 
                        break;
                    }
                }
            }
        }
        vector <int> ans(K,0);
        while(K--){
            ans[K] = pq.top();
            pq.pop();
        }
        return ans;
         
     }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends