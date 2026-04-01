// 题目描述
// 给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环，所有边权均为非负值。
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
// 1≤n,m≤1.5×10^5
 
// 图中涉及边长均不小于 0，且不超过 10000。
// 数据保证：如果最短路存在，则最短路的长度不超过10^9

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> PII;
const int N = 150010;

int n, m;
// 邻接表
int idx;
int h[N]; // 头指针
int ne[N]; // 下一个指针
int e[N]; // 编号
int w[N]; // 权重
// Dijkstra
bool st[N];
priority_queue<PII, vector<PII>, greater<PII>> heap; // 小根堆，元素是pair<距离,编号>
int dist[N];

void add(int x, int y, int z)
{
    e[idx] = y;
    ne[idx] = h[x];
    h[x] = idx;
    w[idx] = z;
    idx++;
}

int dijkstra()
{
    // 初始化
    heap.push({0,1});// {距离,编号}。一定要是距离在前！
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    while (heap.size())
    {
        auto t = heap.top(); // 当前距离最小的点，可能重复
        heap.pop();

        int distance = t.first, num = t.second;
        if(st[num]) // 已经确定最小距离，则跳过
            continue;
        
        st[num] = true;
        for(int i=h[num] ; i!=-1 ; i=ne[i])
        {
            int j = e[i];
            if(dist[j] > distance+w[i])
            {
                dist[j] = distance+w[i];
                heap.push({dist[j],j});
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
    // 邻接表初始化
    memset(h, -1, sizeof h);

    while(m--)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
    }

    int ans = dijkstra();

    printf("%d", ans);

    return 0;
}

// 点和边数量级类似->稀疏图->邻接表