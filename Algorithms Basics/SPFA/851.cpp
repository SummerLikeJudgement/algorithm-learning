// 题目描述
// 给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环，边权可能为负数。
// 请你求出 1 号点到 n 号点的最短距离，如果无法从 1 号点走到 n 号点，则输出 impossible。
// 数据保证不存在负权回路。

// 输入格式
// 第一行包含两个整数 n 和 m。
// 接下来 m 行，每行包含三个整数 x, y, z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

// 输出格式
// 输出一个整数，表示 1 号点到 n 号点的最短距离。
// 如果路径不存在，则输出 impossible。

// 输入输出样例
// 无

// 说明/提示
// 1≤n,m≤10^5
// 图中涉及边长绝对值均不超过 10^4


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



void add(int x, int y, int z)
{
    e[idx] = y;
    ne[idx] = h[x];
    h[x] = idx;
    w[idx] = z;
    idx++;
}


int SPFA()
{
    // 初始化
    memset(dist, 0x3f , sizeof dist);
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    st[1] = true;
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
                if(!st[j]) // 如果j不在队列中
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    if(dist[n] == 0x3f3f3f3f) 
        return -1;
    else
        return dist[n];
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
    
    int ans = SPFA();

    if(ans == -1)
        printf("impossible");
    else
        printf("%d", ans);

    return 0;
}