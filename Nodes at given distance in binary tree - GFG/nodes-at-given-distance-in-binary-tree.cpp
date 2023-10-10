//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
public:
    Node* find_target(Node* root, int target)
    {
        if (!root) return nullptr;
        if (root->data == target) return root;
        Node* left_result = find_target(root->left, target);
        if (left_result) return left_result; // If found in the left subtree, return it.
        return find_target(root->right, target); // Otherwise, search in the right subtree.
    }

    void dfs(Node* root,unordered_map <Node*,Node*> &p_map)
        {
            queue <Node*> q;
            q.push(root);
            while(!q.empty())
            {
                Node* temp = q.front();
                q.pop();
                if(temp->left)
                {
                    p_map[temp->left] = temp;
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    p_map[temp->right] = temp;
                    q.push(temp->right);
                }
            }
        }
    
    vector<int> KDistanceNodes(Node* root, int t, int k) {
        unordered_map <Node*,Node*> p_map;
        dfs(root, p_map); // mapping parent

        unordered_map <Node*,bool> visited; // visited node
        
        Node*target = find_target(root,t); // to find the target node
       
        queue <Node*> q;
        q.push(target);
        visited[target] = true;
        while(!q.empty())
        {
            int len = q.size();
            if(k-- == 0)  break;
            for(int i{0}; i < len; ++i)
            {
                Node* temp = q.front();
                q.pop();
                if(temp->left && !visited[temp->left])  // left
                {
                    q.push(temp->left);
                    visited[temp->left] = true;
                }
                if(temp->right && !visited[temp->right]) // right
                {
                    q.push(temp->right);
                    visited[temp->right] = true;
                }
                if(p_map[temp] && !visited[p_map[temp]])  // upward
                {
                    q.push(p_map[temp]);
                    visited[p_map[temp]] = true;
                }
            }
        }

        vector <int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->data);
            q.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends