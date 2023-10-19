//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    // int kthSmallest(int arr[], int l, int r, int k) {
        // priority_queue <int, vector<int>, greater <int>> pq(arr, arr+r+1);
        // while(--k){
        //     pq.pop();
        // }
        // return pq.top();
        
        
        // priority_queue<int> pq;
        // for (int i=r; i>=0; i--)
        // {
        //     pq.push(arr[i]);
        //     if (pq.size() > k)pq.pop();
        // }
        // return pq.top();
// }
        
          int partition(int arr[], int l, int r) {
        int pivot = arr[l];
        int count = 0;
        for(int i = l+1; i <= r; ++i) {
            if(arr[i] <= pivot) {
                ++count;
            }
        }
        int pivotIndex = l + count;
        swap(arr[pivotIndex],arr[l]);
        int i = l, j = r;
        while (i < pivotIndex && j > pivotIndex) {
            while (arr[i] <= pivot) {
                i++;
            }
            while (arr[j] > pivot) {
                j--;
            }
            if (i < pivotIndex && j > pivotIndex) {
                swap(arr[i++], arr[j--]);
            }
        }
        return pivotIndex;
    }
    int kthSmallest(int arr[], int l, int r, int k) {
        int pivotIndex = partition(arr,l,r);
        if(pivotIndex == k-1) {
            return arr[pivotIndex];
        }
        if(pivotIndex > k-1) {
            return kthSmallest(arr,l,pivotIndex,k);  
        }
        return kthSmallest(arr,pivotIndex+1,r,k);
    }
        
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends