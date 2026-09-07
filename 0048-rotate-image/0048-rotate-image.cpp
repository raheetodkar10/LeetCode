class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        //1) Transpose karaych
        for(int i=0;i<n;i++){ //n*n matrix ahe so same ch size asnar so <matrix.size()
            for(int j=i;j<n;j++){ //diagonal ghayloy so j=i(diagonal index vr i=j asta)
                swap(matrix[i][j],matrix[j][i]); //jr diagonal vrun swap kel tr easily transpose milto, so
            }
        }
        //2) Row wise reverse karaych
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end()); //this reverses each row of matrix
        }   
    }
};