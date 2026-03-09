// 题目描述
// 给定两个非负整数（不含前导 0 ） A，B ，请你计算 A/B 的商和余数。

// 输入格式
// 共两行，第一行包含整数 A ，第二行包含整数 B 。

// 输出格式
// 共两行，第一行输出所求的商，第二行输出所求余数。

// 输入输出样例
// 输入

// 7
// 2
// 输出

// 3
// 1

// 说明/提示
// 1≤A的长度≤100000,1≤B≤10000,B一定不为0

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// A/B = C ... D
vector<int> div(vector<int> &A, int B, int &D)
{
    vector<int> C;
    
    int t = 0;
    for (int i = A.size()-1 ; i>=0 ; i--)
    {
        t = t*10 + A[i];
        C.push_back(t/B);
        t = t % B;
    }

    reverse(C.begin(), C.end()); // 反转vector，确保逆序 
    // 去掉前导零
    for (int i = C.size()-1 ; i > 0 && C[i] == 0 ; i--)
    {
        C.pop_back();
    }
    // while(C.size()>1 && C.back()==0) C.pop_back(); // 去掉前导零另一方法

    D = t;

    return C;
}

int main()
{
    string a;
    int B;

    cin >> a >> B;

    vector<int> A;
    //逆序存入A(为了和其他运算统一，依然逆序存)
    for (int i = a.size() - 1 ; i>=0 ; i--)
    {
        A.push_back(a[i]-'0');
    }

    int D;
    
    auto C = div(A, B, D);

    for (int i = C.size()-1 ; i>=0 ; i--)
    {
        printf("%d", C[i]);
    }
    printf("\n%d",D);

    return 0;
}