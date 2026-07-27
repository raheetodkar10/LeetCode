class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod=1;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                prod=(nums[i]-1)*(nums[j]-1);
                maxi=max(maxi,prod);
            }
        }
        return maxi;
        
    }
};