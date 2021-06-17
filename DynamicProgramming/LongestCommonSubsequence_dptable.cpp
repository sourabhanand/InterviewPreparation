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
                /*
                else
                    table[i][j]= -1;
                */
            }
        }
        isInit = true;
    }
    void printTable(int x, int y) {
        for(int i = 0; i <=x; ++i){
            for(int j = 0; j<= y; ++j) {
                std::cout << table[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string& s1, string& s2)
    {
        if(isInit == false) {
            init(x+1, y+1);
        }
        //printTable(x, y);
        //std::cout << std::endl;
        //std::cout << std::endl;
        // your code here
        for(int i = 1; i <= x; ++i) {
            for(int j = 1; j <= y; ++j) {
                
                if(s1[i-1] == s2[j-1]) {
                    table[i][j] = 1 + table[i-1][j-1];
                } else {
                    table[i][j] = max(table[i-1][j], table[i][j-1]);
                }
            }
        }
        //printTable(x, y);
        return table[x][y];
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
