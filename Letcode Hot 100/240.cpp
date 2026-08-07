// 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：

// 每行的元素从左到右升序排列。
// 每列的元素从上到下升序排列。
 

// 示例 1：


// 输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
// 输出：true
// 示例 2：


// 输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
// 输出：false
 

// 提示：

// m == matrix.length
// n == matrix[i].length
// 1 <= n, m <= 300
// -109 <= matrix[i][j] <= 109
// 每行的所有元素从左到右升序排列
// 每列的所有元素从上到下升序排列
// -109 <= target <= 109


/// 【贪心】将矩阵逆时针旋转90度，其类似于搜索二叉树，因此从根节点开始搜索，若当前节点值大于目标值，则向左走，否则向下走，直到找到目标值或者越界为止。
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int i = 0;
        int j = n-1;
        while(matrix[i][j] != target)
        {
            if(matrix[i][j] > target)
                j--;
            else if(matrix[i][j] < target)
                i++;
            if(i>m-1 || j<0)
                break;
        }
        return i<=m-1 && j>=0 && matrix[i][j] == target;
    }
};


/// 【整数二分】每行都是升序的，所以可对每行使用一次二分查找
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (const auto& row: matrix) {
            auto it = lower_bound(row.begin(), row.end(), target);
            if (it != row.end() && *it == target) {
                return true;
            }
        }
        return false;
    }
};