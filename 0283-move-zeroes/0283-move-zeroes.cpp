class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        //sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i] != 0){
                swap(nums[i],nums[j]);
                j++;
            }
        }    
    }
};
/* 1st ieration:   j=0 -> nums[i]=0 
2nd ieration:   j=0 -> nums[i]=1 -> swap(1,0) ->j++ -> O/P: 1,0
3rd ieration:   j=1 -> nums[i]=0
4th ieration:   j=1 -> nums[i]=3 ->swap(3,1) ->j++ -> O/P: 1,3,0  ans so on */