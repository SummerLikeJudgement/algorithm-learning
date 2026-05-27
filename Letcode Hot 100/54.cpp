// 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

 

// 示例 1：


// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：[1,2,3,6,9,8,7,4,5]
// 示例 2：


// 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 

// 提示：

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100


/// 【模拟】按圈模拟
/// 将矩阵看作若干圈，从外到内输出元素
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        
        int i = 0, j = 0;

        while(m>1 && n>1)
        {
            ans.push_back(matrix[i][j]);
            for(int k=0 ; k<n-1 ; k++)
            {
                j++;
                ans.push_back(matrix[i][j]);
            }
            for(int k=0 ; k<m-1 ; k++)
            {
                i++;
                ans.push_back(matrix[i][j]);
            }
            for(int k=0 ; k<n-1 ; k++)
            {
                j--;
                ans.push_back(matrix[i][j]);
            }
            for(int k=0 ; k<m-2 ; k++)
            {
                i--;
                ans.push_back(matrix[i][j]);
            }
            j++;
            m -= 2;
            n -= 2;
        }
        if(m == 0 || n==0)
            return ans;
        if(m == 1)
        {
            ans.push_back(matrix[i][j]);
            for(int k=0 ; k<n-1 ; k++)
            {
                j++;
                ans.push_back(matrix[i][j]);
            }
        }
        else if(n == 1)
        {
            ans.push_back(matrix[i][j]);
            for(int k=0 ; k<m-1 ; k++)
            {
                i++;
                ans.push_back(matrix[i][j]);
            }
        }
        

        return ans;
    }
};

/// 【模拟】层模拟
/// 遍历完一层后直接缩小矩阵边界
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> ans;
        if(matrix.empty()) return ans; //若数组为空，直接返回答案
        int u = 0; //赋值上下左右边界
        int d = matrix.size() - 1;
        int l = 0;
        int r = matrix[0].size() - 1;
        while(true)
        {
            for(int i = l; i <= r; ++i) ans.push_back(matrix[u][i]); //向右移动直到最右
            if(++ u > d) break; //重新设定上边界，若上边界大于下边界，则遍历遍历完成，下同
            for(int i = u; i <= d; ++i) ans.push_back(matrix[i][r]); //向下
            if(-- r < l) break; //重新设定有边界
            for(int i = r; i >= l; --i) ans.push_back(matrix[d][i]); //向左
            if(-- d < u) break; //重新设定下边界
            for(int i = d; i >= u; --i) ans.push_back(matrix[i][l]); //向上
            if(++ l > r) break; //重新设定左边界
        }
        return ans;
    }
};