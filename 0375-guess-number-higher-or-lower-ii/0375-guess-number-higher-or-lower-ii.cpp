class Solution {
public:
    int solveByRec(int start, int end){
        if(start >= end){
            return 0;
        }
        int ans = INT_MAX;  //min hava ahe so
        for(int i=start;i<=end;i++){
            ans = min(ans, i + max(solveByRec(start,i-1), solveByRec(i+1, end)));
        }
        return ans;
    }

    //2d dp
    int solveByMem(int start, int end, vector<vector<int>>& dp){  //TC:O(n*n*n), SC:O(n*n)
        if(start >= end){
            return 0;
        }
        if(dp[start][end] != -1){
            return dp[start][end];
        }
        int ans = INT_MAX;  //min hava ahe so
        for(int i=start;i<=end;i++){
            ans = min(ans, i + max(solveByMem(start,i-1, dp), solveByMem(i+1, end, dp)));
        }
        dp[start][end] =  ans;
        return dp[start][end];
    }

    int solveByTabulation(int n){   //TC:O(n*n*n), SC:O(n*n)
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));  //i+1 use kella ahe so n+2 ie size vadhavli
        for(int start = n;start >= 1;start--){
            for(int end = 1;end <= n;end++){
                if(start >= end){   //from base case:if(start >= end) return 0
                    continue;
                }
                else{
                    int ans = INT_MAX;  //min hava ahe so
                    for(int i=start;i<=end;i++){
                        ans = min(ans, i + max(dp[start][i-1], dp[i+1][end]));
                    }
                    dp[start][end] =  ans;
                }
            }
        }
        return dp[1][n];
    }

    int getMoneyAmount(int n) {
        //int ans = solveByRec(1,n);   //1,n is range
        //vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        //int ans = solveByMem(1, n, dp);
        int ans = solveByTabulation(n);
        return ans;
    }
};