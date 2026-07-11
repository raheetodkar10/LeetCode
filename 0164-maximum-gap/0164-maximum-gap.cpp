class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return 0;
        sort(nums.begin(),nums.end());
        int maxi=0;
        for(int i=1;i<n;i++){
            int diff=nums[i]-nums[i-1];
            maxi=max(maxi,diff);
        }
        return maxi;
    }
};