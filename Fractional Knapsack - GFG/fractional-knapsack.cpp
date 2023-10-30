//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

 
class Solution
{
    public:
    struct  my_cmp{
        bool operator() (const Item &p1 ,const Item &p2){
            return p1.value/(p1.weight*1.0) > p2.value/(p2.weight*1.0); 
        }
    };
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr+n, my_cmp());
        double res = 0;
        int curr_w = W;
        
        for(int i{0}; i < n ; ++i) {
            if(arr[i].weight <= curr_w){
                res += arr[i].value;
                curr_w -= arr[i].weight;
            }
            else {
                res += arr[i].value * curr_w / (arr[i].weight*1.0);
                break;
            }
        }
        return res;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends