#include <bits/stdc++.h>
#include <climits>
using namespace std;

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
    int maximizeTheCuts(int x, int y, int z, int n, int maxLen)
    {
        //Your code here
        /*
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
        if(0) {
            for(int i = 0; i < 4; ++i) {
                for(int j = 0; j <=n; ++j) {
                    std::cout << table[i][j] <<" ";
                }
                std::cout << std::endl;
            }
        }
        return table[3][n];
        */

        if( n == 0)
            if(maxLen == 0) return 0;
            else return INT_MIN;
        if((n == x || n == y || n == z) && n <= maxLen) {

            return max(1+maximizeTheCuts(x,y,z,n,maxLen-n),
                       maximizeTheCuts(x,y,z,n-1,maxLen));

        } else {
            return maximizeTheCuts(x,y,z,n-1,maxLen);
        }
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int x,y,z;
        cin >> x >> y >> z;
        int maxLen = n;
        Solution obj;
        //std::cout << "N: " << n << " x,y,z" << x << ", " << y << ", " << z << std::endl;
        std::cout << "Result: " << obj.maximizeTheCuts(x, y, z, n, maxLen) << std::endl;
    }
    return 0;
}
