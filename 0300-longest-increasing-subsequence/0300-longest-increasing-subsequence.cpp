class Solution {
public:
    int solveByRec(vector<int>& arr, int curr, int prev){
        //base case
        if(curr >= arr.size()){
            return 0;
        }
        //hr no. include nai kr sakte, but exclude kr sakte he
        int includeAns = 0;
        if(prev == -1 || arr[curr] > arr[prev]){
            //we will include
            includeAns = 1 + solveByRec(arr, curr+1, curr); //prev jithe adhi curr hota tikde janar
        }
        int excludeAns = 0 + solveByRec(arr, curr+1, prev);  //curr tr include hotch rahnar
        int finalAns = max(includeAns, excludeAns);
        return finalAns;
    }

    //2d DP (prev & curr both changed)
    //Top Down appr
    int solveByMem(vector<int>& arr, int curr, int prev, vector<vector<int>>& dp){
        //base case
        if(curr >= arr.size()){
            return 0;
        }
        //step3: check if ans already exists or not
        if(dp[curr][prev+1] != -1){  //ere, if we write just dp[curr][prev], tr prev separately handle karav lagnar as prev=-1 initialized, -1 la ek valid index banavnyasathi we will -1=1=0 so saglikde prev=1 kela (apn aplya nusar shift kru shakto by adding some +ve integer to get a valid index)
            return dp[curr][prev+1];
        }
        //hr no. include nai kr sakte, but exclude kr sakte he
        int includeAns = 0;
        if(prev == -1 || arr[curr] > arr[prev]){   //here prev==-1 initialized already so ethe prev+1 nahi kela
            //we will include
            includeAns = 1 + solveByMem(arr, curr+1, curr, dp); //prev jithe adhi curr hota tikde janar
        }
        int excludeAns = 0 + solveByMem(arr, curr+1, prev, dp);  //curr tr include hotch rahnar
        int finalAns = max(includeAns, excludeAns);
        //step2: store ans
        dp[curr][prev+1] = finalAns;
        return finalAns;
    }

    //Bottom up
    int solveByTabulation(vector<int>& arr){
        //step!: create dp array
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));  //(step2: initialized every val with 0)
        //step2: analyze base case and fill dp array
        //for curr=n, all answers shd be 0 in dp arr

        //step3: reverse flow, for loop, copy paste, replace recursive call, looping variable
        for(int curr=n-1;curr>=0;curr--){   //for curr==n, we have 0 so start from n-1
            for(int prev=curr-1;prev>=-1;prev--){   //top down mde prev goes from -1 to curr-1
                int includeAns = 0;
                if(prev == -1 || arr[curr] > arr[prev]){   //here prev==-1 initialized already so ethe prev+1 nahi kela
                    //we will include
                    includeAns = 1 + dp[curr+1][curr+1]; //prev jithe adhi curr hota tikde janar
                    //here prev(curr+1) is col and not variable, saglya cols ci position impact honar so +1 (same for prev+1 in excludeAns)
                }
                int excludeAns = 0 + dp[curr+1][prev+1];  //curr tr include hotch rahnar
                int finalAns = max(includeAns, excludeAns);
                //step2: store ans
                dp[curr][prev+1] = finalAns;
            }
        }
        //step4: return final ans
        return dp[0][0]; //from int prev = -1, int curr = 0; but apn col index +1 kelay so -1+1=0 in col
    }

    int lengthOfLIS(vector<int>& nums) {
        int prev = -1;
        int curr = 0;
        /*both are denoting indexes
        int ans = solveByRec(nums, curr, prev);
        return ans;*/
        /*2 d DP:Top down
        //step1: create, initialize, send, receive dp array
        //dp array depends on curr(row) and prev(col)
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        int ans = solveByMem(nums, curr, prev, dp);
        return ans;*/
        //Bottom up
        int ans = solveByTabulation(nums);
        return ans;
    }
};