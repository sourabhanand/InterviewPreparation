#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends



class Solution
{
    public:
    std::vector<std::vector<int>> table;
    void init(int n) {
        table.resize(4);
        for(int i = 0; i < 4; ++i) {
            table[i].resize(n);
        }
        for(int i = 0; i < 4; ++i)
            table[i][0] = 0;
        for(int i = 1; i < n; ++i)
            table[0][i] = INT_MIN;
    }
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        init(n+1);
        int len[3];
        len[0] = x; len[1] = y; len[2] = z;

        for(int i = 1; i < 4; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(len[i-1] <= j) {
                    table[i][j] = max(1+table[i][j-len[i-1]], table[i-1][j]);
                } else {
                    table[i][j] = table[i-1][j];
                }
            }
        }
        if(table[3][n] < 0)
            return 0;
        return table[3][n];
    }
};

// { Driver Code Starts.
int main() {

    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;

        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

    return 0;
}  // } Driver Code Ends
