class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int r=matrix.size()-1;
        int c=0;
        while (r>=0&&c<matrix[0].size()){
            if(matrix[r][c]==target) return true;
            else if(matrix[r][c]>target) r--;
            else c++;
        }
        return false;
    }
};
