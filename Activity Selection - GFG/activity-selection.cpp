//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int,int>> vec;
        for(int i{0}; i < n; ++i){
            vec.push_back({end[i],start[i]}); //<end , start>
        }
        sort(vec.begin(), vec.end());
        int res = 1;
        int check = vec[0].first;
        for(int i{1}; i < n;++i){
            if(vec[i].second > check)
            {
                res++;
                check = vec[i].first;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends