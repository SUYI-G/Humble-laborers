class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int k = 1;
        for (int i = 0; i < n / 2; i++){
            //从左向右的部分
            for (int j = i; j < n - 1 - i; j++){ //j = 0 ,1
                res[i][j] = k;
                k++;
            }
            //从上到下的部分
            for (int j = i; j < n - 1 - i; j++){ //j = 0, 1
                res[j][n - 1 - i] = k;
                k++;
            }

            //从左到右的部分
            for (int j = n - i - 1; j > i; j--){ //j = 2, 1
                res[n - i - 1][j] = k;
                k++;
            }
            //从下到上的部分
            for (int j = n - i - 1; j > i; j--){ //j = 2, 1
                res[j][i] = k;
                k++;
            }
        }
        if (res[n / 2 ][n / 2 ] == 0) res[n / 2 ][n / 2] = k;
        return res;

    }
};