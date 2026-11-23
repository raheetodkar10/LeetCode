class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {//TC:O(N+M), SC:O(1)
        //stones mde kiti jewels ahet ki baghaychay
        //step 1-> store jewels char. step 2->stones che char check, step 3->count
        //boolean arr approach
        vector<int> isJewels(128,0);   //Since characters have ASCII values ranging from 0 to 127 (for standard ASCII), create an array/vector of size 128. te nasel tr runtime err
        for(char ch : jewels){
            isJewels[ch] = true;
        }
        //check stones and count
        int count = 0;
        for(char ch : stones){
            if(isJewels[ch]){
                count++;
            }
        }
        return count;
    }
};