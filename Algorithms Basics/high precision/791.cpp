// 给定两个正整数（不含前导 0 ），计算它们的和。

// 输入格式
// 共两行，每行包含一个整数。

// 输出格式
// 共一行，包含所求的和。

// 1≤整数长度≤100000


#include <iostream>
#include <vector>

using namespace std;


//C = A+B
vector<int> add(vector<int> &A, vector<int> &B)//传入引用（指针）避免复制，提高效率
{
    vector<int> C;

    int t = 0;
    for (int i = 0 ; i < A.size() || i < B.size() ; i++)
    {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t%10);
        t = t/10; //t整除10的商
    }
    if (t>0)
    {
        C.push_back(t);
    }
    return C;

}

int main()
{
    string a, b;//位数太大用string读取
    vector<int> A, B;//vector有size方法直接获取长度

    cin >> a >> b;

    //逆序存入vector
    for (int i = a.size()-1 ; i>=0 ; i--)
    {
        A.push_back(a[i]-'0');
    }
    for (int i = b.size()-1 ; i>=0 ; i--)
    {
        B.push_back(b[i]-'0');
    }

    auto C = add(A, B);

    //逆序输出结果
    for (int i = C.size()-1; i>=0 ; i--)
    {
        printf("%d",C[i]);
    }
    return 0;
}