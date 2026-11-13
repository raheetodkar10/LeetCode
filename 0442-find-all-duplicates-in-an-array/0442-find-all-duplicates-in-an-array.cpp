class Solution {
public:   //Infosys, Capgemini, TCS, Wipro
    vector<int> findDuplicates(vector<int>& nums) {
        int idx;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            idx = abs(nums[i]) - 1;
            if(nums[idx] < 0){
                ans.push_back(idx + 1);  //index starts from 0
            }
            else{
                //mark as visited
                nums[idx] = -nums[idx];
            }
        } 
        return ans;
    }
};
/* ex: 2,1,3,6,3,1,2
after: -2,-1,-3,6,3,-1,2
ans: 3,1,2  */