//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
 
   int solveSO(int arr[],int n,int t){
       vector<int> curr(t+1,0);
       vector<int> next(t+1,0);
       
       curr[0]=1;
       next[0]=1;
       
       for(int index=n-1;index>=0;index--){
           for(int target=1;target<=t;target++){
               int inc=0;
               if(target-arr[index] >=0)
                   inc = next[target-arr[index]];
               int exc = next[target];
               
               curr[target] = max(inc,exc);
           }
           next = curr;
       }
       return next[t];
   }
   
   int equalPartition(int N, int arr[])
   {
       int sum = accumulate(arr,arr+N,0);
       if(sum &1) return 0;
       int target = sum/2;
       return solveSO(arr,N,target);
       
   }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends