//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void DFS(vector<vector<char>>& board, int i, int j, int n, int m) {
            if(i<0 or j<0 or i>=n or j>=m or board[i][j] != 'O') return;
            board[i][j] = '#';
            DFS(board, i-1, j, n, m);
            DFS(board, i+1, j, n, m);
            DFS(board, i, j-1, n, m);
            DFS(board, i, j+1, n, m);
        }
        vector<vector<char>> fill(int n, int m, vector<vector<char>> board)
        {
            // code here
                  //We will use boundary DFS to solve this problem
            
          // Let's analyze when an 'O' cannot be flipped,
          // if it has atleast one 'O' in it's adjacent, AND ultimately this chain of adjacent 'O's is connected to some 'O' which lies on boundary of board
            
          //consider these two cases for clarity :
          /*
            O's won't be flipped          O's will be flipped
            [X O X X X]                   [X X X X X]     
            [X O O O X]                   [X O O O X]
            [X O X X X]                   [X O X X X] 
            [X X X X X]                   [X X X X X]
          
          So we can conclude if a chain of adjacent O's is connected some O on boundary then they cannot be flipped
          
          */
            
          //Steps to Solve :
          //1. Move over the boundary of board, and find O's 
          //2. Every time we find an O, perform DFS from it's position
          //3. In DFS convert all 'O' to '#'      (why?? so that we can differentiate which 'O' can be flipped and which cannot be)   
          //4. After all DFSs have been performed, board contains three elements,#,O and X
          //5. 'O' are left over elements which are not connected to any boundary O, so flip them to 'X'
          //6. '#' are elements which cannot be flipped to 'X', so flip them back to 'O'
          //7. finally, Upvote the solution😊   
            
          
            
                
             if(n == 0) return board;  
                
             
             //Moving over firts and last column   
             for(int i=0; i<n; i++) {
                 if(board[i][0] == 'O')
                     DFS(board, i, 0, n, m);
                 if(board[i][m-1] == 'O')
                     DFS(board, i, m-1, n, m);
             }
                
                
             //Moving over first and last row   
             for(int j=0; j<m; j++) {
                 if(board[0][j] == 'O')
                     DFS(board, 0, j, n, m);
                 if(board[n-1][j] == 'O')
                     DFS(board, n-1, j, n, m);
             }
                
             for(int i=0; i<n; i++)
                 for(int j=0; j<m; j++)
                 {
                     if(board[i][j] == 'O')
                         board[i][j] = 'X';
                     if(board[i][j] == '#')
                         board[i][j] = 'O';
                 }
         
            return board;
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends