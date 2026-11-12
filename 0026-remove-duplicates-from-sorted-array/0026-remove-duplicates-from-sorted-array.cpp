class Solution {
public:
    int removeDuplicates(vector<int>& nums) {   //TC:O(N), SC:O(1)
        //ex: [1,1,2,2,3] -> [1,2,3]   (no extra arr)
        //two pointers: 1st pointer tracks unique elem, 2nd will scan the arr
        //unique->add, duplicate->ignore
        int unique = 0;
        for(int scan=1;scan<nums.size();scan++){
            if(nums[scan] != nums[unique]){
                unique++;
                nums[unique] = nums[scan];   //Move unique one position forward & Copy the new unique element into that position
            }
        }
        return unique + 1;   //array indexing starts from 0. Our unique elements are: 0,1,2.  Last unique index = 2.  But total unique elements = 3
    }
};