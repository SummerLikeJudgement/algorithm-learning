// 洛谷中与acwing 282完全相同的区间DP模板题：https://www.luogu.com.cn/problem/P1775

// ## 题目描述

// 设有 $N(N \le 300)$ 堆石子排成一排，其编号为 $1,2,3,\cdots,N$。每堆石子有一定的质量 $m_i\ (m_i \le 1000)$。现在要将这 $N$ 堆石子合并成为一堆。每次只能合并相邻的两堆，合并的代价为这两堆石子的质量之和，合并后与这两堆石子相邻的石子将和新堆相邻。合并时由于选择的顺序不同，合并的总代价也不相同。试找出一种合理的方法，使总的代价最小，并输出最小代价。

// ## 输入格式

// 第一行，一个整数 $N$。

// 第二行，$N$ 个整数 $m_i$。

// ## 输出格式

// 输出文件仅一个整数，也就是最小代价。

// ## 输入输出样例 #1

// ### 输入 #1

// ```
// 4
// 2 5 3 1
// ```

// ### 输出 #1

// ```
// 22
// ```


#include <iostream>
#include <cstring>

using namespace std;

const int N=310;

int n;
// 前缀和方便求m[i~j]
int s[N];

int f[N][N];

int main()
{
    scanf("%d", &n);

    for(int i=1 ; i<=n ; i++)
    {
        scanf("%d", &s[i]);
        s[i] += s[i-1];
    }
    // 初始化f
    memset(f, 0x3f, sizeof f);
    for(int i=1 ; i<=n ; i++)
        f[i][i] = 0;

    // 从区间长度从小到大遍历
    for(int len=2 ; len<=n ; len++)
    {
        for(int i=1 ; i<=n-len+1 ; i++)
        {
            int j = i+len-1;
            for(int k=i ; k<=j-1 ; k++)
            {
                f[i][j] = min(f[i][j], f[i][k] + f[k+1][j] + s[j]-s[i-1]);
            }
        }
    }

    printf("%d", f[1][n]);

    return 0;
}

// 动态规划
//     状态表示：f(i,j)
//         集合：所有将第i堆石子到第j堆石子的合并方式
//         属性：所有方式的最小代价
//     状态转换：最终合并时左边堆的石子个数
//              f(i,j) = min{f(i,k) + f(k+1,j)} + m[i~j] (i<k,k+1<j)