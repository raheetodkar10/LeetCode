class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n1=nums[0];
        int n2=nums[nums.size()-1];
        int ans=gcd(n1,n2);
        return ans;
    }
};

/* App 1:
sort(nums.begin(),nums.end());
return gcd(nums[0],nums[nums.size()-1]);

App2:
int maxi=INT_MIN;
int mini=INT_MAX;
for(int x:nums){
    maxi=max(maxi,x);
    mini=min(mini,x);
}   
return gcd(maxi,mini);

App3:
int maxi=INT_MIN;
int mini=INT_MAX;
for(int x:nums){
    maxi=max(maxi,x);
    mini=min(mini,x);
}
return gcd(maxi,mini);
*/