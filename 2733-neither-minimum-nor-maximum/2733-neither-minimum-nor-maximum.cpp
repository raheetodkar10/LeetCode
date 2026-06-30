class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if(nums.size()<3){
            return -1;
        }
        sort(nums.begin(),nums.end());
        return nums[1];  ////sort kelyavr apoap min elem first and max elem last la asnar. So second elem return karaycha
    }
};

/*Another approach:
        int maxi=max(nums.begin(),nums.end());
        int mini=min(nums.begin(),nums.end());
        for(int x:nums){
            if(x!=maxi && x!=mini){
                return x;
            }
        }
        return -1;
min_element(start, end) : It finds the smallest element in a range*/