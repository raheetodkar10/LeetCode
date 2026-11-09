class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {  //TC:O(n), SC:O(1)
        //negative marking technique
        //no. 1->index=0, no. 2->index=1, no. 3->index=2,...  so index = no.-1
        vector<int> ans;
        for(int i=0;i<nums.size();i++){  //for marking neg
            int idx = abs(nums[i]) - 1;
            if(nums[idx] > 0){
                nums[idx] = -nums[idx];
            }
        }

        for(int i=0;i<nums.size();i++){   //for collecting pos
            if(nums[i] > 0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
/* ex: 4,3,2,-7,8,2,3,1   n=8 so nos. must be 1 to 8
nums[0]=4 so 4-1=3 index vr jaych and make nums[3] negative
arr: 4,3,2,-7,8,2,3,1 , val 7 made neg but marking is done of no. 4. so no. 4 found in arr
same, nums[1]=3 so 3-1=2 index vr jaych nd make nums[2] neg
arr:4,3,-2,-7,8,2,3,1 . similarly, process all values
so, je elem neg that will be found and pos will be missing
2nd loop to find pos no.  */