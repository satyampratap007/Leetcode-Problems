//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int equilibriumPoint(long long a[], int n) {
        if(n == 1)
            return 1;
            
        long long s_i{0}, s_j{0};
        int i = 0, j = n-1;
        while(i < j)
        {
            if(s_i == s_j)
            {
                s_i = 0;
                s_j = 0;
            }
            if(s_i < s_j)
            {
                s_i += a[i];
                i++;
            }
            else{
                s_j += a[j];
                j--;
            }
        }
        return (s_i == s_j) ? i+1 : -1;
    }
};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends