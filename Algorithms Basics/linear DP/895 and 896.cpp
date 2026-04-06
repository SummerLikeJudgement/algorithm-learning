// 题目描述
// 给出一个由 n(n≤5000) 个不超过 10^6的正整数组成的序列。请输出这个序列的最长上升子序列的长度。
// 最长上升子序列是指，从原序列中按顺序取出一些数字排在一起，这些数字是逐渐增大的。

// 输入格式
// 第一行，一个整数 n，表示序列长度。
// 第二行有 n 个整数，表示这个序列。

// 输出格式
// 一个整数表示答案。

// 输入输出样例
// 输入
// 6
// 1 2 4 1 3 4
// 输出
// 4
// 说明/提示
// 分别取出 1、2、3、4 即可。


// #include <iostream>

// using namespace std;

// const int N=5010;
// int n;
// int v[N];
// int f[N];

// int main()
// {
//     scanf("%d", &n);
//     for(int i=1 ; i<=n ; i++)
//         scanf("%d", &v[i]);

//     int ans = 0;

//     for(int i=1 ; i<=n ; i++)
//     {
//         f[i] = 1; // 子序列只有i一个数
//         for(int j=1 ; j<i ; j++)
//         {
//             if(v[j]<v[i])
//                 f[i] = max(f[i], f[j]+1);
//         }
//         ans = max(ans, f[i]);
//     }

//     printf("%d", ans);

//     return 0;
// }

// DP思路：
// 	状态表示：结尾的数字=一维 f(i)
//		集合
//		    集合的实际含义--所有上升子序列
//		    限制条件--以第i个元素结尾
//		属性：f(i)的值是集合（即所有路径）的Max长度
//	状态计算：集合划分=子序列中i-1的数字是序列中第k个数

/// acwing 896增大了序列元素数量，只使用朴素dp会超时
/// 本质思想：对于同样长度的子串，希望它的末端越小越好，这样后面更易扩展它,使数列更长。对于同样长度的子串，希望它的末端越小越好，这样后面更易扩展它,使数列更长。
#include <iostream>

using namespace std;

const int N=1e5+10;
int n;
int v[N];
int f[N];
// 已经确定f的长度
int len;

// 在f中找到小于x的第一个元素位置
int binary_search(int x)
{
    int l=0, r=len, mid;
    // 找到左区间(f<x)的右端点
    while (l<r)
    {
        mid = (l+r+1)/2;
        if(f[mid]<x)
            l=mid;
        else
            r=mid-1;
    }

    return l;
}

int main()
{
    scanf("%d", &n);
    for(int i=1 ; i<=n ; i++)
        scanf("%d", &v[i]);

    // 初始化
    len = 1;
    f[1] = v[1];

    for(int i=2 ; i<=n ; i++)
    {
        if(v[i]>f[len])
            f[++len] = v[i];
        else
        {
            int pos = binary_search(v[i]);
            f[pos+1] = v[i];
        }
    }

    printf("%d", len);

    return 0;
}
// DP思路：
// 	状态表示：结尾的元素=一维 f(i)
//		集合
//		    集合的实际含义--所有的上升子序列
//		    限制条件--子序列长度为i
//		属性：f(i)的值是集合（即所有长度为i的上升子序列）的Min结尾元素
//	状态计算：【f(i)的值一定是单调递增的】集合划分=如果a[i]>f(len),f(++len)=a[i];如果a[i]<f(len),找到a[i]<f(k),f(k+1)=a[i]
