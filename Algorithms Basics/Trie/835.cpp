// 题目描述
// 维护一个字符串集合，支持两种操作：
// I x 向集合中插入一个字符串 x；
// Q x 询问一个字符串在集合中出现了多少次。
// 共有 N 个操作，输入的字符串总长度不超过 10^5，字符串仅包含小写英文字母。

// 输入格式
// 第一行包含整数 N，表示操作数。
// 接下来 N 行，每行包含一个操作指令，指令为 I x 或 Q x 中的一种。

// 输出格式
// 对于每个询问指令 Q x，都要输出一个整数作为结果，表示 x 在集合中出现的次数。
// 每个结果占一行。

// 输入输出样例
// 输入
// 5
// I abc
// Q abc
// Q ab
// I ab
// Q ab
// 输出
// 1
// 0
// 1
// 说明/提示
// 数据范围：1≤N≤2∗10^4

#include <iostream>

using namespace std;

const int N=1e5+10;
const int C=2e4+10;

int son[N][26]; //字符串总长度最多N,只有26种字符.下标为0的点既是根结点,也是空结点
int cnt[C];//结点的单词数
int idx;//当前用到的节点
char str[N];

void insert(char str[])
{
    int p=0;
    for (int i=0 ; str[i] ; i++)
    {
        int u = str[i]-'a';
        if (!son[p][u]) // 如果不存在子节点
            son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(char str[])
{
    int p = 0;
    for (int i=0 ; str[i] ; i++)
    {
        int u = str[i]-'a';
        if(son[p][u])
            p = son[p][u];
        else
            return 0;
    }
    return cnt[p];
}

int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        char Oper[2];
        scanf("%s%s", &Oper, &str);
        if (Oper[0] == 'I')//插入
        {
            insert(str);
        }
        else//查询
        {
            int q = query(str);
            printf("%d\n", q);
        }
    }

    return 0;
}