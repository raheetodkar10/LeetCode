class Solution {
public:
    long long int mod = 1000000007; //given(10^9+7)
    int solveByRec(int n, int k, int target){
        //base cases
        if(n<0 || target<0){  //neg no. of dice ani target not considered
            return 0;
        }
        if(n == 0 && target == 0){
            return 1; //kahi nahi karaycha
        }
        if(n == 0 && target != 0){  //dice nahey ani target banvaychay, not possible
            return 0;
        }
        if(n != 0 && target == 0){
            return 0;
        }

        int ans = 0;
        for(int val=1;val<=k;val++){
            ans = ans + solveByRec(n-1, k, target-val);
        }
        return ans;
    }

    //2d dp: n and target changes 
    int solveByMem(int n, int k, int target, vector<vector<long long int>>& dp){
         //base cases
        if(n<0 || target<0){  //neg no. of dice ani target not considered
            return 0;
        }
        if(n == 0 && target == 0){
            return 1; //kahi nahi karaycha
        }
        if(n == 0 && target != 0){  //dice nahey ani target banvaychay, not possible
            return 0;
        }
        if(n != 0 && target == 0){
            return 0;
        }
        if(dp[n][target] != -1){   
            return dp[n][target];
        }

        long long int ans = 0;
        for(int val=1;val<=k;val++){
            ans = (ans%mod + solveByMem(n-1, k, target-val, dp)%mod) % mod;
        }
        dp[n][target] = ans;
        return ans;
    }

    //Bottom up
    int solveByTabulation(int n, int k, int target){
        //step1
        vector<vector<long long int>> dp(n+1, vector<long long int>(target+1, 0));  //mostly base case mde return 0 yetay so. jyat return 1 hotay we'll handle it separately
        //step2
        dp[0][0] = 1;  //1 wala case
        //step3: reverse flow, for loop, copy paste, replace rec calls, looping variables
        for(int i=1;i<=n;i++){  //variable for n, 0 is handled already ie dp[0][0] = 1;
            for(int j=1;j<=target;j++){  //variable for target,  0 is handled already ie dp[0][0] = 1;
                long long int ans = 0;
                for(int val=1;val<=k;val++){
                    long long int temp = 0;
                    if(j-val >= 0){
                        temp = dp[i-1][j-val]%mod;
                    }
                    ans = (ans%mod + temp)%mod;  //j-val can give -ve val which causes runtime error, so handled separately
                }
                dp[i][j] = ans;
            }
        }
        //step4
        return dp[n][target];
    }

    int solveBySO(int n, int k, int target){
        //vector<vector<long long int>> dp(n+1, vector<long long int>(target+1, 0)); 
        vector<int> prev(target+1, 0); 
        vector<int> curr(target+1, 0); 
        //dp[0] -> 0th row. starting la we considered 0th row as prev and 1st row as curr
        //0th row -> prev
        prev[0] = 1;  //instead of dp[0][0] = 1;  
        for(int i=1;i<=n;i++){ 
            for(int j=1;j<=target;j++){  
                long long int ans = 0;
                for(int val=1;val<=k;val++){
                    long long int temp = 0;
                    if(j-val >= 0){
                        temp = prev[j-val]%mod;  //dp[i-1] ie adhica index->prev
                    }
                    ans = (ans%mod + temp) % mod;  
                }
                curr[j] = ans;   //dp[i]->curr
            }
            prev = curr;
        }
        return prev[target];  //curr pn lihu shakto
    }
    //j-val can be any val so we cannot space optimize it more

    int numRollsToTarget(int n, int k, int target) {
        //target->cols
        //vector<vector<long long int>> dp(n+1, vector<long long int>(target+1, -1));
        int ans = solveBySO(n, k, target);
        return ans;
    }
};