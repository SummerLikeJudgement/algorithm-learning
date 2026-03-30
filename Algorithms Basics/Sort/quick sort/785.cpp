// 给定一个长n的数列，将其从小到大排序。

// 输入格式：
// 输入共两行，第一行包含整数n。第二行包含n个整数（所有整数均在1 ∼ 10^9范围内），表示整个数列。

// 输出格式：
// 输出共一行，包含n个整数，表示排好序的数列。

// 数据范围：
// 1≤n≤100000


#include <iostream>

using namespace std;

const int N = 1e6 +10;

int n;
int q[N];


void quick_sort(int q[], int l, int r)
{
    if (l>=r) return;

    int x = q[l]; //取base元素
    int i = l-1, j = r+1; //注意指针要放在边界两侧，为了后面指针移动方便
    while(i<j)
    {
        while(q[++i] < x)
        {} //移动左指针
        while(q[--j] > x)
        {} //移动右指针
        if (i<j) //交换元素
        {
            swap(q[i], q[j]);
        }
    }
    //递归处理
    quick_sort(q, l, j); // 以j作为边界，x就不能为q[r];以i作为边界，x就不能为q[l]
    quick_sort(q, j+1, r); // 即不能取到边界，否则会死循环(同一个区间无限递归)
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &q[i]);
    }
    

    quick_sort(q, 0, n-1);
    
    for(int i = 0; i < n; i++)
    {
        printf("%d ", q[i]);
    }

    return 0;
}