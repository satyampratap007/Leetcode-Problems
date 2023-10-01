//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void helper(vector<vector<int>> &matrix,int r,int c, vector <int> &row, vector <int> &col)
    {
        for(int i{0}; i < r; ++i)
        {
            if(row[i] == 1)
            {
                for(int j{0}; j < c; ++j)
                {
                    matrix[i][j] = 1;
                }
            }
        }
        
        for(int i{0}; i < c; ++i)
        {
            if(col[i] == 1)
            {
                for(int j{0}; j < r; ++j)
                {
                    matrix[j][i] = 1;
                }
            }
        }
        
    }
    
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        int r= matrix.size();
        int c = matrix[0].size();
        vector <int> row(r,0);
        vector <int> col(c,0);
        
        for(int i{0}; i < r; ++i)
        {
            for(int j{0}; j < c; ++j)
            {
                if(matrix[i][j] == 1)
                {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        helper(matrix,r,c, row, col);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}



// } Driver Code Ends