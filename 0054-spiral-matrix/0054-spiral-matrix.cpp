class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int top = 0, bottom = row - 1;  //top->varchi row, bottom-> khalchi row
        int left = 0, right = col - 1;  //right is column index(right col), left is row index(left col)

        vector<int> ans;   //jyat apn final matrix store karnar

        while(left <= right && top <= bottom){  //joparaynt matrix mde elements ahet toparyant loop chalnar
            for(int i = left ; i <= right ; i++){   // left->right
                ans.push_back(matrix[top][i]);   //fix row->top
            }
            top++;  //next row
            for(int j = top ; j <= bottom ; j++){   // top->bottom
                ans.push_back(matrix[j][right]);  //adhi row index yenar mg col index, so [j][right], right col->fix
            }
            right--; //left shift
            if(top <= bottom){   //to avoid duplicate values
                for(int i = right ; i >= left ; i--){   // (matrix ch bottom) right->left
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if(left <= right){   //parat left->right
                for(int j = bottom ; j >= top ; j--){
                    ans.push_back(matrix[j][left]);   //adhi row index yenar mg col index, so [j][left]
                }
                left++;
            }
        }
        return ans;
        
    }
};