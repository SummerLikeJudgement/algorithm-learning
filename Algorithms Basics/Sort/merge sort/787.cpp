// 给定你一个长度为n的整数数列。

// 请你使用 归并排序 对这个数列按照从小到大进行排序。并将排好序的数列按顺序输出。

// 输入格式
// 输入共两行，第一行包含整数 n。
// 第二行包含 n个整数（所有整数均在 1∼10^9范围内），表示整个数列。

// 输出格式
// 输出共一行，包含 n个整数，表示排好序的数列。

// 数据范围
// 1≤n≤10000


#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n;
int q[N], tmp[N];

void merge_sort(int q[], int l, int r)
{
    if (l>=r) return;
    //基准元素
    int mid = l+r >> 1;
    //递归排序
    merge_sort(q, l, mid); merge_sort(q, mid+1, r);
    //归并
    int k=0, i=l ,j=mid+1;
    while(i<=mid && j<=r)
    {
        if (q[i]<=q[j])
        {
            tmp[k++] = q[i++];
        }
        else
        {
            tmp[k++] = q[j++];
        }
    }
    //将剩余的序列放到tmp
    while(i<=mid)
    {
        tmp[k++] = q[i++];
    }
    while(j<=r)
    {
        tmp[k++] = q[j++];
    }
    //将tmp复制回q
    for (i = l, j = 0 ; i<=r ; i++, j++)
    {
        q[i] = tmp[j];
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d",&q[i]);
    
    merge_sort(q, 0, n-1);

    for (int i = 0; i < n; i++) printf("%d ",q[i]);
    
    return 0;
}
