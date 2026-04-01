// 题目描述
// 给定一个n个点m条边的有向图，图中可能存在重边和自环， 边权可能为负数。
// 请你求出从1号点到n号点的最多经过k条边的最短距离，如果无法从1号点走到n号点，输出impossible。
// 注意：图中可能存在负权回路 。

// 输入格式
// 第一行包含三个整数n，m，k。
// 接下来m行，每行包含三个整数x，y，z，表示存在一条从点x到点y的有向边，边长为z。

// 输出格式
// 输出一个整数，表示从1号点到n号点的最多经过k条边的最短距离。
// 如果不存在满足条件的路径，则输出impossible。

// 输入输出样例
// 输入
// 3 3 1
// 1 2 1
// 2 3 1
// 1 3 3

// 输出
// 3

// 说明/提示
// 1≤n,k≤500,
// 1≤m≤10000,
// 任意边长的绝对值不超过10000。

#include <iostream>
#include <cstring>

using namespace std;

const int M = 10010;
const int N = 510;
//存a->b权重是w的边
struct Edge{
    int a,b,w;
}edges[M];//结构体数组，存储边

int n, m, k;
// 每个点的目前最短距离
int dist[N];
// 每次循环前备份dist，避免发生串联（遍历所有边时只使用上次迭代的结果，而不使用临时更新的结果）
int backup[N];

void bellman_ford()
{
    //初始化
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for(int i=0 ; i<k ; i++) // 迭代了k次，代表找到了从源点经过不超过k条边走到n号点的最短距离
    {
        memcpy(backup, dist, sizeof dist);
        for(int j=0 ; j<m ; j++)
        {
            auto e = edges[j];
            dist[e.b] = min(dist[e.b], backup[e.a]+e.w);
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for(int i=0 ; i<m ; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        edges[i] = {x, y, z};
    }

    bellman_ford();

    if(dist[n] > 0x3f3f3f3f / 2) // 在循环过程中可能会更新一点，所以大于INF/2
        printf("impossible");
    else
        printf("%d", dist[n]);

    return 0;
}