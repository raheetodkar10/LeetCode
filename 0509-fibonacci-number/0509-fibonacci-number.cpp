class Solution {
public:
    int solveUsingMem(int n, vector<int>& dp){
        if(n == 0 || n == 1){
            return n;
        }
        //Step 3:check if ans already exists, if yes then return
        if(dp[n] != -1){
            return dp[n];
        }
        int ans = solveUsingMem(n-1,dp) + solveUsingMem(n-2,dp);
        //Step 2: store ans in dp array
        dp[n] = ans;
        return dp[n];
    }

    //Bottom up/Iterative/Tabulation appr
    int solveUsingTabulation(int n){
        //step 1: create dp array
        vector<int> dp(n+1,-1);
        //step 2: analyze base case and fill dp array
        if(n == 0) return 0;
        if(n == 1) return 1;   //if not written these 2 lines, code ft sakta he
        dp[0] = 0;
        dp[1] = 1;   //if n=0 then this step will throw error so handled separately
        //step 3: loop wala logic, reverse top-down flow
        for(int i=2;i<=n;i++){   //already handled for 0 & 1 so started from 2
            //copy paste
            //skip base case, ans already exist case, return statm
            //convert function calls to dp array
            //looping variable sahe se replace krdena
            int ans = dp[i-1] + dp[i-2];
            dp[i] = ans;
        }
        //step 4: return ans
        return dp[n];  //rule: go in main func & see whats passed with dp ie int ans = solveUsingMem(n,dp) that is n. so write that
    }

    //Space Optimization
    int solveUsingTabulationSO(int n){   //constant space
        vector<int> dp(n+1,-1);
        if(n == 0) return 0;
        if(n == 1) return 1;  

        int prev2 = 0;
        int prev1 = 1; 
        int curr = -1;  
        
        for(int i=2;i<=n;i++){   
            curr = prev1 + prev2;
            //ye me bhul sakti hu
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;  
    }

    /* appr2:
    int solveUsingRecursion(int n){
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        int ans = solveUsingRecursion(n-1) + solveUsingRecursion(n-2);
        return ans;
    }*/

    int fib(int n) {
        //vector<int> dp(n+1, -1);  //n+1->size, n+100 kahi pn gheu shakto fakt kami nai like n or n-1  and -1->initialized with it
        //Step 1: we figured out that it is 1D dp(n changed to n-1 and n-2)
        //create, initialize, pass the dp array
        int ans = solveUsingTabulationSO(n);
        return ans;
        /*appr 2:
        int ans = solveUsingRecursion(n);
        return ans; */
    }
};

//most time and space consuming: Rec->Mem->Tabulation

/*appr:
    if(n==0) return 0;
        if(n==1) return 1;
            int a = 0;
            int b = 1;
            for(int i=2;i<=n;i++){
                int c = a+b;
                a=b;
                b=c;
            }
        return b; */