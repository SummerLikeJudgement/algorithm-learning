// 题目描述
// 给定一个浮点数 n，求它的三次方根。

// 输入格式
// 共一行，包含一个浮点数 n。

// 输出格式
// 共一行，包含一个浮点数，表示问题的解。

// 注意，结果保留 6 位小数。

// 输入输出样例
// 输入
// 1000.00
// 输出
// 10.000000

// 说明/提示
// −10000≤n≤10000

#include <iostream>

using namespace std;

int main()
{
    double n;
    cin >> n;

    double l=-50.0, r=50.0;
    double mid;

    while(r-l>1e-8)
    {
        mid = (l+r)/2;
        if (mid*mid*mid <= n) l=mid;
        else r=mid;
    }
    printf("%.6lf",l);

    return 0;
}