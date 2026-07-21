class Solution {
public:
    void quicksort(vector<int>& nums, int s, int e){
        //Quick sort
        if(s>=e){
            return;   //base case
        } 
        int mid = s + (e - s) / 2;
        swap(nums[mid], nums[e]);
        int pivot=e;
        int i=s-1;
        //int j=s;
        for(int j=s;j<pivot;j++){
            if(nums[j]<nums[pivot]){
                i++;
                swap(nums[i],nums[j]);
            }
            //j++;
        }
        i++;
        swap(nums[i],nums[pivot]);
        //Recursive calls
        quicksort(nums,s,i-1);
        quicksort(nums,i+1,e);
    }
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums,0,nums.size()-1);
        return nums;
    }
};
// int n=nums.size();
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n-i-1;j++){
//                 if(nums[j]>nums[j+1]){
//                     swap(nums[j],nums[j+1]);
//                 }
//             }
//         }   
//         return nums;