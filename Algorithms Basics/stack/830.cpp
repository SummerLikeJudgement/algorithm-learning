// 给定一个长度为N的整数数列，输出每个数左边第一个比它小的数，如果不存在则输出-1。

// 输入格式
// 第一行包含整数N，表示数列长度。
// 第二行包含N个整数，表示整数数列。

// 输出格式
// 共一行，包含N个整数，其中第i个数表示第i个数的左边第一个比它小的数，如果不存在则输出-1。

// 数据范围
// 1≤N≤10^5
// 1≤数列中元素≤10^9

// 输入样例：
// 5
// 3 4 2 7 5
// 输出样例：
// -1 3 -1 2 2
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int stk[N], tt;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0 ; i<n ; i++)
    {
        int x;
        scanf("%d", &x);
        while(tt>0 && stk[tt] >= x) tt--;//当x<y且a_x>=a_y时，直接弹出栈顶元素
        if (tt) printf("%d ", stk[tt]);
        else printf("-1 ");
        stk[++tt] = x;
    }
    return 0;
}