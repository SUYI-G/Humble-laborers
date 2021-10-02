//59.螺旋矩阵II
//给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > resultMatrix(n, vector<int>(n, 0));
        int loop = n / 2;   //转的圈数
        int start_x = 0, start_y = 0, element = 1;
        for (int n_loop = 0;n_loop < loop;n_loop++) {
            start_x = n_loop;
            start_y = n_loop;
            for (int i = 0;i < n - n_loop;i++) {    //从左至右填充上行
                if (element < n * n + 1) {
                    resultMatrix[start_x][start_y + i] = element;
                    element++;
                }
                else {
                    break;
                }
            }
            for (int i = 0;i < n - 1 - n_loop * 2;i++) {    //从上至下填充有=右列
                if (element < n * n + 1) {
                    resultMatrix[start_x + i][n - n_loop - 1] = element;
                    element++;
                }
                else {
                    break;
                }
            }
            for (int i = 0;i < n - n_loop;i++) {    //从右至左填充下行
                if (element < n * n + 1) {
                    resultMatrix[start_x + n - 1 - n_loop * 2][n - n_loop - 1 - i] = element;
                    element++;
                }
                else {
                    break;
                }
            }
            for (int i = 0;i < n - 1 - n_loop * 2;i++) {  //从下至上填充左列
                if (element < n * n + 1) {
                    resultMatrix[start_x + i][start_y] = element;
                    element++;
                }
                else {
                    break;
                }
            }
        }
        return resultMatrix;
    }
};

void main() {
    int n = 3;
    Solution solution;
    vector<vector<int> > resultMatrix = solution.generateMatrix(n);
    for (int i = 0; i != resultMatrix.size();i++)
    {
        for (int j = 0; j != resultMatrix[0].size();j++) {
            cout << resultMatrix[i][j] << " ";
        }
        cout << endl;
    }
}