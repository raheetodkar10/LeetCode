class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for(int i=0;i<nums.size();i++){
            if(i > maxReach){
                return false;
            }
            maxReach = max(maxReach, i+nums[i]);
        }
        return true;
    }
};
/* ex: 2,3,1,1,4
max=0  i=0
max=max(0,0+2)=2
i=1
max=max(2,1+3)=4
last index is reachable
same for i=2,3,4  */