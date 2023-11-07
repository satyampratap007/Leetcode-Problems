//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
//   We are only intended to find the maximum distance we can achieve that's why it is greedy
    int canReach(int A[], int N) {
        int maxi = A[0];
        
        for(int i{1}; i < N; ++i){
            int curr_i = i;
            curr_i += A[i];
            
            if(i > maxi)
                return false;
            maxi = max(curr_i, maxi);
            if(maxi >= N-1)
                return true;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}
// } Driver Code Ends