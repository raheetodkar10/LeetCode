class Solution {
public:
    bool solveByRec(int index, vector<int>& nums, int target){  //TC:exponential
        //base case
        int n = nums.size();
        if(index >= n){
            return 0;
        }
        if(target < 0){
            return 0;
        }
        if(target == 0){
            return 1;  //true, means subset is found
        }
        bool include = solveByRec(index+1, nums, target-nums[index]);
        bool exclude = solveByRec(index+1, nums, target);
        return (include || exclude);
    }
    //2d dp-> index & target changes
    bool solveByMem(int index, vector<int>& nums, int target, vector<vector<int>>& dp){  //TC & SC: n*m, n->size of nums and m->target
        //base case
        int n = nums.size();
        if(index >= n){
            return 0;
        }
        if(target < 0){
            return 0;
        }
        if(target == 0){
            return 1;  //true, means subset is found
        }
        if(dp[index][target] != -1){
            return dp[index][target];
        }
        bool include = solveByMem(index+1, nums, target-nums[index], dp);
        bool exclude = solveByMem(index+1, nums, target, dp);
        dp[index][target] = (include || exclude);
        return dp[index][target];
    }

    bool solveByTabulation(vector<int>& nums, int target){  //n rows banavliy so last index will be n-1 . SC:O(n), TC: n*m
        int n = nums.size();
        vector<vector<int>> dp(nums.size()+1, vector<int>(target+1,0));   //no need to consider base cases of 0 as we already initialized it with 0
        //down: in loop i=n-1 and we are accessing i+1 in include, that means we are talking about n so nums.size()+1
        //from base case: if(target == 0) return 1;   target ie. column 0 hoil tevha return 1
        for(int i=0;i<nums.size();i++){
            dp[i][0] = 1;
        }
        for(int i=n-1;i>=0;i--){  //index
            for(int t=1;t<=target;t++){  //target. target = 0 already handle kelay so start from 1
            bool include = 0;
            if(t-nums[i] >= 0){
                include = dp[i+1][t-nums[i]];
            }
            bool exclude = dp[i+1][t];
            dp[i][t] = (include || exclude);
            }
        }
        return dp[0][target];   //index goes from n to 0 so we'll have ans at 0 index
    }

    bool solveByTabulationSO(vector<int>& nums, int target){  
        int n = nums.size();
        vector<int> curr(target+1, 0);
        vector<int> next(target+1, 0);
        curr[0] = 1;
        next[0] = 1;
        for(int i=n-1;i>=0;i--){  //index
            for(int t=1;t<=target;t++){  //target. target = 0 already handle kelay so start from 1
            bool include = 0;
            if(t-nums[i] >= 0){
                include = next[t-nums[i]];
            }
            bool exclude = next[t];
            curr[t] = (include || exclude);
            }
            //shift
            next = curr;
        }
        return next[target];   //index goes from n to 0 so we'll have ans at 0 index
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }
        //imp
        if(sum & 1){   //jr sum odd asel tr 2 parts mde divide ch nai honar, so always false
            return false;
        }
        int target = sum/2;
        int index = 0;
        //bool ans = solveByRec(index, nums, target);
        //vector<vector<int>> dp(nums.size(), vector<int>(target+1,-1));
        //bool ans = solveByMem(index, nums, target, dp);
        bool ans = solveByTabulationSO(nums, target);
        return ans;
    }
};