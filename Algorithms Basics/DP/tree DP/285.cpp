// 洛谷中与acwing 285完全相同的模板题《没有上司的舞会》 https://www.luogu.com.cn/problem/P1352

// ## 题目描述

// 某大学有 $n$ 个职员，编号为 $1\ldots n$。

// 他们之间有从属关系，也就是说他们的关系就像一棵以校长为根的树，父结点就是子结点的直接上司。

// 现在有个周年庆宴会，宴会每邀请来一个职员都会增加一定的快乐指数 $r_i$，但是呢，如果某个职员的直接上司来参加舞会了，那么这个职员就无论如何也不肯来参加舞会了。

// 所以，请你编程计算，邀请哪些职员可以使快乐指数最大，求最大的快乐指数。

// ## 输入格式

// 输入的第一行是一个整数 $n$。

// 第 $2$ 到第 $(n + 1)$ 行，每行一个整数，第 $(i+1)$ 行的整数表示 $i$ 号职员的快乐指数 $r_i$。

// 第 $(n + 2)$ 到第 $2n$ 行，每行输入一对整数 $l, k$，代表 $k$ 是 $l$ 的直接上司。

// ## 输出格式

// 输出一行一个整数代表最大的快乐指数。

// ## 输入输出样例 #1

// ### 输入 #1

// ```
// 7
// 1
// 1
// 1
// 1
// 1
// 1
// 1
// 1 3
// 2 3
// 6 4
// 7 4
// 4 5
// 3 5

// ```

// ### 输出 #1

// ```
// 5

// ```

// ## 说明/提示

// #### 数据规模与约定

// 对于 $100\%$ 的数据，保证 $1\leq n \leq 6 \times 10^3$，$-128 \leq r_i\leq 127$，$1 \leq l, k \leq n$，且给出的关系一定是一棵树。

#include <cstring>
#include <iostream>

using namespace std;

const int N = 6010;

int happy[N]; // 快乐指数
int h[N], ne[N], e[N], idx; // 使用邻接表存储树
int f[N][2];
bool hasfather[N];

void add(int k, int l)
{
    e[idx] = l;
    ne[idx] = h[k];
    h[k] = idx;
    idx++;
}

// 节点u处的dfs
void dfs(int u)
{
    // 初始化
    f[u][1] = happy[u];// 不选择u初始化为0

    for(int i=h[u] ; i!=-1 ; i=ne[i])
    {
        int t = e[i];

        dfs(t);

        f[u][0] += max(f[t][0], f[t][1]);
        f[u][1] += f[t][0];
    }

}

int main()
{
    int n;
    scanf("%d", &n);
    
    // 初始化
    memset(h, -1, sizeof h);
    for(int i=1 ; i<=n ; i++)
        scanf("%d", &happy[i]);
    for(int i=1 ; i<n ; i++)
    {
        int l, k;
        scanf("%d%d", &l, &k);
        hasfather[l] = true;
        add(k, l);
    }
    // 求树的根节点
    int root = 1;
    while (hasfather[root])
        root++;

    dfs(root);

    printf("%d", max(f[root][0], f[root][1]));

    return 0;
}
/// 状态表示:f(u,0)在以u为根的子树中选择，并且不选u的所有方案；f(u,1)在以u为根的子树中选择，并且选u的所有方案；
/// -> 属性：最大值
/// 状态转换:f(u,0) += max(f(s_i,0),f(s_i,1))；f(u,1) += f(s_i,0)