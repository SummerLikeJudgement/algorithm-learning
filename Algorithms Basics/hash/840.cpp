// 题目描述
// 维护一个集合，支持如下几种操作：
// I x，插入一个数 x；
// Q x，询问数 x 是否在集合中出现过；
// 现在要进行 N 次操作，对于每个询问操作输出对应的结果。

// 输入格式
// 第一行包含整数 N，表示操作数量。
// 接下来 N 行，每行包含一个操作指令，操作指令为 I x，Q x 中的一种。

// 输出格式
// 对于每个询问指令 Q x，输出一个询问结果，如果 x 在集合中出现过，则输出 Yes，否则输出 No。
// 每个结果占一行。

// 输入输出样例
// 输入
// 5
// I 1
// I 2
// I 3
// Q 2
// Q 5

// 输出
// Yes
// No

// 说明/提示
// 1≤N≤10^5
// −10^9≤x≤10^9

//// 拉链法
// #include <iostream>
// #include <cstring>

// using namespace std;

// const int N = 100003; // 最好用质数（编程遍历求）

// int h[N];// hash数组，每个位置相当于head头指针，指向链表中第一个节点
// int e[N], ne[N], idx;// 用一个链表存储所有hash的N条链

// void insert(int x)
// {
//     int k = (x % N + N) % N; // 确保k是正数
//     //将x插入链表中
//     e[idx] = x;
//     ne[idx] = h[k];
//     h[k] = idx++;
// }

// bool find(int x)
// {
//     int k = (x % N + N) % N; // 确保k是正数

//     for (int i=h[k] ; i!=-1 ; i=ne[i])
//         if(e[i] == x) return true;
//     return false;
// }

// int main()
// {
//     int n;
//     scanf("%d", &n);

//     memset(h, -1, sizeof h); //将h清空，全部置为-1

//     while(n--)
//     {
//         int x;
//         char Op[3];
//         scanf("%s%d", Op, &x);
//         if (Op[0] == 'I') // 插入
//             insert(x);
//         else
//         {
//             if (find(x)) printf("Yes\n");
//             else printf("No\n");
//         }
//     }

//     return 0;

// }

#include <iostream>
#include <cstring>

using namespace std;

const int N = 200003; // 最好用质数（编程遍历求）
const int null = 0x3f3f3f3f; // 约定一个数表示空

int h[N];// hash数组

// 如果x在hash中，返回位置；如果x不在hash中，返回应该存的位置
int find(int x)
{
    int k = (x % N + N) % N; // 确保k是正数

    while(h[k]!=null && h[k]!=x)
    {
        k++;
        if (k == N) 
            k=0;
    }
    return k;

}

int main()
{
    int n;
    scanf("%d", &n);

    memset(h, 0x3f, sizeof h); // memset 是按字节设置的，不是按 int 设置的！

    while(n--)
    {
        int x;
        char Op[3];
        scanf("%s%d", Op, &x);

        int k = find(x);
        if (Op[0] == 'I') // 插入
            h[k] = x;
        else
        {
            if (h[k]!=null) printf("Yes\n");
            else printf("No\n");
        }
    }

    return 0;

}

