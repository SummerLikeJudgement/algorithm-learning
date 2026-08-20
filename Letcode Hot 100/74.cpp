// 给你一个满足下述两条属性的 m x n 整数矩阵：

// 每行中的整数从左到右按非严格递增顺序排列。
// 每行的第一个整数大于前一行的最后一个整数。
// 给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。

// 你必须编写一个时间复杂度为 O(log(m * n)) 的解决方案。

 

// 示例 1：


// 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// 输出：true
// 示例 2：


// 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// 输出：false
 

// 提示：

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 100
// -104 <= matrix[i][j], target <= 104


/// 【整数二分】先对每行的首元素进行二分，找到第一个小于等于target，再在该行中进行二分。或者将整个数组拉平为一维，然后整个二分。
class Solution {
public:
    int search(vector<int>& q, int t)
    {
        int l = 0;
        int r = q.size()-1;
        while(l < r)
        {
            int mid = (l + r + 1) >> 1;
            if(q[mid] <= t)
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        vector<int> col;
        for(int i=0 ; i<m ; i++)
            col.push_back(matrix[i][0]);
        int x = search(col, target);
        int y = search(matrix[x], target);
        if(matrix[x][y] == target)
            return true;
        else
            return false;
    }
};