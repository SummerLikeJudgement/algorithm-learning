//洛谷单调栈模板题：https://www.luogu.com.cn/problem/P5788

// 题目描述
// 给出项数为 n 的整数数列 a_{1…n}
// 定义函数 f(i) 代表数列中第 i 个元素之后第一个大于 a_i的元素的下标；若不存在，则 f(i)=0。
// 试求出 f(1…n)。

// 输入格式
// 第一行一个正整数 n。
// 第二行 n 个正整数 a_{1…n}
// 输出格式
// 一行 n 个整数表示 f(1),f(2),…,f(n) 的值。

// 输入输出样例
// 输入

// 5
// 1 4 2 3 5
// 输出

// 2 5 4 5 0

// 说明/提示
// 【数据规模与约定】
// 对于 30% 的数据，n≤100；
// 对于 60% 的数据，n≤5×10^3
// 对于 100% 的数据，1≤n≤3×10^6，1≤ai≤10^9

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;// first数值，second下标

const int N=3e6+10;
PII stk[N];
int tt;
vector<int> a, res;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0 ; i<n ; i++)
    {
        int x;
        scanf("%d", &x);
        a.push_back(x);
    }
    for (int i=a.size()-1 ; i>=0 ; i--)
    {
        int x = a[i];
        while(tt && stk[tt].first<=x) tt--;
        // if (tt) printf("%d ", stk[tt].second); // 栈中还有
        // else printf("0 ");// 栈中没有
        if (tt) res.push_back(stk[tt].second);
        else res.push_back(0);
        stk[++tt] = {x, i+1};
    }

    reverse(res.begin(), res.end());
    for (int i=0 ; i<res.size() ; i++)
        printf("%d ", res[i]);
    
    return 0;
}