class Solution {
public:
    int solveByRec(vector<int>& arr, map< pair<int,int> , int>& maxi, int left, int right){
        //base case
        if(left == right){   //means we reached leaf node, but we want to store non leaf nodes so return 0
            return 0;
        }
        int ans = INT_MAX;
        for(int i=left;i<right;i++){
            ans = min(ans, maxi[{left, i}] * maxi[{i+1, right}] + solveByRec(arr, maxi, left, i) + solveByRec(arr, maxi, i+1, right));
        }
        return ans;
    }

    int solveByMem(vector<int>& arr, map< pair<int,int> , int>& maxi, int left, int right, vector<vector<int>>& dp){
        //base case
        if(left == right){   //means we reached leaf node, but we want to store non leaf nodes so return 0
            return 0;
        }
        if(dp[left][right] != -1){
            return dp[left][right];
        }
        int ans = INT_MAX;
        for(int i=left;i<right;i++){
            ans = min(ans, maxi[{left, i}] * maxi[{i+1, right}] + solveByMem(arr, maxi, left, i, dp) + solveByMem(arr, maxi, i+1, right, dp));
        }
        dp[left][right] = ans;
        return dp[left][right];
    }

    int solveByTabulation(vector<int>& arr, map< pair<int,int> , int>& maxi){
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));  //base case is of 0 only and we initialized with 0 already so no need to handle separately
        for(int left=n-1;left>=0;left--){
            for(int right=0;right<=n-1;right++){
                if(left >= right){   
                    continue;  //invalid range, kuch krne ki jarurat nai hei
                }
                else{  //valid range
                    int ans = INT_MAX;
                    for(int i=left;i<right;i++){
                        ans = min(ans, maxi[{left, i}] * maxi[{i+1, right}] + dp[left][i] + dp[i+1][right]);
                    }
                    dp[left][right] = ans;
                }
            }
        }
        return dp[0][n-1];
    }
    //for SO, dp[left][right] depends on both [i] & [i+1], means kisi bhi row and ksi bhi col pe depend krta ei so no SO
    int mctFromLeafValues(vector<int>& arr) {
        map< pair<int,int> , int> maxi;   //unordered map is based on hash map and there is no and for hash, pair doesn't exist. Map is based on tree map and there we can use pair
        /*instead of: maxi[{i,i}] = arr[i];   we can write 
        pair<int,int> p;
        p.first = i;
        p.second = i;
        maxi[p] = arr[i];*/
        for(int i=0;i<arr.size();i++){  //stores har range me se max val
            maxi[{i,i}] = arr[i];  //ex:maxi(1,1) will be val at arr[1]
            for(int j=i+1;j<arr.size();j++){
                maxi[{i,j}] = max(arr[j], maxi[{i,j-1}]);
            }
        }
        int n = arr.size();
        //int ans = solveByRec(arr, maxi, 0, n-1);  //0 to n-1 is the range
        //vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        //int ans = solveByMem(arr, maxi, 0, n-1);
        int ans = solveByTabulation(arr, maxi);
        return ans;
    }
};