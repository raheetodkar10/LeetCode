class Solution {
public:
    //Recursion approach
    int recursiveBS(vector<int>& nums,int s,int e,int target){
        //base case
        if(s > e) return -1;
        //1 case
        int mid = s + (e-s) / 2;
        if(nums[mid]==target) {
            return mid;
        }
        //rest, recursion will handle
        if(nums[mid] > target){
            //left
            int recAns=recursiveBS(nums,s,mid-1,target);
            return recAns;
        }
        else{
            //right
            int recAns=recursiveBS(nums,mid+1,e,target);
            return recAns;
        }
    };
    int search(vector<int>& nums, int target){
        int s=0;
        int e=nums.size()-1;
        int ans=recursiveBS(nums,s,e,target);
        return ans;    
    }
};
/*int n = nums.size();
        int s = 0;
        int e = n - 1;
        while ( s <= e){
            int mid = s + (e-s) / 2;
            if (nums[mid] == target){
                return mid;
            }
            if ( nums[mid] < target){
                s = mid + 1;
            }
            else{
                e = mid-1;
            }
        }
        return -1;  */