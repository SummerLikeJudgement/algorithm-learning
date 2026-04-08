// 题目描述
// 实现一个双链表，双链表初始为空，支持5种操作：
// 在最左侧插入一个数；
// 在最右侧插入一个数；
// 将第 k 个插入的数删除；
// 在第 k个插入的数左侧插入一个数；
// 在第 k个插入的数右侧插入一个数
// 现在要对该链表进行M次操作，进行完所有操作后，从左到右输出整个链表。

// 注意:题目中第k个插入的数并不是指当前链表的第 k 个数。例如操作过程中一共插入了 n 个数，则按照插入的时间顺序，这 n 个数依次为：第1 个插入的数，第 2个插入的数，…第 n 个插入的数。

// 输入格式
// 第一行包含整数M，表示操作次数。
// 接下来 M行，每行包含一个操作命令，操作命令可能为以下几种：
// L x，表示在链表的最左端插入数x。
// R x，表示在链表的最右端插入数 x。
// D k，表示将第 k个插入的数删除。
// IL k x，表示在第 k个插入的数左侧插入一个数。
// IR k x，表示在第 k个插入的数右侧插入一个数。

// 输出格式
// 共一行，将整个链表从左到右输出。

// 输入输出样例
// 输入
// 10
// R 7
// D 1
// L 3
// IL 2 10
// D 3
// IL 2 7
// L 8
// R 9
// IL 4 7
// IR 2 2
// 输出
// 8 7 7 3 2 9

// 说明/提示
// 1≤M≤100000

// 所有操作保证合法。

#include <iostream>

using namespace std;

const int N = 100010;

int e[N], l[N], r[N], idx;

//初始化
void init()
{
    //下标为0的点表示头节点，下标为1的点表示尾节点
    l[1] = 0;
    r[0] = 1;
    idx = 2;
}

// 在下标k节点的右边插入x
void add_r(int k, int x)
{
    e[idx] = x; // 存储x
    l[idx] = k, r[idx] = r[k];// x节点的左右指针
    r[l[idx]] = idx;// 旧节点的指针
    l[r[idx]] = idx;
    idx++;
}

// 在下标k节点的左边插入x
void add_l(int k, int x)
{
    add_r(l[k], x);
}

// 删除下标为k的节点
void remove(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main()
{
    int m;
    scanf("%d",&m);

    init();

    while(m--)
    {
        string Oper;
        cin >> Oper;

        if (Oper == "L")// 在最左端插入x
        {
            int x;
            scanf("%d", &x);
            add_r(0, x);
        }
        else if (Oper == "R")// 在最右端插入x
        {
            int x;
            scanf("%d", &x);
            add_l(1, x);
        }
        else if (Oper == "D") // 将第k个插入的数删除。
        {
            int k;
            scanf("%d", &k);
            remove(k+1);
        }
        else if(Oper == "IL")// 在第k个插入的数左侧插入一个数。
        {
            int k, x;
            scanf("%d%d", &k, &x);
            add_l(k+1, x);
        }
        else if(Oper == "IR")// 在第k个插入的数右侧插入一个数。
        {
            int k, x;
            scanf("%d%d", &k, &x);
            add_r(k+1, x);
        }
    }
    
    for (int i=r[0] ; i!=1 ; i=r[i])
        printf("%d ",e[i]);

    return 0;
}