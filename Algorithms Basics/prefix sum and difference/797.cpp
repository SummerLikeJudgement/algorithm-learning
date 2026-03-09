// 题目描述
// 输入一个长度为n 的整数序列。

// 接下来输入 m个操作，每个操作包含三个整数 l,r,c ，表示将序列中 [l,r] 之间的每个数加上 c 。

// 请你输出进行完所有操作后的序列。

// 输入格式
// 第一行包含两个整数 n 和 m 。

// 第二行包含 n 个整数，表示整数序列。

// 接下来 m 行，每行包含三个整数 l，r，c ，表示一个操作。

// 输出格式
// 共一行，包含 n 个整数，表示最终序列。

// 数据范围

// 输入输出样例
// 输入

// 6 3
// 1 2 2 1 2 1
// 1 3 1
// 3 5 1
// 1 6 1
// 输出

// 3 4 5 3 4 2
// 说明/提示
// 1≤n,m≤100000 ,

// 1≤l≤r≤n ,

// −1000≤c≤1000 ,

// −1000≤整数序列中元素的值≤1000

#include <iostream>

using namespace std;

const int N = 100010;

int A[N], B[N];

// 在A的[l,r]区间加上c
void insert(int l, int r, int c)
{
    B[l] += c;
    B[r+1] -= c;
}

int main()
{
    int n, m;
    scanf("%d%d",&n, &m);
    // 读取A数组
    for (int i = 1 ; i<=n ; i++) scanf("%d",&A[i]);
    // 构造初始差分数组
    for (int i = 1 ; i<=n ; i++) insert(i, i, A[i]);
    
    while(m--)
    {
        int l, r, c;
        scanf("%d%d%d",&l, &r, &c);
        insert(l, r, c);
    }
    int t = 0;
    for (int i = 1 ; i<=n ; i++)
    {
        t += B[i];
        printf("%d ", t);
    }

    return 0;
}