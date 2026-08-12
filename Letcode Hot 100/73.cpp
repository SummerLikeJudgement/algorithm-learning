// 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。

 

// 示例 1：


// 输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
// 输出：[[1,0,1],[0,0,0],[1,0,1]]
// 示例 2：


// 输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// 输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

// 提示：

// m == matrix.length
// n == matrix[0].length
// 1 <= m, n <= 200
// -231 <= matrix[i][j] <= 231 - 1
 

// 进阶：

// 一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
// 一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
// 你能想出一个仅使用常量空间的解决方案吗？


/// 【模拟】用两个标记数组分别记录每一行和每一列是否有零出现。
const int N = 200;

class Solution {
public:
    bool col[N];// 记录列的情况
    bool row[N];// 记录行的情况
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=0 ; i<m ; i++)
            for(int j=0 ; j<n ; j++)
            {
                if(matrix[i][j] != 0)
                    continue;
                row[i] = true;
                col[j] = true;
            }
        // row
        for(int i=0 ; i<m ; i++)
            if(row[i])
                for(int k=0 ; k<n ; k++)
                    matrix[i][k] = 0;
        // col
        for(int i=0 ; i<n ; i++)
            if(col[i])
                for(int k=0 ; k<m ; k++)
                    matrix[k][i] = 0;

        return;
    }
};


/// 【模拟】优化额外空间。用矩阵的第一行和第一列代替方法一中的两个标记数组，并且使用两个标记变量分别记录第一行和第一列是否原本包含 0。
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int flag_col0 = false, flag_row0 = false;
        for (int i = 0; i < m; i++) {
            if (!matrix[i][0]) {
                flag_col0 = true;
            }
        }
        for (int j = 0; j < n; j++) {
            if (!matrix[0][j]) {
                flag_row0 = true;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (!matrix[i][j]) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (flag_col0) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
        if (flag_row0) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};