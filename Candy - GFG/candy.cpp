//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCandy(int N, vector<int> &ratings) {
        if(N == 1)  return 1;
        vector <int> temp(N, 1);
        
        for(int i{1}; i < N;++i){ // left to right
            if(ratings[i] > ratings[i-1])
                temp[i] = temp[i-1]+1;
        }
        for(int i{N-2}; i >= 0 ;--i){ // right to left
            if(ratings[i] > ratings[i+1])
            {
                if(temp[i]  <= temp[i+1])
                    temp[i] = temp[i+1]+1; 
            }
        }
        return accumulate(temp.begin(),temp.end(),0);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends