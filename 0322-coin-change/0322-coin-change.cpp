class Solution {
public:
    int solveByRec(vector<int>& coins, int amount){
        //base case
        if(amount == 0){
            return 0;
        }
        //is amount ko create krne ke liye i'll try every coin
        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(coins[i] <= amount){
                //valid
                //mene ek coin use kr liya
                int recKaAns = solveByRec(coins,amount-coins[i]);  //updated amount: amount-coins[i] honar
                //rec ka ans can be valid or invalid
                if(recKaAns != INT_MAX){  // ==-> mini update zhala nahi means its invalid  ans, then at that time we'll do nothing
                    //ek valid ans mila he
                    //it may or may not be a minimum answer
                    //so we'll atleast try to update mini
                    mini = min(mini, 1 + recKaAns); //before recKaAns, we've 'mene ek coin use kr liya' so 1+recKaAns
                }
            }
        }
        return mini;
    }

    //Rec+Mem
    //1d DP
    int solveByMem(vector<int>& coins, int amount, vector<int>& dp){
        if(amount == 0){
            return 0;
        }
        if(dp[amount] != -1){
            return dp[amount];
        }
        
        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(coins[i] <= amount){
                int recKaAns = solveByMem(coins,amount-coins[i], dp);  
                if(recKaAns != INT_MAX){  
                    mini = min(mini, 1 + recKaAns);
                    //here 1+ represents the coin we used in line 13 
                }
            }
        }
        dp[amount] = mini;
        return mini;
    }

    //Tabulation method
    int solveByTabulation(vector<int>& coins, int amount){
        //step1: dp array create
        int n = amount;
        vector<int> dp(n+1, INT_MAX);
        //step2: analyze base case and fill dp array
        dp[0] = 0;
        //step3: for loop, reverse the flow, looping variable, replace function calls
        for(int val=1;val <= amount;val++){  //0 sathi already ans kadlay so from 1
            int mini = INT_MAX;
            for(int i=0;i<coins.size();i++){
                if(coins[i] <= val){
                    int recKaAns = dp[val-coins[i]];  //amount la val sobat replace
                    if(recKaAns != INT_MAX){  
                        mini = min(mini, 1 + recKaAns);
                    }
                }
            }
            dp[val] = mini;
        }
        //step4
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = amount;
        //vector<int> dp(n+1,-1);
        int ans = solveByTabulation(coins,amount);
        if(ans == INT_MAX){   //invalid 
            return -1;   
        } 
        else{
            return ans;
        }
    }
};