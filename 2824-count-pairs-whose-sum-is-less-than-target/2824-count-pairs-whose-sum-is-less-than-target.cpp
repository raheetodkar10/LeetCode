class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int s=0,e=nums.size()-1;
        int cnt=0;
        while(s<e){
            if(nums[s]+nums[e]<target){
                cnt += (e-s); //e to s madhle sagle pairs count honar as nums[s]+nums[e] < target
                s++;   //to move to next element
            }
            else{
                e--;  //to reduce sum
            }
        }
        return cnt;
    }
};
/* Another approach:
        int n=nums.size();
        int count=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]<target){
                    count++;
                }
            }
        }
        return count;
This also works but for small values*/