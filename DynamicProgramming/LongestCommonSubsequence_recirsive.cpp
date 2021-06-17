#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    bool isInit = false;
    std::vector<std::vector<int>> table;
    void init(int x, int y) {
        table.resize(x);
        for(int i = 0; i < x; ++i) {
            table[i].resize(y);
        }
        for(int i = 0; i < x; ++i) {
            for(int j = 0; j < y; ++j) {
                if(i == 0 || j == 0)
                    table[i][j] = 0;
                else
                    table[i][j]= -1;
            }
        }
        isInit = true;
    }
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string& s1, string& s2)
    {
        if(isInit == false) {
            init(x+1, y+1);
        }
        // your code here
        if(x == 0 || y == 0) return 0;

        if(table[x][y] != -1) {
            return table[x][y];
        } else {
            if(s1[x-1] == s2[y-1]) {
                return table[x][y] = (1 + lcs(x-1, y-1, s1, s2));
            } else {
                return table[x][y] = max ( lcs(x-1, y, s1, s2),
                                           lcs(x, y-1, s1, s2)
                                        );
            }
        }
        //return table[x][y];
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends
