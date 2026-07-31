// 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

// 问总共有多少条不同的路径？

 

// 示例 1：


// 输入：m = 3, n = 7
// 输出：28
// 示例 2：

// 输入：m = 3, n = 2
// 输出：3
// 解释：
// 从左上角开始，总共有 3 条路径可以到达右下角。
// 1. 向右 -> 向下 -> 向下
// 2. 向下 -> 向下 -> 向右
// 3. 向下 -> 向右 -> 向下
// 示例 3：

// 输入：m = 7, n = 3
// 输出：28
// 示例 4：

// 输入：m = 3, n = 3
// 输出：6
 

// 提示：

// 1 <= m, n <= 100
// 题目数据保证答案小于等于 2 * 109


/// 【数学】
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 && n==1)
            return 1;
        long long ans = 1;
        for(int i=n, j=1 ; i<=m+n-2 ; i++, j++)
            ans = ans * i / j;
        return ans;
    }
};


/// 【动态规划】
class Solution {
public:
    int f[105][105];
    int uniquePaths(int m, int n) {
        // if(m==1 && n==1)
        //     return 1;
        //init
        for(int i=0 ; i<=m-1 ; i++)
            f[i][0] = 1;
        for(int i=0 ; i<=n-1 ; i++)
            f[0][i] = 1;
        // f[0][0] = 0;

        for(int i=1 ; i<=m-1 ; i++)
            for(int j=1 ; j<=n-1 ; j++)
            {
                if(i-1 >= 0)
                    f[i][j] += f[i-1][j];
                if(j-1 >= 0)
                    f[i][j] += f[i][j-1];
            }
        return f[m-1][n-1];

    }
};
/// 优化后
class Solution {
public:
    int f[105];
    int uniquePaths(int m, int n) {
        //init
        for(int i=0 ; i<=n-1 ; i++)
            f[i] = 1;

        for(int i=1 ; i<=m-1 ; i++)
            for(int j=1 ; j<=n-1 ; j++)
                if(j-1 >= 0)
                    f[j] += f[j-1];
        return f[n-1];

    }
};