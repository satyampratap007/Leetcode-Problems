//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long helper(vector <int> A, long long K)
    {
        long long count {0};
        int i{0};
        long long curr_sum = 0;
        for(int j{0}; j < A.size(); ++j)
        {
            curr_sum += A[j];
            while(curr_sum > K)
            {
                curr_sum -= A[i++];
            }
            count  += j-i+1;
        }
        return count;
    }
    
    long long countSubarray(int N,vector<int> A,long long L,long long R){
        return helper(A,R) - helper(A, L-1); // (all subarray whole sum <= R - all subarray whose sum < L) 
                                             // Gives the exact count of required subarray
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        long long L,R;
        cin>>N>>L>>R;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution obj;
        auto ans = obj.countSubarray(N,A,L,R);
        cout<<ans<<endl;
    }
}  
// } Driver Code Ends