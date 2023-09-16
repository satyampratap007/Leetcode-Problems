//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
        // Brute Force
    // long long trappingWater(int arr[], int n){
    //     long long res {0};
    //     for(int i{1}; i < n-1; ++i)
    //     {
    //         int lmax = arr[i];
    //         for(int l{0}; l < i; ++l)
    //         {
    //             lmax = max(lmax, arr[l]);
    //         }
            
    //         int rmax = arr[i];
    //         for(int r{i+1}; r < n; ++r)
    //         {
    //             rmax = max(rmax,arr[r]);
    //         }
            
    //         res += (min(lmax, rmax) - arr[i]);
    //     }
    //     return res;
    // }
    
    //  Using lmax and rmax array
    long long trappingWater(int arr[], int n){
        int pre_max[n];
        // finding the lmax array
        pre_max[0] = arr[0];
        for(int i{1}; i < n; ++i)
        {
            pre_max[i] = max(arr[i], pre_max[i-1]);
        }
        
        // Finding the rightmax array
        int suff_max[n];
        suff_max[n-1] = arr[n-1];
        for(int i{n-2}; i >= 0; --i)
        {
            suff_max[i] = max(arr[i], suff_max[i+1]);
        }
        long long pre = 0;
        for(int i{1}; i < n-1; ++i)
        {
            pre += (min(pre_max[i], suff_max[i]) - arr[i]);
        }
        return pre;
    
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends