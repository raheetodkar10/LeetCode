class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {   //TC:O(n) 
        deque<int> dq;
        vector<int> ans;

        //process 1st window
        //addition (imp step)
        for(int index=0;index<k;index++){
            //curr elem ke index ko store krna padega, but isko insert krne se pehele agar koi iske left me chota elem already insert ho chuke he to muze vo remove krne padenge as those element cannot be the ans or cannot be in the front as curr elem is larger
            while(!dq.empty() && nums[dq.back()] < nums[index]){    //dq.back() shows left elem ka index so nums[dq.back()] shows value on left side index & arr[index] is curr value
                dq.pop_back();
            }
            //insert to krna hi he
            dq.push_back(index);
        }
        //ans
        int elem = nums[dq.front()];  //dq.front() index asnar
        ans.push_back(elem);
        
        //remaining window
        for(int index=k;index<nums.size();index++){
            //removal
            if(!dq.empty() && index-dq.front() >= k){  //index-dq.front() >= k chya aivaji dq.front()<=index-k  pn use kru shakto (shown this formula in 1st neg int Q)
                dq.pop_front();
            }
            //addition
            while(!dq.empty() && nums[dq.back()] < nums[index]){    //dq.back() shows left elem ka index so nums[dq.back()] shows value on left side index & arr[index] is curr value
                dq.pop_back();
            }
            //insert to krna hi he
            dq.push_back(index);
            //ans
            int elem = nums[dq.front()];  //dq.front() index asnar
            ans.push_back(elem);
        }
        return ans;
    }
};