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
    struct Node{
        int val;
        int mini;
        Node* next;
        
        Node(int val, int mini, Node*next) : val(val),mini(mini),next(next) {}
    };
    Node* head;
    
    public:
    Solution():head(NULL) {}
    int getMin(){
        if(head == NULL)
            return -1;
        else{
            return head->mini;
        }
        
       }
       int pop(){
           if(head == NULL)
                return -1;
           else{
               Node* temp = head;
               int ans = temp->val;
               delete(temp);
               head = head->next;
               return ans;
           }
       }
       void push(int x){
           if(head != NULL)
           {
               head = new Node(x,min(x,head->mini), head);
           }
           else
           {
               head = new Node(x, x, nullptr);
           }
       }
        ~Solution() {
            while (head) {
                Node* temp = head;
                head = head->next;
                delete temp;
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