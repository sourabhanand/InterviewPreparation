#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

    public:
    std::vector<std::vector<int>> table;
    void init(int M, int V, int coins[]) {
        table.resize(M);
        for(int i = 0; i < M; ++i) {
            table[i].resize(V);
        }
        for(int i = 0; i < M; ++i)
            table[i][0] = 0;
        for(int i = 0; i < V; ++i)
            table[0][i] = INT_MAX - 1;

        for(int i = 1; i < V; ++i)
            if(i % coins[0] == 0)
                table[1][i] = i/coins[0];
            else
                table[1][i] = INT_MAX - 1;

    }
    int minCoins(int coins[], int M, int V)
    {
        // Your code goes here
        init(M+1, V+1, coins);
        for(int i = 1; i <= M; ++i) {
            for(int j = 1; j <= V; ++j) {
                if(coins[i-1] <= j) {
                    table[i][j] = min(1+table[i][j-coins[i-1]],
                                      table[i-1][j]);
                } else {
                    table[i][j] = table[i-1][j];
                }
            }
        }
        /*
        for(int i = 0; i <=M; ++i) {
            for(int j = 0; j <=V; ++j) {
                std::cout << table[i][j]<< " ";
            }
            std::cout << std::endl;
        }
        */
        if(table[M][V] == INT_MAX - 1)
            return -1;
        return table[M][V];
    }

};

// { Driver Code Starts.
int main()
{


    int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
            cin >> coins[i];


        Solution ob;
        cout << ob.minCoins(coins, m, v) << "\n";

    }
    return 0;
}
  // } Driver Code Ends
