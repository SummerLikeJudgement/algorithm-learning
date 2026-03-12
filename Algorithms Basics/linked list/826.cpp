// 题目描述
// 实现一个单链表，链表初始为空，支持三种操作：
// (1) 向链表头插入一个数；
// (2) 删除第k个插入的数后面的数；
// (3) 在第k个插入的数后插入一个数
// 现在要对该链表进行M次操作，进行完所有操作后，从头到尾输出整个链表。

// 注意:题目中第k个插入的数并不是指当前链表的第k个数。例如操作过程中一共插入了n个数，则按照插入的时间顺序，这n个数依次为：第1个插入的数，第2个插入的数，…第n个插入的数。

// 输入格式
// 第一行包含整数M，表示操作次数。
// 接下来M行，每行包含一个操作命令，操作命令可能为以下几种：
// (1) “H x”，表示向链表头插入一个数x。
// (2) “D k”，表示删除第k个输入的数后面的数（当k为0时，表示删除头结点）。
// (3) “I k x”，表示在第k个输入的数后面插入一个数x（此操作中k均大于0）。

// 输出格式
// 共一行，将整个链表从头到尾输出。

// 输入输出样例
// 输入
// 10
// H 9
// I 1 1
// D 1
// D 0
// H 6
// I 3 6
// I 4 5
// I 4 5
// I 3 4
// D 6
// 输出
// 6 4 6 5
// 说明/提示
// 1≤M≤100000

// 所有操作保证合法。

#include <iostream>

using namespace std;

const int N = 100010;

//head 头节点的下标
//e[i] 节点i的值
//ne[i] 节点i的next指针
//idx 当前的节点
int head, e[N], ne[N], idx;

// 初始化
void init()
{
    head = -1;
    idx = 0;
}

//将x插入到头节点
void add_to_head(int x)
{
    e[idx] = x;// 将x存入数组
    ne[idx] = head;// x的节点的指针指向原头节点
    head = idx;// 新头节点
    idx++;
}

//将x插入到下标k节点的后面
void add(int x, int k)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

// 将下标k节点后面的节点删除
void remove(int k)
{
    if (k==0) head = ne[head];
    else ne[k] = ne[ne[k]];
}

int main()
{
    int m;
    scanf("%d", &m);

    init();

    while(m--)
    {
        int k, x;
        char Oper;

        scanf(" %c", &Oper);;
        if (Oper == 'H')
        {
            scanf("%d", &x);
            add_to_head(x);
        }
        else if (Oper == 'D')
        {
            scanf("%d", &k);
            if (k==0) remove(k);
            else remove(k-1);
        }
        else if (Oper == 'I')
        {
            scanf("%d%d", &k, &x);
            add(x, k-1);
        }
    }

    for (int i=head ; i!=-1 ; i=ne[i])
    {
        printf("%d ",e[i]);
    }
    
    return 0;
}