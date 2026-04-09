// 题目描述
// 给定一个 n 个点 m 条边的无向图，图中可能存在重边和自环。
// 请你判断这个图是否是二分图。

// 输入格式
// 第一行包含两个整数 n 和 m。
// 接下来 m 行，每行包含两个整数 u 和 v，表示点 u 和点 v 之间存在一条边。

// 输出格式
// 如果给定图是二分图，则输出 Yes，否则输出 No。

// 输入输出样例
// 输入
// 4 4
// 1 3
// 1 4
// 2 3
// 2 4

// 输出
// Yes

// 说明/提示
// 1≤n,m≤10^5

#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010;
// 邻接表
int e[2*N], ne[2*N], h[N];
int idx;
int color[N]; // 0表示未染色，1/2表示两种颜色

int n, m;

void add(int x, int y)
{
    e[idx] = y;
    ne[idx] = h[x];
    h[x] = idx;
    idx++;
}
// 在u号点处执行DFS进行染色(c=1/2)
bool dfs(int u, int c)
{
    color[u] = c;

    for(int i=h[u] ; i!=-1 ; i=ne[i])
    {
        int j=e[i];
        if(!color[j]) // 未染色
        {
            if(!dfs(j, 3-c))
                return false;
        }
        else // 染色
        {
            if(color[j] == c)
                return false;
        }
    }

    return true;
}

int main()
{
    scanf("%d%d", &n, &m);
    //初始化
    memset(h, -1, sizeof h);

    while (m--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }
    // 染色法
    bool flag = true;
    for(int i=1 ; i<=n ; i++)// 遍历所有点,因为可能不是连通图
    {
        if(!color[i]) // 如果还未染色
        {
            if(!dfs(i, 1)) // 如果dfs返回false，说明有矛盾发生
            {
                flag = false;
                break;
            }
        }
    }

    if(flag) printf("Yes");
    else printf("No");
}

// n、m同一数量级->稀疏图->邻接表