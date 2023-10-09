//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    // int findZeroes(int arr[], int n, int k) {
        // Similar to at most k 0
        // int i{0}, j{0};
        // int maxi = 0;
        
        // while(j < n)
        // {
        //     if(arr[j] == 0 )
        //         k--;
        //     while(k < 0 && arr[i++] == 0)
        //         k++;
        //     if(k >= 0)
        //         maxi = max(maxi, j-i+1);
        //     j++;
        // }
        // return maxi;
    // }  
    
    //  OR
    
    int findZeroes(int arr[], int n, int k) {
        // Similar to at most k 0
        int i{0}, j{0};

        while(j < n)
        {
            if(arr[j] == 0 )
                k--;
            if(k < 0 && arr[i++] == 0)
                k++;
            j++;
        }
        return j-i;
    }  
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends