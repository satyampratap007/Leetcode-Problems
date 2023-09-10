//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
    //     stack <char> st;
        
    //     for(auto i : x) {
    //     if(i == '(' || i == '{' || i == '[')
    //         st.push(i);
    //     else if(i == ')' || i == '}' || i == ']') {
    //         if(st.empty() || 
    //           (i == ')' && st.top() != '(') ||
    //           (i == '}' && st.top() != '{') ||
    //           (i == ']' && st.top() != '[')) {
    //             return false;
    //         }
    //         st.pop();
    //     }
    // }
    // return st.empty();
    
        // More clean
        stack <char> st;
        
        for(auto i : x) {
            if(i == '(')
                st.push(')');
            else if(i == '{')
                st.push('}');
            else if(i == '[')
                st.push(']');
            else if(st.empty() || st.top() != i)
                return false;
            else
                st.pop();
        }
        return st.empty();
    }
};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends