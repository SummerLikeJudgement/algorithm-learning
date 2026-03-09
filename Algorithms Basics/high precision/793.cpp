// 输入格式
// 两个正整数 a,b（第二个可能比第一个大）。

// 输出格式
// 结果。

// 输入输出样例
// 输入
// 2
// 3

// 输出
// 6

// 说明/提示
// 1≤A的长度≤100000 , 0≤B≤10000

#include <iostream>
#include <vector>

using namespace std;

//A*B(A很大，B较小)
vector<int> mul(vector<int> &A, int B)
{
    vector<int> C;

    int t=0;
    for (int i = 0; i < A.size() || t; i++)
    {
        if (i < A.size()) t += A[i]*B;
        C.push_back(t % 10);
        t /= 10;
    }

    return C;
}

int main()
{
    string a;
    int B;
    cin >> a >> B;

    vector<int> A;
    // 逆序存入向量
    for (int i = a.size()-1 ; i>=0 ; i--)
    {
        A.push_back(a[i]-'0');
    }

    vector<int> C;
    
    C = mul(A, B);

    for (int i = C.size() - 1 ; i >= 0 ; i--)
    {
        printf("%d", C[i]);
    }

    return 0;
}