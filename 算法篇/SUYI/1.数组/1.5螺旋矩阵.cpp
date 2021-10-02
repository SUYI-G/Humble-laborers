//59.��������II
//����һ�������� n ������һ������ 1 �� n2 ����Ԫ�أ���Ԫ�ذ�˳ʱ��˳���������е� n x n �����ξ��� matrix ��

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > resultMatrix(n, vector<int>(n, 0));
        int loop = n / 2;   //ת��Ȧ��
        int start_x = 0, start_y = 0, element = 1;
        for (int n_loop = 0;n_loop < loop;n_loop++) {
            start_x = n_loop;
            start_y = n_loop;
            for (int i = 0;i < n - n_loop;i++) {    //���������������
                if (element < n * n + 1) {
                    resultMatrix[start_x][start_y + i] = element;
                    element++;
                }
                else {
                    break;
                }
            }
            for (int i = 0;i < n - 1 - n_loop * 2;i++) {    //�������������=����
                if (element < n * n + 1) {
                    resultMatrix[start_x + i][n - n_loop - 1] = element;
                    element++;
                }
                else {
                    break;
                }
            }
            for (int i = 0;i < n - n_loop;i++) {    //���������������
                if (element < n * n + 1) {
                    resultMatrix[start_x + n - 1 - n_loop * 2][n - n_loop - 1 - i] = element;
                    element++;
                }
                else {
                    break;
                }
            }
            for (int i = 0;i < n - 1 - n_loop * 2;i++) {  //���������������
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