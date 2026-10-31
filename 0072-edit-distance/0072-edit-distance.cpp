class Solution {
public:
    int solveByRec(string& a, string& b, int i, int j){  //string&-> changes memory exceed error to tle
        if(i == a.size()){
            return b.size()-j;
        }
        if(j == b.size()){
            return a.size()-i;
        }
        int ans = 0;
        if(a[i] == b[j]){
            ans = solveByRec(a, b, i+1, j+1);
        }
        else{
            //operations perform
            int insert = 1 + solveByRec(a, b, i, j+1);  //ek elem insert kela apn so +1, same for others
            int deleted = 1 + solveByRec(a, b, i+1, j);
            int replace = 1 + solveByRec(a, b, i+1, j+1);
            ans = min(insert, min(deleted, replace));
        }
        return ans;
    }

    int solveByMem(string a, string b, int i, int j, vector<vector<int>>& dp){
        if(i == a.size()){
            return b.size()-j;
        }
        if(j == b.size()){
            return a.size()-i;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = 0;
        if(a[i] == b[j]){
            ans = solveByMem(a, b, i+1, j+1, dp);
        }
        else{
            //operations perform
            int insert = 1 + solveByMem(a, b, i, j+1, dp);  //ek elem insert kela apn so +1, same for others
            int deleted = 1 + solveByMem(a, b, i+1, j, dp);
            int replace = 1 + solveByMem(a, b, i+1, j+1, dp);
            ans = min(insert, min(deleted, replace));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    int solveByTab(string a, string b){   //TC:O(n*m), SC:(m)
        vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1, 0));  //if we want to access a.size() from base case. it shd be valid index so +1
        for(int j=0;j<=b.size();j++){
            dp[a.size()][j] = b.size()-j;   //a.size() chya row sathi apn loop chalavtoy
        }
        for(int i=0;i<=a.size();i++){
            dp[i][b.size()] = a.size()-i;
        }
        //i, j goes from 0 to size-1, so here ulta
        for(int i=a.size()-1;i>=0;i--){
            for(int j=b.size()-1;j>=0;j--){
                int ans = 0;
                if(a[i] == b[j]){
                    ans = dp[i+1][j+1];
                }
                else{
                    //operations perform
                    int insert = 1 + dp[i][j+1];  //ek elem insert kela apn so +1, same for others
                    int deleted = 1 + dp[i+1][j];
                    int replace = 1 + dp[i+1][j+1];
                    ans = min(insert, min(deleted, replace));
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int solveByTabSO(string a, string b){
        vector<int> curr(b.size()+1, 0);  //for b.size() im accessing next[b.size()]  (causes out-of-bounds access)
        vector<int> next(b.size()+1, 0);

        for(int j=0; j<=b.size(); j++){
            next[j] = b.size()-j;   //a.size()+1 sathi a.size()(last row) will be the next row 
        }
        /*for(int i=0;i<=a.size();i++){
            dp[i][b.size()] = a.size()-i;
        }*/
        
        for(int i=a.size()-1;i>=0;i--){
            //imp
            //every row starts here
            curr[b.size()] = a.size()-i;
            for(int j=b.size()-1;j>=0;j--){
                int ans = 0;
                if(a[i] == b[j]){
                    ans = next[j+1];
                }
                else{
                    //operations perform
                    int insert = 1 + curr[j+1];  //ek elem insert kela apn so +1, same for others
                    int deleted = 1 + next[j];
                    int replace = 1 + next[j+1];
                    ans = min(insert, min(deleted, replace));
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];  //next contains the final computed DP row after the loop finishes due to next = curr so
    }

    int minDistance(string word1, string word2) {
        if(word1.size() == 0){  //jr word1 empty asel tr tyala word2 banavnyasathi word2.size() chi garaj honar
            return word2.size();
        }
        if(word2.size() == 0){
            return word1.size();
        }
        int i = 0;
        int j = 0;
        //vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        //return solveByMem(word1, word2, i, j, dp);
        return solveByTabSO(word1, word2);
    }
};