//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    priority_queue<int> left; // max_heap
    priority_queue<int,vector<int>, greater<int>> right; // min_heap
    //Function to insert heap.
    void insertHeap(int &num)
    {
        int lsize = left.size();
        int rsize = right.size();
        if(lsize == 0) // when left is empty
            left.push(num);
        else if(lsize == rsize){
            if(right.top() > num){
                left.push(num);
            }
            else{
                int temp = right.top();
                right.pop();
                right.push(num);
                left.push(temp);
            }
        }
        else{
            // when there is no element in the min_heap
            if(rsize == 0){ 
                if(num > left.top()){
                    right.push(num);
                }
                else{ // push num to max_heap
                    int temp = left.top();
                    left.pop();
                    left.push(num);
                    right.push(temp);
                }
            }
            else if(num >= right.top()) // push num to min_heap
                right.push(num);
            else{
                if(num < left.top()){
                    int temp = left.top();
                    left.pop();
                    left.push(num);
                    right.push(temp);                
                }
                else{
                    right.push(num);
                }
            }
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(left.size() > right.size())
            return left.top();
        else{
            return static_cast<double>(left.top() + right.top()) / 2;
        }
        
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends