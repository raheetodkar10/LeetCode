class Solution {
public:
    int minimumRecolors(string blocks, int k) {  //TC:O(N), SC:O(1)
        //window size is fixed-> Fixed size sliding window: window fixed thevnar, fakt ek elem add karnar ani ek minus
        int count = 0;
        for(int i=0;i<k;i++){
            if(blocks[i] == 'W'){
                count++;
            }
        }
        int minCount = count;
        for(int i=k;i<blocks.size();i++){
            if(blocks[i-k] == 'W') count--;  //access the char jo window se bahar ja raha hei
            if(blocks[i] == 'W') count++;    //access new char jo window me enter ho raha hei
            minCount = min(minCount, count);
        }
        return minCount;
    }
};
/*pseudo:
1. Count W in first k blocks
2. Slide: out W->-1, in W->+1
3. Update minCount every window
Return minCount   */