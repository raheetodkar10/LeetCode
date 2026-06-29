class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        // int row=mat.size();
        // int col=mat[0].size();
        int n=mat.size();
        for(int i=0;i<n;i++){
            sum += mat[i][i];  //left to right diagonal
        }
        for(int i=0;i<n;i++){
            sum += mat[i][n-i-1];  //right to left diagonal
            //n=4,i=0 -> 3 (arr cha col value)
            //n=4,i=1 -> 2
            //n=4,i=2 -> 1
            //n=4,i=3 -> 0  hence (n-i-1) formula is created
        }
        //to remove duplicate values (5 in given ex)
        //n chi value jevha even aste tevha duplicate values create hot nai. but it happens with odd n value
        if(n&1){
            sum -= mat[n/2][n/2];   //duplicate values remove karaychya, n/2 mhanje middle element that gives duplicate value
        }
        return sum;
        
    }
};