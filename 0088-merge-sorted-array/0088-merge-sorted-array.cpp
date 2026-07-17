class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>ans;
        int i=0;  //for nums1
        int j=0;  //for nums2
        while(i<m && j<n){   //jo paryant valid indexes ahet
            if(nums1[i]<nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else{
                ans.push_back(nums2[j]);  //jr j wali value choti asel
                j++;
            }
        }
        //asa pn hou shakta ki eka array mde elements ch rahile nastil compare karayla, pn dusrya array mde elements rahile astil. so, copy
        while(i<m){
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<n){
            ans.push_back(nums2[j]);  
            j++;
        }
        nums1=ans; //copies every element of ans into nums1, it checks nums1, not ans, so answer is considered wrong if we dont write this statement
    }
};