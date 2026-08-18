class Solution {
public:
    void rotate(vector<int>& nums, int k) {   //TC:O(n) , SC:O(1)
        int n = nums.size();
        k = k%n;  //ex: 3 ch rotation asel, tr that rotation will be same for 6,9,.... ie rotating by n positions gives the same array
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        
        /*
        int n = nums.size();
        k = k % n;
        std::rotate(nums.begin(), nums.end() - k, nums.end());  */
    }
};