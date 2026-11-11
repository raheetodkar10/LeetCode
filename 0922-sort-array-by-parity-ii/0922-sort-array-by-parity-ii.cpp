class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {   //TC:O(N), SC:O(1)
        //2 pointers, one for even idx one for odd idx
        int even = 0, odd = 1;
        int n = nums.size();
        while(even < n && odd < n){
            if(nums[even] % 2 == 0){   //jr even idx vr even no. asel tr fakt pointer increase karaycha
                even += 2;
            }
            else if(nums[odd] % 2 == 1){    //jr odd idx vr even no. asel tr fakt pointer increase karaycha
                odd += 2;
            }
            else{
                //swap
                int temp = nums[even];
                nums[even] = nums[odd];
                nums[odd] = temp;
                //mg pointer increase karaycha
                even += 2;
                odd += 2;
            }
        }
        return nums;
    }
};