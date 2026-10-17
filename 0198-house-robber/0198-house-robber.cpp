class Solution {
public:
    int solveByRec(vector<int>& nums,int index){
        //base case
        if(index >= nums.size()) return 0;
        //include
        int include = nums[index] + solveByRec(nums,index+2); //current house cha paisa and then remaining by recursion
        //exclude
        int exclude = 0 + solveByRec(nums,index+1);   //current house cha paisa nahi ghayaycha and then move to next house(curr house mde chori nai karaychi so tyachya pudchi karaychi)

        int ans = max(include, exclude);
        return ans;
    }   //OR

    //1d DP
    //Rec + Memoisation - Top down appr.
    int solveByMem(vector<int>& nums, int index, vector<int>& dp){
        //base case
        if(index >= nums.size()){
            return 0;
        }
        //step 3
        if(dp[index] != -1){
            return dp[index];
        }
        int include = nums[index] + solveByMem(nums,index+2,dp); 
        int exclude = 0 + solveByMem(nums,index+1,dp); 
        int ans = max(include, exclude);
        //step 2
        dp[index] = ans;  //jo parameter(here, index) change hoto to dp sobat ghayaycha
        return ans;
    }   //OR

    int solveByTabulation(vector<int>& nums){
        //step 1: dp array create initialize
        int n = nums.size();
        vector<int> dp(n+1,-1);
        //step 2:analyze base case and fill dp array
        dp[n] = 0;  //from:if(index = nums.size()) return 0;
        //step 3: reverse the flow, loop copy paste
        for(int i=n-1; i>=0; i--){     //n-1 range mde i+2 basnar nahi, so we'll handle it separately and will also check if it is range  (i=n-1 -> i+2=n-1+2=n+1 in range till n will be invalid)
            int temp = 0;    //we've alloted i+2 as 0 
            if(i+2 <= n){
                temp = dp[i+2];
            }
            int include = nums[i] + temp; 
            int exclude = 0 + dp[i+1]; 
            int ans = max(include, exclude);
            dp[i] = ans; 
        }
        //step 4
        return dp[0];  //index->0
    } //OR

    //Space Optimization
    int solveBySpaceOptimization(vector<int>& nums){  //copied from tabulation
        int n = nums.size();
        //vector<int> dp(n+1,-1);
        int next1 = 0;
        int next2 = 0;
        int curr;  
        for(int i=n-1; i>=0; i--){     
            int temp = 0;    
            if(i+2 <= n){
                temp = next2;
            }
            int include = nums[i] + temp; 
            int exclude = 0 + next1; 
            curr = max(include, exclude);
            //ye me bhul sakti hu, sifting
            next2 = next1;
            next1 = curr; 
        }
        return curr; 
    }

    int rob(vector<int>& nums) {
        //Include Exclude pattern 
        int index=0;
        //step 1
        int n = nums.size();
        vector<int> dp(n+1,-1);
        //int ans = solveByRec(nums,index);
        int ans = solveByMem(nums,index,dp);
        return ans;
    }
};