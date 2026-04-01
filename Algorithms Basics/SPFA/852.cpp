// 题目描述
// 给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环，边权可能为负数。
// 请你判断图中是否存在负权回路。

// 输入格式
// 第一行包含整数 n 和 m。
// 接下来 m 行每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

// 输出格式
// 如果图中存在负权回路，则输出Yes；否则输出No。

// 输入输出样例
// 输入
// 3 3
// 1 2 114
// 2 3 514
// 3 1 -1919
// 输出
// Yes

// 输入
// 3 3
// 1 2 -1145
// 2 3 -14
// 3 1 1919
// 输出
// No

// 说明/提示
// 1≤n≤2000,
// 1≤m≤10000,
// 图中涉及边长绝对值均不超过 10000。


#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N=100010;

int n, m;
// 邻接表
int h[N], e[N], ne[N];
int idx;
int w[N];

int dist[N];
bool st[N]; // 表示点是否在队列当中，防止队列存重复的点
int cnt[N]; // 记录每个点的最短路径经过的边数是多少


void add(int x, int y, int z)
{
    e[idx] = y;
    ne[idx] = h[x];
    h[x] = idx;
    w[idx] = z;
    idx++;
}


bool SPFA()
{
    // 初始化
    queue<int> q;
    for(int i=1 ; i<=n ; i++) // 之前的初始化是找从1开始的最短路径，但可能负权环不在1为起点的路径上，所以要全部放入队列并且dist都置为0
    {
        q.push(i);
        st[i] = true;
    }
    // 只找有更新的边
    while(q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;

        for(int i=h[t] ; i!=-1 ; i=ne[i])
        {
            int j = e[i];
            int weight = w[i];
            int distance = dist[t];
            if(dist[j] > distance+weight)
            {
                dist[j] = distance+weight;
                cnt[j] = cnt[t] + 1;
                if(!st[j]) // 如果j不在队列中
                {
                    q.push(j);
                    st[j] = true;
                }
                if(cnt[j] >= n)
                    return true;
            }
        }
    }

    return false;
}


int main()
{
    scanf("%d%d", &n, &m);
    //初始化
    memset(h, -1, sizeof h);

    while (m--)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
    }
    
    bool ans = SPFA();

    if(ans)
        printf("Yes");
    else
        printf("No");

    return 0;
}