// 洛谷中acwing338的基础问题
// # P1980 [NOIP 2013 普及组] 计数问题

// ## 题目背景

// NOIP2013 普及组 T1

// ## 题目描述

// 试计算在区间 $1$ 到 $n$ 的所有整数中，数字 $x$（$0\le x\le9$）共出现了多少次？例如，在 $1$ 到 $11$ 中，即在 $1,2,3,4,5,6,7,8,9,10,11$ 中，数字 $1$ 出现了 $4$ 次。

// ## 输入格式

// $2$ 个整数 $n,x$，之间用一个空格隔开。

// ## 输出格式

// $1$ 个整数，表示 $x$ 出现的次数。

// ## 输入输出样例 #1

// ### 输入 #1

// ```
// 11 1
// ```

// ### 输出 #1

// ```
// 4
// ```

// ## 说明/提示

// 对于 $100\%$ 的数据，$1\le n\le 10^6$，$0\le x \le 9$。

#include <iostream>

using namespace std;

// 计算1~n中x的出现次数（x非0）
int count_x(int n, int x)
{
    int t = n;
    int ans = 0;
    int base = 1; // 正在处理的位数
    while(t) // 从低位到高位
    {
        int digit = t%10; // 正处理的位置的数字
        if(x < digit)
            ans += (n/(base*10) + 1) * base;
        else if(x == digit)
            ans += n/(base*10)*base + (n%base + 1);
        else if(x > digit)
            ans += (n/(base*10)) * base;
        
        // printf("%d t=%d base=%d digit=%d ans=%d\n", n/(base*10), t, base, digit, ans);

        t /= 10;
        base *= 10;
    }

    return ans;
}

// 计算1~n中0的出现次数
int count_0(int n, int x)
{
    int t = n;
    int ans = 0;
    int base = 1;
    while(t)
    {
        int digit = t%10;
        if(digit > 0)
            ans += n/(base*10) * base;
        else if(digit == 0)
            ans += (n/(base*10)-1)*base + (n%base + 1);

        t /= 10;
        base *= 10;

        // printf("ans=%d\n", ans);
    }
    
    return ans;
}

int main()
{
    int n, x;
    scanf("%d%d", &n, &x);
    if(x == 0)
        printf("%d", count_0(n, x));
    else
        printf("%d", count_x(n, x));
    
    return 0;
}

/// 求数字在每个数位上出现次数（分情况讨论计算），然后相加