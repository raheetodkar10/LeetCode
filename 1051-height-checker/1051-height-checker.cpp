class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;   //copy all elements of heights in expected
        sort(expected.begin(),expected.end());
        int count=0;
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=expected[i]){
                count++;
            }
        }
        return count;
        
    }
};
/* Asa pn lihu shakto:
    vector<int> expected;
    expected = heights;
    sort(expected.begin(),expected.end());  */