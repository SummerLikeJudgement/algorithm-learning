// 题目描述
// 给定一个 n 个点 m 条边的有向图，点的编号是 1 到 n，图中可能存在重边和自环。
// 请输出任意一个该有向图的拓扑序列，如果拓扑序列不存在，则输出 −1。
// 若一个由图中所有点构成的序列 A 满足：对于图中的每条边 (x,y)，x 在 A 中都出现在 y 之前，则称 A 是该图的一个拓扑序列。

// 输入格式
// 第一行包含两个整数 n 和 m。
// 接下来 m 行，每行包含两个整数 x 和 y，表示存在一条从点 x 到点 y 的有向边 (x,y)。

// 输出格式
// 共一行，如果存在拓扑序列，则输出任意一个合法的拓扑序列即可。
// 否则输出 −1。

// 输入输出样例
// 输入
// 3 3
// 1 2
// 2 3
// 1 3

// 输出
// 1 2 3

// 说明/提示
// 1≤n,m≤10 
// 5

#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5+10;

int n, m;
// 存储图
int h[N], ne[N], e[N];
int idx;
// 队列
int q[N];
int hh, tt;
// 每个点的入度
int d[N];

void add(int x, int y)
{
    e[idx] = y;
    ne[idx] = h[x];
    h[x] = idx;
    idx++;
}

bool topsort()
{
    hh = 0;
    tt = -1;
    // 将入度为0的点加入队列
    for(int i=1 ; i<=n ; i++)
        if(!d[i])
            q[++tt] = i;
    
    while(hh<=tt)
    {
        int t = q[hh++];
        for(int i=h[t] ; i!=-1 ; i=ne[i])
        {
            int j = e[i];
            d[j]--;
            if(d[j] == 0)
                q[++tt] = j;
        }
    }
    
    return tt == n-1; // 如果读入n-1个点，则有拓扑序列，否则没有
}

int main()
{
    scanf("%d%d", &n, &m);
    // 初始化存储图
    memset(h, -1, sizeof h);
    while(m--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
        d[y]++;
    }
    
    if(topsort())
    {
        for(int i=0 ; i<n ; i++)
            printf("%d ", q[i]);
    }
    else
        printf("-1\n");
    
    return 0;
}