// 题目描述
// 给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环，所有边权均为正值。
// 请你求出 1 号点到 n 号点的最短距离，如果无法从 1 号点走到 n 号点，则输出 −1。

// 输入格式
// 第一行包含整数 n 和 m。
// 接下来 m 行每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

// 输出格式
// 输出一个整数，表示 1 号点到 n 号点的最短距离。

// 如果路径不存在，则输出 −1。

// 输入输出样例
// 输入
// 3 3
// 1 2 2
// 2 3 1
// 1 3 4

// 输出
// 3
// 说明/提示
// 1≤n≤500
// 1≤m≤10^5
// 图中涉及边长均不超过10000。

#include <iostream>
#include <cstring>

using namespace std;

const int N=510;

int n, m;
// 稠密图
int g[N][N];
// Dijkstra
int dist[N]; // 当前的最短路径
bool st[N]; //表示点的最短路是否已确定

int dijkstra()
{
    // 初始化
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for(int i=0 ; i<n ; i++)
    {
        int t = -1;
        // 找到非st中距离最近的点
        for(int j=1 ; j<=n ; j++)
            if(!st[j] && (t==-1 || dist[t]>dist[j]))
                t = j;
        st[t] = true;
        // 更新
        for(int j=1 ; j<=n ; j++)
            dist[j] = min(dist[j], dist[t]+g[t][j]);
    }

    if(dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];
}

int main()
{
    scanf("%d%d", &n, &m);
    // 初始化
    memset(g, 0x3f, sizeof g);

    while(m--)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        g[x][y] = min(g[x][y], z); // 有重边，保留长度最短的一条
    }

    int ans = dijkstra();

    printf("%d\n", ans);
    return 0;
}

// 500个点 100000条边->稠密图->邻接矩阵