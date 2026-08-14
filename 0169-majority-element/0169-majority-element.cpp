class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];  //after sorting, Majority element appears more than n/2 times
        //So after sorting it MUST occupy middle position.
        /*another approach:Boyer Moore Voting algo TC:O(n), SC:O(1)
        int candidate = 0;  //current candidate
        int voteCount = 0;  //vote count of candidate
        for(int num:nums){
            if(voteCount == 0){   //if vote count is 0, choose new candidate
                candidate = num;
            }
            if(num == candidate){  //same count -> voteCount++
                voteCount++;
            }
            else{                 //different candidate -> voteCount--
                voteCount--;    
            }
        }
        return candidate;   //candidate with max votes   */
    }   
};