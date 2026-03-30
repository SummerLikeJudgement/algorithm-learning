// 题目描述
// 给定一个长度为 n 的整数数列，以及一个整数 k，请用快速选择算法求出数列从小到大排序后的第 k 个数。

// 输入格式
// 第一行包含两个整数 n 和 k。
// 第二行包含 n 个整数（所有整数均在 1∼109 范围内），表示整数数列。

// 输出格式
// 输出一个整数，表示数列的第 k 小数。

// 数据范围1≤n≤100000,1≤k≤n

// 输入样例：
// 5 3
// 2 4 1 5 3
// 输出样例：
// 3

///原始快排
// #include <iostream>

// using namespace std;

// const int N = 100010;
// int A[N];

// void quick_sort(int l, int r, int A[])
// {
//     if (l>=r) return;

//     int i = l-1, j = r+1;
//     int x = A[l]; // 基准元素

//     while(i<j)
//     {
//         while(A[++i] < x)//移动左指针
//         {}
//         while(A[--j] > x)//移动右指针
//         {}
//         if (i<j) swap(A[i], A[j]); //交换元素
//     }

//     quick_sort(l, j, A);
//     quick_sort(j+1, r, A);
// }

// int main()
// {
//     int n, k;
//     scanf("%d%d",&n, &k);
//     for (int i=0 ; i<n ; i++)
//         scanf("%d",&A[i]);

//     quick_sort(0, n-1, A);

//     printf("%d",A[k-1]);

//     return 0;
// }

/// 优化快排（只排序第k位元素在的部分）
#include <iostream>

using namespace std;

const int N = 100010;
int A[N];

void quick_sort(int l, int r, int k, int A[])
{
    if (l>=r) return;

    int i = l-1, j = r+1;
    int x = A[l]; // 基准元素

    while(i<j)
    {
        while(A[++i] < x)//移动左指针
        {}
        while(A[--j] > x)//移动右指针
        {}
        if (i<j) swap(A[i], A[j]); //交换元素
    }

    if (j - l + 1 >= k - 1) // 第k位在左边
        quick_sort(l, j, k, A);
    else // 第k位在右边
        quick_sort(j+1, r, k, A);
}

int main()
{
    int n, k;
    scanf("%d%d",&n, &k);
    for (int i=0 ; i<n ; i++)
        scanf("%d",&A[i]);

    quick_sort(0, n-1, k, A);

    printf("%d",A[k-1]);

    return 0;
}