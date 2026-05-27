// 给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

// 说明：每次只能向下或者向右移动一步。

 

// 示例 1：


// 输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
// 输出：7
// 解释：因为路径 1→3→1→1→1 的总和最小。
// 示例 2：

// 输入：grid = [[1,2,3],[4,5,6]]
// 输出：12
 

// 提示：

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 200
// 0 <= grid[i][j] <= 200


/// 【动态规划】时间复杂度O(MN)。二维
/// 表示：f(i,j)表示从起点走到(i,j)的所有路径的最小数字总和
/// 转换：f(i,j) = min(f(i-1,j), f(i,j-1)) + w(i,j)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int N = 205;
        int f[N][N];
        // init
        memset(f, 0x3f, sizeof f);
        f[1][1] = grid[0][0];

        for(int i=1 ; i<=m ; i++)
            for(int j=1 ; j<=n ; j++)
            {
                if(i == 1 && j == 1)
                    continue;
                f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i-1][j-1];
            }

        return f[m][n];
    }
};


/// 【动态规划】时间复杂度O(MN)。一维，二维转换只依赖当前行的左边和上一行的数据
/// 表示：f(j)表示从起点走到i行的j列的所有路径的最小数字总和
/// 转换：f(j)=min(f(j), f(j-1))+w(i,j)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int N = 205;
        int f[N];
        // init
        memset(f, 0x3f, sizeof f);

        for(int i=1 ; i<=m ; i++)
            for(int j=1 ; j<=n ; j++) // j仍然从小到大，使用的是更新后的j-1值
                if(i == 1 && j == 1)
                    f[j] = grid[0][0];
                else
                    f[j] = min(f[j-1], f[j]) + grid[i-1][j-1];

        return f[n];
    }
};
