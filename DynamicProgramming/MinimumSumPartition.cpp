#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

    public:
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
            }
        }
    }
    bool isSubsetSum(int n, int arr[], int sum) {
        init(n+1,sum+1);
        for(int i = 1; i <n+1; ++i) {
            for(int j = 1; j <sum+1; ++j) {
                if(arr[i-1] <= j) {
                    table[i][j] = ((table[i-1][j-arr[i-1]])
                                  || (table[i-1][j]));
                } else {
                    table[i][j] = table[i-1][j];
                }
            }
        }
        return table[n][sum];
    }
    int minDiffernce(int arr[], int n)
    {
        unsigned long int sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += arr[i];
        }
        unsigned long int sumToCheck = sum/2;
        isSubsetSum(n, arr, sumToCheck);
        std::vector<unsigned long int> RangeMinus2S;
        for(int i = 0; i <= sumToCheck; ++i) {
            if(table[n][i]) {
                RangeMinus2S.push_back(sum - (2*i));
            }
        }
        auto it = std::min_element(RangeMinus2S.begin(), RangeMinus2S.end());
        return *it;
    }
};


// { Driver Code Starts.
int main()
{


    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];



        Solution ob;
        cout << ob.minDiffernce(a, n) << "\n";

    }
    return 0;
}  // } Driver Code Ends
