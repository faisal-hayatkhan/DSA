class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int total=0;
        for(int i=0; i<n; i++){
            total+=mat[i][i];
            total+=mat[i][n-1-i];
        }
        if(n%2!=0){
            int idx=n/2;
            total-=mat[idx][idx];
        }
        return total;
    }
};