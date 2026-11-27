class Solution {
public:
    int solveByRec(string a, string b, int i, int j){
        //base case
        if(i == a.size()){  //means pehli string khatam ho gyi, no char left there
            return 0;
        }
        if(j == b.size()){
            return 0;
        }
        if(a[i] == b[j]){   //a[i] = b[j] tyachi length 1 & curr char match kr chuke hei so ans mei 1 ayega he ayega and then bacha ua string call krdo
            return 1 + solveByRec(a, b, i+1, j+1);
        }
        else{    //no char match so returned 0
            return 0 + max(solveByRec(a, b, i, j+1) , solveByRec(a, b, i+1, j));
        }
    }

    int solveByMem(string& a, string& b, int i, int j, vector<vector<int>>& dp){   //string&: if not, gives tle  //TC:O(n*m) (n,m: size of text1 & text2)
        //base case
        if(i == a.size()){  //means pehli string khatam ho gyi, no char left there
            return 0;
        }
        if(j == b.size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(a[i] == b[j]){   //a[i] = b[j] tyachi length 1 & curr char match kr chuke hei so ans mei 1 ayega he ayega and then bacha ua string call krdo
            return 1 + solveByMem(a, b, i+1, j+1, dp);
        }
        else{    //no char match so returned 0
            return 0 + max(solveByMem(a, b, i, j+1, dp) , solveByMem(a, b, i+1, j, dp));
        }
        int ans = 0;
        dp[i][j] = ans;
        return dp[i][j];
    }

    int solveByTabulation(string a, string b){     //TC:O(n*m), (n,m: size of text1 & text2)
        vector<vector<int>>dp(a.size()+1, vector<int>(b.size()+1, 0));  //a.size() means last index(n-1) but we want to access nth index so +1
        for(int i=a.size()-1;i>=0;i--){
            for(int j=b.size()-1;j>=0;j--){
                int ans = 0;
                if(a[i] == b[j]){   
                    ans = 1 + dp[i+1][j+1];
                }
                else{    
                    ans = 0 + max(dp[i][j+1] , dp[i+1][j]);
                }
                dp[i][j] = ans;                                      
            }
        }
        return dp[0][0];  
    }

    int solveByTabulationSO(string a, string b){     //TC:O(n*m), SC:O(2m)
        vector<int> curr(b.size()+1, 0);
        vector<int> next(b.size()+1, 0);
        for(int i=a.size()-1;i>=0;i--){
            for(int j=b.size()-1;j>=0;j--){
                int ans = 0;
                if(a[i] == b[j]){   
                    ans = 1 + next[j+1];
                }
                else{    
                    ans = 0 + max(curr[j+1] , next[j]);
                }
                curr[j] = ans;                                      
            }
            //shift
            next = curr;
        }
        return curr[0]; 
    }

    int longestCommonSubsequence(string text1, string text2) {
        /*int i = 0;
        int j = 0;
        vector<vector<int>>dp(text1.size(), vector<int>(text2.size(), -1));
        return solveByMem(text1, text2, i, j, dp);*/
        return solveByTabulationSO(text1, text2);
    }
};