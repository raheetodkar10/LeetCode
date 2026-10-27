class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {  //TC:O(N) , SC:O(1)
        //Sliding window
        int sum = 0;
        for(int i=0;i<k;i++){
            sum += nums[i];
        }
        int maxSum = sum;   //maxSum mde initial sum stored
        for(int i=k;i<nums.size();i++){   //Since the first k elements are already processed, we start i at k
            sum = sum - nums[i-k] + nums[i];   //new sum = prev sum - outgoing no. + incoming no.
            maxSum = max(maxSum,sum);
        }
        return (double) maxSum / k;
    }
};