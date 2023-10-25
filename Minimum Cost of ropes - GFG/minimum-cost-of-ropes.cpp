//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    typedef long long ll;
    public:
    //Function to return the minimum cost of connecting the ropes.
    // long long minCost(long long arr[], long long n) {
    //     // here k = 2  will me a min heap
    //     ll cost = 0;
    //     priority_queue<ll, vector<ll>, greater<ll>>pq(arr, arr+n);
    //     while(pq.size() >= 2){
    //         int i = 2;
    //         ll temp = 0;
    //         while(i--){
    //             temp += pq.top();
    //             pq.pop();
    //         }
    //         cost += temp;
    //         pq.push(temp);
    //     }
    //     return cost;
    // }
    long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long>,greater<long long> > pq;
        
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        
        long long cost=0;
        
        while(pq.size()>1){
            long long a=pq.top();
            pq.pop();
            
            long long b=pq.top();
            pq.pop();
            
            long long sum=a+b;
            cost+=sum;
            
            pq.push(sum);
            
        }
        
        return cost;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Endsak