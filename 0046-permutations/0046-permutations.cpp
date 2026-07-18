class Solution {
public:
    //By Recursion
    vector<vector<int>>ans;
    void solve(vector<int>&nums,int i){
        //base case
        if(i>=nums.size()){    //i becomes out of bounds
            ans.push_back(nums);  //ya case mde ji string yeil, that will be a permutation. so store it
            return;
        }
        //1 case
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            solve(nums,i+1);
            swap(nums[i],nums[j]);  //**Backtrack (as string is passed by reference)
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums,0);   //0 is i starting value
        return ans;
    }
};