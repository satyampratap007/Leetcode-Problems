//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* reverse(Node*head){
        if(!head || !head->next)    return head;
        Node* prev = NULL;
        Node* curr = head;
        while(curr){
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    struct Node* addTwoLists(struct Node* l1, struct Node* l2)
    {
        if(!l1 && !l2)  return l1;
        l1 = reverse(l1);
        l2 = reverse(l2);
        int carry{0};
        Node* dummy = new Node (carry);
        Node* temp = dummy;
        while(l1 || l2 || carry)
        {
            int sum = carry;
            if(l1)
            {
                sum += l1->data;
                l1 = l1->next;
            }
            if(l2)
            {
                sum += l2->data;
                l2 = l2->next;                
            }
            Node* node = new Node(sum%10);
            temp->next = node;
            carry = sum/10;
            temp = temp->next;
        }
        Node* n_h = reverse(dummy->next);
        return n_h;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends