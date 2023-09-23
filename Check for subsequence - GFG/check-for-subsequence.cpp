//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std; 

// } Driver Code Ends

class Solution{
    public:
    
        bool isSubSequence(string s, string t) {
        // Brute Force
        int l1 = s.size();
        int l2 = t.size();
        int i=0,j=0;

        for(; i < l2 && j < l1; ++i)
        {
            if(s[j] == t[i]){
                j++;
            }
        }
        return (j == l1);
    }


    // bool isSubSequence(string s, string t) {
    //     int l1 = s.size();
    //     int l2 = t.size();
    //     if(l1 > l2) return false;
    //     int ind{0};
    //     for(int i{0}; i < l1; ++i)
    //     {
    //         bool flag = false;
    //         for(int j{ind}; j < l2; ++j)
    //         {
    //             if(s[i] == t[j])
    //             {
    //                 flag = true;
    //                 ind = j+1;
    //                 break;
    //             }
    //         }
    //         if(!flag)
    //             return false;
    //     }
    //     return true;

    // }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;  
        Solution ob;
        if(ob.isSubSequence(A,B))
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
    }
    return 0; 
} 

// } Driver Code Ends