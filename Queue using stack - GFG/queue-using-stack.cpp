//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Queue {
    stack<int> input, output;
public:
    stack <int> s1,s2;
    int temp = INT_MIN;
    void enqueue(int x) 
    {
        s1.push(x);
    }

    int dequeue() {
        if(!s2.empty())
        {
            temp = s2.top(),s2.pop();
            return temp;
        }
        
        if(s1.empty())
            return -1;
        
        while(!s1.empty())
        {
            s2.push(s1.top()),s1.pop();
        }
        temp = s2.top();
        s2.pop();
        return temp;
    }
    
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Queue ob;

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            ob.enqueue(a);
        }
        else if(QueryType==2)
        {
            cout<<ob.dequeue()<<" ";

        }
        }
    cout<<endl;
    }
}

// } Driver Code Ends