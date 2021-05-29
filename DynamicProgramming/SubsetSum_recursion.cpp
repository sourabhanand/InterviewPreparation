//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    bool isInit = false;
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
                table[i][j] = -1;
            }
        }
        isInit = true;
    }
    bool isSubsetSum(int N, int arr[], int sum) {
        // code here
        if(isInit == false) {
            init(N+1,sum+1);
        }
        if(N == 0) {
            if(sum == 0) return true;
            return false;
        }
        if(table[N-1][sum] != -1) return table[N-1][sum];
        else {
            if(arr[N-1] > sum)
                return table[N-1][sum] = isSubsetSum(N-1, arr, sum);
            else {
                return table[N-1][sum] = (isSubsetSum(N-1, arr, (sum-arr[N-1]))
                        || isSubsetSum(N-1, arr, sum));
            }
        }
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
