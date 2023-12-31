//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    // Brute Force 
    // int celebrity(vector<vector<int> >& M, int n) 
    // {
    //     // int pot {-1};
        // for(int i{0}; i < n; ++i)
        // {
        //     bool flag = true;
        //     for(int j{0}; j < n; ++j)
        //     {
        //         if(M[i][j] != 0)
        //         {
        //             flag = false;
        //             break;
        //         }
        //     }
        //     if(flag){
        //         pot = i;
        //         break;
        //     }
        // }
        // // Check for the pot candiate
    //     for(int i{0}; i < n; ++i)
    //     {
    //         if(i != pot)
    //         {
    //             if(M[i][pot] != 1 || M[pot][i] == 1 )
    //             {
    //                 return -1;
    //             }
    //         }
    //     }
    //     return pot;
    // }
    
    
    int celebrity(vector<vector<int> >& M, int n){
        // Creating stack to check for the potential candidate
        stack <int> st;
        for(int i{0}; i < n; ++i){
            st.push(i);
        }
        while(st.size() >= 2)
        {
            // check consecutively wheter they know each other or not
            int i = st.top();   st.pop();
            int j = st.top();   st.pop();
            // if i -> j push(j)
            if(M[i][j] == 1){
                st.push(j);
            }
            // else j -> i push(i) as if somebody know other then he can't be celebrity as per the given condition
            else{
                st.push(i);
            }
        }
        int pot = st.top();
        st.pop();
        // Check for the potential Candidate
        for(int i{0}; i < n; ++i)
        {
            if(i != pot)
            {
                if(M[i][pot] != 1 || M[pot][i] == 1)
                {
                    return -1;
                }
            }
        }
        return pot;
    }
   
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends