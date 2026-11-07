class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {  //TC & SC: O(n)
        int n = nums.size();
        vector<bool> seen(n+1, false);  //seen wala hashmap 1 extra size ne asava to store that missing one
        /*If an array has 4 elements, the first missing positive number must be between 1 and 4, or it must be 5. Cause if all numbers from 1 to 4 are present, then the next missing number is */

        for(int num : nums){
            if(num > 0 && num <= n){
                seen[num] = true;    //jas jas elem miltil, we'll be marking true in seen map
            }
        }

        for(int i=1;i<=n;i++){   //ans 1 to n ya mdhech asnar
            if(!seen[i]){
                return i;   //As soon as we find false, we return that number
            }
        }
        return n + 1;
        /*Ex: nums = [1, 2, 3, 4]   All positive numbers from 1 to 4 are present. So the first missing positive number is 5.  Since n = 4:  n + 1 = 5  That's why we return n+1 */
    }
};

/* Ex: 3,4,-1,-2,1,8    n=6
arr:   | | True | | True | True | | |
index:  0    1   2    3     4    5 6    
by return i, 2 will be returned */