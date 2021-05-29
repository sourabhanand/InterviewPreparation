//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    //bool isInit = false;
    std::vector<std::vector<short>> table;
    void init(int n, int sum) {
        table.resize(n);
        for(int i = 0; i < n; i++) {
            table[i].resize(sum);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < sum; j++) {
                if(i == 0) {
                    table[i][j] = 0;
                }
                if (j == 0) {
                    table[i][j] = 1;
                    continue;
                }
                //table[i][j] = -1;
            }
        }
        //isInit = true;
    }
    bool isSubsetSum(int N, int arr[], int sum) {
        // code here

        init(N+1,sum+1);
        for(int i = 1; i <N+1; ++i) {
            for(int j = 1; j <sum+1; ++j) {
                if(arr[i-1] <= j) {
                    table[i][j] = ((table[i-1][j-arr[i-1]])
                                  || (table[i-1][j]));
                } else {
                    table[i][j] = table[i-1][j];
                }
            }
        }
        return table[N][sum];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;

        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0;
}
  // } Driver Code Ends
