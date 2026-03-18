// 题目描述
// 维护一个集合，初始时集合为空，支持如下几种操作：

// I x，插入一个数 x；
// PM，输出当前集合中的最小值；
// DM，删除当前集合中的最小值（数据保证此时的最小值唯一）；
// D k，删除第 k 个插入的数；
// C k x，修改第 k 个插入的数，将其变为 x；
// 现在要进行 N 次操作，对于所有第 2 个操作，输出当前集合的最小值。

// 输入格式
// 第一行包含整数 N。
// 接下来 N 行，每行包含一个操作指令，操作指令为 I x，PM，DM，D k 或 C k x 中的一种。

// 输出格式
// 对于每个输出指令 PM，输出一个结果，表示当前集合中的最小值。
// 每个结果占一行。

// 输入输出样例
// 输入
// 8
// I -10
// PM
// I -10
// D 1
// C 2 8
// I 6
// PM
// DM

// 输出
// -10
// 6
// 说明/提示
// 数据范围
// 1≤N≤10^5
// −10^9≤x≤10^9
 

// 数据保证合法。


#include <iostream>
#include <string.h>

using namespace std;

const int N = 1e5+10;

int n;
int h[N], size_;//堆，堆当前存入的个数
int hp[N];//堆中节点对应的插入顺序
int ph[N];//插入顺序对应的堆中节点

// 堆中位置a和b交换时，hp、ph也要更新
void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);// 顺序对应堆先交换
    swap(hp[a], hp[b]);// 堆对应顺序再交换
    swap(h[a], h[b]);
}

// 将x位置的节点尝试down
void down(int x)
{
    int t = x;// t存储三个节点中最小的
    if (x*2 <= size_ && h[x*2] < h[t]) t = x*2;
    if (x*2+1 <= size_ && h[x*2+1] < h[t]) t = x*2+1;

    if (x != t)
    {
        heap_swap(x, t);
        down(t);
    }
}

// 将x位置的节点尝试up
void up(int x)
{
    while(x/2 && h[x/2]>h[x]) // 当父节点存在并且更大
    {
        heap_swap(x/2, x);
        x /= 2;
    }
}

int main()
{
    scanf("%d", &n);

    int cnt;

    while(n--)
    {
        char Op[2];
        scanf("%s", Op);
        if (!strcmp(Op, "I"))// 插入
        {
            int x;
            scanf("%d", &x);
            h[++size_] = x;
            // hp、ph更新
            hp[size_] = ++cnt;
            ph[cnt] = size_;

            up(size_);
        }
        else if (!strcmp(Op, "PM"))// 输出最小值
        {
            printf("%d\n", h[1]);
        }
        else if (!strcmp(Op, "DM"))
        {
            heap_swap(1, size_--);
            down(1);
        }
        else if (!strcmp(Op, "D"))// 删除第k插入的数
        {
            int k;
            scanf("%d", &k);

            int p = ph[k];// 删除的数的堆中位置
            heap_swap(p, size_);
            size_--;

            up(p);
            down(p);
        }
        else// 修改第k插入的数
        {
            int k, x;
            scanf("%d%d", &k, &x);

            int p = ph[k];// 修改的数的堆中位置
            h[p] = x;

            up(p);
            down(p);
        }
    }

    return 0;
}