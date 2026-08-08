class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    bool found=false;        //ans mde elements repeat hou naye so apn he lihila
                    for(int x:ans){
                        if(x==nums1[i]){
                            found=true;
                            //break;              //till this
                        }
                    } 
                    if(!found){
                        ans.push_back(nums1[i]);
                    }
                }
            }
        }
        
        return ans;
        
    }
};