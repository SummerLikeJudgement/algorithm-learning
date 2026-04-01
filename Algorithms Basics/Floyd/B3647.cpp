// 洛谷中类似acwing 854的Floyd模板题：https://www.luogu.com.cn/problem/B3647

// ## 题目描述

// 给出一张由 $n$ 个点 $m$ 条边组成的无向连通图。

// 求出所有点对 $(i,j)$ 之间的最短路径。

// ## 输入格式

// 第一行为两个整数 $n,m$，分别代表点的个数和边的条数。

// 接下来 $m$ 行，每行三个整数 $u,v,w$，代表 $u,v$ 之间存在一条边权为 $w$ 的边。

// ## 输出格式

// 输出 $n$ 行每行 $n$ 个整数。

// 第 $i$ 行的第 $j$ 个整数代表从 $i$ 到 $j$ 的最短路径。

// ## 输入输出样例 #1

// ### 输入 #1

// ```
// 4 4
// 1 2 1
// 2 3 1
// 3 4 1
// 4 1 1
// ```

// ### 输出 #1

// ```
// 0 1 2 1
// 1 0 1 2
// 2 1 0 1
// 1 2 1 0
// ```

// ## 说明/提示

// 对于 $100\%$ 的数据，$n \le 100$，$m \le 4500$，任意一条边的权值 $w$ 是正整数且 $1 \leqslant w \leqslant 1000$。

// **数据中可能存在重边。**

#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;
const int INF = 1e9;

int n, m;
// 稠密图，用邻接矩阵存
int d[N][N];

void Floyd()
{
    for(int k=1 ; k<=n ; k++)
        for(int i=1 ; i<=n ; i++)
            for(int j=1 ; j<=n ; j++)
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
}

int main()
{
    scanf("%d%d", &n, &m);
    // 初始化
    for(int i=0 ; i<N ; i++)
        for(int j=0 ; j<N ; j++)
        {
            if(i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }

    while(m--)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        // 读入无向边
        d[x][y] = min(d[x][y], z); // 有重边，只存最小的即可
        d[y][x] = min(d[y][x], z);
    }

    Floyd();

    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=n ; j++)
            printf("%d ", d[i][j]);
        printf("\n");
    }

    return 0;
}