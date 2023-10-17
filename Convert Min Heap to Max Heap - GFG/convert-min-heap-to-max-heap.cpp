//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void max_heap_heapify(vector<int> &arr, int size,int ind)
    {
        int l = 2 * ind + 1;
        int r = 2 * ind + 2;
        int maxi = ind;
        
        if(l < size && arr[l] > arr[maxi]){
            maxi = l;
        }
        if(r < size && arr[r] > arr[maxi]){
            maxi = r;
        }
        if(maxi != ind){
            swap(arr[ind],arr[maxi]);
            max_heap_heapify(arr, size,maxi);
            
        }
    }
    void convertMinToMaxHeap(vector<int> &arr, int N){
        for(int i = N-1; i >= 0; --i){
            max_heap_heapify(arr,N,i);
        }
    
    }
    
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends