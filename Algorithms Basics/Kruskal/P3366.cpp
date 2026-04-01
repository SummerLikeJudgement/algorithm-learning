// 洛谷类似求最小生成树的模板题：https://www.luogu.com.cn/problem/P3366

// # P3366 【模板】最小生成树

// ## 题目描述

// 如题，给出一个无向图，求出最小生成树，如果该图不连通，则输出 `orz`。

// ## 输入格式

// 第一行包含两个整数 $N,M$，表示该图共有 $N$ 个结点和 $M$ 条无向边。

// 接下来 $M$ 行每行包含三个整数 $X_i,Y_i,Z_i$，表示有一条长度为 $Z_i$ 的无向边连接结点 $X_i,Y_i$。

// ## 输出格式

// 如果该图连通，则输出一个整数表示最小生成树的各边的长度之和。如果该图不连通则输出 `orz`。

// ## 输入输出样例 #1

// ### 输入 #1

// ```
// 4 5
// 1 2 2
// 1 3 2
// 1 4 3
// 2 3 4
// 3 4 3
// ```

// ### 输出 #1

// ```
// 7
// ```

// ## 说明/提示

// 数据规模：

// 对于 $20\%$ 的数据，$N\le 5$，$M\le 20$。

// 对于 $40\%$ 的数据，$N\le 50$，$M\le 2500$。

// 对于 $70\%$ 的数据，$N\le 500$，$M\le 10^4$。

// 对于 $100\%$ 的数据：$1\le N\le 5000$，$1\le M\le 2\times 10^5$，$1\le Z_i \le 10^4$，$1\le X_i,Y_i\le N$。


#include <iostream>
#include <algorithm>

using namespace std;

const int M = 200010;
const int N = 5010;

struct Edge{
    int a, b, w;
    // 运算符重载
    bool operator < (const Edge &W) const
    {
        return w < W.w;
    }
}edges[M];

int n, m;

int p[N];

int find(int x)
{
    if(p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d%d", &n, &m);

    for(int i=0 ; i<m ; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        edges[i] = {x, y, z};
    }
    // 按权重排序
    sort(edges, edges+m);
    // 初始化
    for(int i=1 ; i<=n ; i++)
        p[i] = i; // 每一个点最初在单独的集合中
    int ans = 0;
    int cnt = 0;
    
    for(int i=0 ; i<m ; i++)
    {
        int a = edges[i].a;
        int b = edges[i].b;
        int w = edges[i].w;
        if(find(a) != find(b)) // 如果a和b不在同一集合中
        {
            ans += w;
            p[find(a)] = p[find(b)];
            cnt++;
        }
    }
    
    if(cnt<n-1) printf("orz");
    else printf("%d", ans);

    return 0;
}