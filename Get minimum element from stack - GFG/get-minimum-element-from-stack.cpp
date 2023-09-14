//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    public:
        int ip[10000];
        int op[10000];
        int mini {-1};
        int curr {-1};
        int getMin(){
            if(mini < 0)    return -1;
            return op[mini];
       }
       
       /*returns poped element from stack*/
       int pop(){
           if(curr < 0 || mini < 0)
            return -1;
            else{
                int top = ip[curr];
                curr--;
                mini--;
                return top;
            }
            
       }
       void push(int x){
           if(curr >= 10000)
                return;
          
           ip[++curr] = x;
           if(mini < 0)
           {
               op[++mini] = x;        
           }
           else{
               int temp = op[mini];
               op[++mini] = min(x, temp);
           }
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends