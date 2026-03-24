//下面代码是洛谷题目的答案，要求的输出有些许不同：https://www.luogu.com.cn/problem/U164672

// 题目：
// 给定一颗树，树中包含 n 个结点（编号 1∼n）和 n−1 条无向边。
// 请你找到树的重心，并输出将重心删除后，剩余各个连通块中点数的最大值。
// 重心定义：重心是指树中的一个结点，如果将这个点删除后，剩余各个连通块中点数的最大值最小，那么这个节点被称为树的重心。

// 输入格式
// 第一行包含整数 n，表示树的结点数。
// 接下来 n−1 行，每行包含两个整数 a 和 b，表示点 a 和点 b 之间存在一条边。

// 输出格式
// 输出一个整数 m，表示将重心删除后，剩余各个连通块中点数的最大值。

// 数据范围
// 1≤n≤10^5
 

// 输入样例
// 9
// 1 2
// 1 7
// 1 4
// 2 8
// 2 5
// 4 3
// 3 9
// 4 6

// 输出样例：
// 4


#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5+10;

int n;
// 储存树
int h[N];
int e[2*N];
int ne[2*N];
int idx;
// 记录最小的最大值
int res = N;
int res_node;
// 标记是否被搜索
bool st[N];

// 编号u节点的dfs，返回该节点树中点数
int dfs(int u)
{
    st[u] = true;
    int cnt = 1;
    int max_ = 0;
    for(int i=h[u] ; i!=-1 ; i=ne[i])
    {
        int sum;
        int j = e[i]; // 节点编号
        if (st[j]) continue; // 如果被标记，跳过
        sum = dfs(j);
        cnt += sum;
        max_ = max(max_, sum);
    }
    max_ = max(max_, n-cnt);
    
    if (max_ < res) res_node = u;
    if (max_ == res) res_node = min(u, res_node);
    res = min(res, max_);
    return cnt; 
}

int main()
{
    scanf("%d", &n);
    //初始化
    memset(h, -1, sizeof h);

    for (int i=0 ; i<n-1 ; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        // a->b存入
        e[idx] = b;
        ne[idx] = h[a];
        h[a] = idx;
        idx++;
        // b->a存入
        e[idx] = a;
        ne[idx] = h[b];
        h[b] = idx;
        idx++;
    }
    // 从编号1开始DFS。可以将任意点作为根节点
    int sum = dfs(1);

    printf("%d\n", res_node);
    printf("%d", res);

    return 0;
}



// 一定是一棵树，所以删除节点的结果是该节点的子树们+所有节点去掉该节点为根的树
// 故该节点=max(该节点的子树们,所有节点去掉该节点为根的树)
// DFS遍历可以得到每个节点为根的树的节点数


// 注意输出的是最小重心