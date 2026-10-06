class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //min heap
        priority_queue<int,vector<int>,greater<int> > pq;  //vector<int>: underlying container used by the priority queue. greater<int>: tells priority queue: Give higher priority to smaller elem
        //initial state
        for(int i=0;i<k;i++){
            pq.push(nums[i]);
        }
        //main logic-> bade elem pr dependant
        for(int i=k;i<nums.size();i++){
            if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        int ans = pq.top();
        return ans;
    }
};