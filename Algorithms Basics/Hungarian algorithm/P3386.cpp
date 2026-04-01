// 洛谷类似acwing 861的二分图最大匹配的模板题：https://www.luogu.com.cn/problem/P3386

// ## 题目描述

// 给定一个二分图，其左部点的个数为 $n$，右部点的个数为 $m$，边数为 $e$，求其最大匹配的边数。

// 左部点从 $1$ 至 $n$ 编号，右部点从 $1$ 至 $m$ 编号。

// ## 输入格式

// 输入的第一行是三个整数，分别代表 $n$，$m$ 和 $e$。

// 接下来 $e$ 行，每行两个整数 $u, v$，表示存在一条连接左部点 $u$ 和右部点 $v$ 的边。

// ## 输出格式

// 输出一行一个整数，代表二分图最大匹配的边数。

// ## 输入输出样例 #1

// ### 输入 #1

// ```
// 1 1 1
// 1 1

// ```

// ### 输出 #1

// ```
// 1
// ```

// ## 输入输出样例 #2

// ### 输入 #2

// ```
// 4 2 7
// 3 1
// 1 2
// 3 2
// 1 1
// 4 2
// 4 1
// 1 1

// ```

// ### 输出 #2

// ```
// 2

// ```

// ## 说明/提示

// #### 数据规模与约定

// 对于全部的测试点，保证：
// - $1 \leq n, m \leq 500$。
// - $1 \leq e \leq 5 \times 10^4$。
// - $1 \leq u \leq n$，$1 \leq v \leq m$。

// **不保证给出的图没有重边**。


#include <iostream>
#include <cstring>

using namespace std;

const int N = 510;

int n, m, e;
// 邻接矩阵
int g[N][N];

int match[N];// 记录右边匹配左边的编号
bool st[N];
// 寻找左边编号u的配对
bool find(int u)
{
    for(int i=1 ; i<=m ; i++) // 遍历所有的右边点
    {
        if(g[u][i]==0 || st[i]==true)
            continue;

        st[i] = true;
        if(match[i] == 0)
        {
            match[i] = u;
            return true;
        }
        if(match[i] && find(match[i])) // 如果右边已经匹配+能够更换匹配
        {
            match[i] = u;
            return true;
        }
    }
    return false;
}

int main()
{
    scanf("%d%d%d", &n, &m, &e);
    
    while (e--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x][y] = 1;
    }
    
    int ans = 0;

    for(int i=1 ; i<=n ; i++)
    {
        memset(st, false, sizeof st); // 每次左边点匹配前都要重置st
        if(find(i))
            ans++;
    }
    
    printf("%d", ans);

    return 0;
}

// 匈牙利算法只存储从左指向右的边即可