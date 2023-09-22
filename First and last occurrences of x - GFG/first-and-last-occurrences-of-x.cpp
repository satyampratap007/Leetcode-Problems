//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
    int first_occ(int *arr, int size, int low , int high, int target)
    {
        int ans = -1;
        while(low <= high)
        {
            int mid = low + (high- low)/2;
            if(arr[mid] >= target){
                if(arr[mid] == target)
                {
                    ans = mid;
                }
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    
    int last_occ(int *arr, int size, int low , int high, int target){
        int ans = -1;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid] <= target){
                if(arr[mid] == target)
                {
                    ans = mid;
                }
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
    
    
    vector<int> find(int arr[], int n , int x )
    {
        vector <int> ans(2,-1);
        int first = first_occ(arr,n,0,n,x);
        int last = last_occ(arr,n,0,n,x);
        return {first, last};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends