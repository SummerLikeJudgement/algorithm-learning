// 题目描述：
// 输入一个长度为n的整数数列，从小到大输出前m小的数。

// 输入格式
// 第一行包含整数n和m。
// 第二行包含n个整数，表示整数数列。

// 输出格式
// 共一行，包含m个整数，表示整数数列中前m小的数。

// 数据范围

// 1≤m≤n≤10^5，
// 1≤数列中元素≤10^9

// 输入样例：
// 5 3
// 4 5 1 3 2

// 输出样例：
// 1 2 3

#include <iostream>

using namespace std;

const int N = 1e5+10;

int n, m;
int h[N], size_;//堆，堆当前存入的个数

// 将x位置的节点尝试down
void down(int x)
{
    int t = x;// t存储三个节点中最小的
    if (x*2 <= size_ && h[x*2] < h[t]) t = x*2;
    if (x*2+1 <= size_ && h[x*2+1] < h[t]) t = x*2+1;

    if (x != t)
    {
        swap(h[t], h[x]);
        down(t);
    }
}

// 将x位置的节点尝试up
void up(int x)
{
    while(x/2 && h[x/2]>h[x]) // 当父节点存在并且更大
    {
        swap(h[x/2], h[x]);
        x /= 2;
    }
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i=1 ; i<=n ; i++)
        scanf("%d", &h[i]);
    size_ = n;

    // 将数组建立为堆
    for (int i=n/2 ; i ; i--)
        down(i);

    while(m--)
    {
        printf("%d ", h[1]);
        h[1] = h[size_--];
        down(1);
    }

    return 0;
}