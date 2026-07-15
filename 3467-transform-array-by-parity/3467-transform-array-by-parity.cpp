class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                ans.push_back(0);
            }
            else{
                ans.push_back(1);
            }
        } 
        sort(ans.begin(),ans.end());
        return ans;
    }
};
/*Another approach: time complexity:O(n)
vector<int>ans;
        int odd=0;
        int even=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                even++;
            }
            else{
                odd++;
            }
        }
        while(even--) {    //post decrement operator. It means : use current value first , then decrease by 1
            ans.push_back(0);
        }
        while(odd--){
            ans.push_back(1);
        }
        return ans;
*/