// # P1434 [SHOI2002] 滑雪

// ## 题目描述

// Michael 喜欢滑雪。这并不奇怪，因为滑雪的确很刺激。可是为了获得速度，滑的区域必须向下倾斜，而且当你滑到坡底，你不得不再次走上坡或者等待升降机来载你。Michael 想知道在一个区域中最长的滑坡。区域由一个二维数组给出。数组的每个数字代表点的高度。下面是一个例子：
// ```plain
// 1   2   3   4   5
// 16  17  18  19  6
// 15  24  25  20  7
// 14  23  22  21  8
// 13  12  11  10  9
// ```
// 一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度会减小。在上面的例子中，一条可行的滑坡为 $24-17-16-1$（从 $24$ 开始，在 $1$ 结束）。当然    $25$－$24$－$23$－$\ldots$－$3$－$2$－$1$ 更长。事实上，这是最长的一条。

// ## 输入格式

// 输入的第一行为表示区域的二维数组的行数 $R$ 和列数 $C$。下面是 $R$ 行，每行有 $C$ 个数，代表高度（两个数字之间用 $1$ 个空格间隔）。

// ## 输出格式

// 输出区域中最长滑坡的长度。

// ## 输入输出样例 #1

// ### 输入 #1

// ```
// 5 5
// 1 2 3 4 5
// 16 17 18 19 6
// 15 24 25 20 7
// 14 23 22 21 8
// 13 12 11 10 9

// ```

// ### 输出 #1

// ```
// 25
// ```

// ## 说明/提示

// 对于 $100\%$ 的数据，$1\leq R,C\leq 100$。

// #include <iostream>
// #include <cstring>

// using namespace std;

// const int N = 105;

// int g[N][N];
// int f[N][N]; // 确定的以(x,y)为终点的最长长度
// int R, C;
// // 移动方向
// int dx[4] = {1, -1, 0, 0};
// int dy[4] = {0, 0, 1, -1};

// // (x,y)处的dfs/以(x,y)为终点的最长长度
// int dfs(int x, int y)
// {
//     if(f[x][y] != -1)
//         return f[x][y];
//     int ans = 0;
//     for(int i=0 ; i<4 ; i++)
//     {
//         int tx = x + dx[i];
//         int ty = y + dy[i];
//         if(tx>=1 && tx<=R && ty>=1 && ty<=C)
//             if(g[tx][ty] > g[x][y])
//                 ans = max(ans, dfs(tx, ty));
//     }
//     f[x][y] = ans+1;
//     return f[x][y];
// }

// int main()
// {
//     // 初始化
//     memset(f, -1 ,sizeof f);

//     scanf("%d%d", &R, &C);
//     for(int i=1 ; i<=R ; i++)
//         for(int j=1 ; j<=C ; j++)
//             scanf("%d", &g[i][j]);

//     int ans = 0;

//     for(int i=1 ; i<=R ; i++)
//         for(int j=1 ; j<=C ; j++)
//             ans = max(ans, dfs(i, j));

//     printf("%d", ans);

//     return 0;
// }
/// 【dfs】遍历所有格子做终点，dfs找到每个格子的最长长度
/// 优化：单个dfs结束后，该点的最长长度已经确定，可使用数组记录下来，不用重复计算了

#include <bits/stdc++.h>

using namespace std;
const int N = 310;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int g[N][N]; // 邻接矩阵,地图
int f[N][N]; // 记录从i到j的最大距离
int n, m;    // 行与列
int res;     // 结果

// 记忆化搜索
int dfs(int x, int y) {
    if (~f[x][y]) return f[x][y];
    // 求最长的轨迹，最起码是1
    f[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int tx = x + dx[i], ty = y + dy[i];
        if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
        if (g[x][y] > g[tx][ty])
            f[x][y] = max(f[x][y], dfs(tx, ty) + 1);
    }
    return f[x][y];
}

int main() {
    cin >> n >> m; // n行 m列
    // 读入每一个点的高度
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];
    // 初始化-1
    memset(f, -1, sizeof f);

    // 从每一个点出发
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            res = max(res, dfs(i, j));
    // 输出结果
    printf("%d\n", res);
    return 0;
}



/// 【记忆化搜索dp】类似于上面的dfs
/// 状态表示f[i][j]:(i,j)作为起始点的路径最长长度
/// 状态转移:f[i][j] = max(f[i-1][j], f[i+1][j], f[i][j+1], f[i][j-1]) + 1