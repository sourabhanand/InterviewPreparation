
 // } Driver Code Ends

class Solution
{
	public:
	    std::vector<std::vector<int>> table;
	    void init(int n, int m) {
	        table.resize(n);
	        for(int i = 0; i <n; ++i) {
	            table[i].resize(m);
	        }
	        
	        for(int i =0; i < n; ++i) {
	            for(int j =0; j <m; ++j) {
	                if(i == 0 || j == 0)
	                    table[i][j] = 0;
	            }
	        }
	        
	    }
	    void fillLcsTable(const string& s, const string& t, int n, int m) {
	        init(n+1, m+1);
	        
	        for(int i = 1; i <=n; ++i) {
	            for(int j = 1; j<=m; ++j) {
	                if(s[i-1] == t[j-1]) {
	                    table[i][j] = 1 + table[i-1][j-1];
	                } else {
	                    table[i][j] = max(table[i][j-1], table[i-1][j]);
	                }
	            }
	        }
	        
	    }
	    void printTable(int n, int m) {
	        for(int i = 0; i <= n; ++i) {
	            for(int j = 0; j <=m; ++j) {
	                std::cout << table[i][j] << " ";
	            }
	            std::cout << std::endl;
	        }
	    }
	    void display(const string& lcs) {
	        int n = lcs.size();
	        for(int i = n-1; i >=0; --i) {
	            std::cout << lcs[i];
	        }
	        std::cout << std::endl;
	    }
	    void printLCS(const string& s, const string& t, int n, int m,
	                  string lcs, set<string>& allLCS)
	   {
	        if(n == 0 || m == 0) {
	            //string copy = lcs;
                std::reverse(lcs.begin(), lcs.end());
                allLCS.insert(lcs);
	            return;
	        }
	        if(s[n-1] == t[m-1]) {
	            lcs.push_back(s[n-1]);
	            printLCS(s,t,n-1,m-1,lcs,allLCS);
	            //lcs.pop_back();
	        } else {
	            if(table[n-1][m] > table[n][m-1])
	                printLCS(s,t,n-1,m,lcs,allLCS);
	            else if(table[n-1][m] < table[n][m-1])
	                printLCS(s,t,n,m-1,lcs,allLCS);
	            else {
	                printLCS(s,t,n-1,m,lcs,allLCS);
	                printLCS(s,t,n,m-1,lcs,allLCS);
	            }
	        }
	    }
		vector<string> all_longest_common_subsequences(string s, string t)
		{
		    // Code here
		    int n = s.length();
	        int m = t.length();
	        fillLcsTable(s, t, n, m);
	        //printTable(n, m);
	        string lcs;
	        std::set<std::string> allLCS;
	        printLCS(s,t,n,m,lcs, allLCS);
	        vector<string> vs(allLCS.begin(), allLCS.end());
	        return vs;
		}
};



// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}

  // } Driver Code Ends
