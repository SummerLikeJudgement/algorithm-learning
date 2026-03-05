// 给定两个正整数（不含前导 0），计算它们的差，计算结果可能为负数。

// 输入格式:
// 共两行，每行包含一个整数。

// 输出格式:
// 共一行，包含所求的差。

// 数据范围:
// 1 ≤ 整数长度 ≤ 10^5

// 输入样例：

// 32
// 11

// 输出样例：

// 21


#include <iostream>
#include <vector>

using namespace std;

// A>=B
bool cmp(vector<int> &A, vector<int> &B)
{
    if (A.size() != B.size()) return A.size()>B.size();
    else
    {
        for (int i = A.size()-1 ; i>=0 ; i--)
        {
            if (A[i]!=B[i]) return A[i]>B[i];
        }
        return true;
    }
}

//C = A-B (A>=B)
vector<int> sub(vector<int> &A, vector<int> &B)//传入引用（指针）避免复制，提高效率
{
    vector<int> C;

    for (int i = 0, t = 0 ; i < A.size() ; i++)
    {
        t = A[i] - t;
        if (i < B.size()) t -=B [i];
        C.push_back((t+10)%10);
        if (t<0) t=1;
        else t=0;
    }
    //删除高位的0
    while(C.size()>1 || C.back() == 0)
    {
        C.pop_back();
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

    if (cmp(A,B)) //A>B
    {
        auto C = sub(A, B);
        //逆序输出结果
        for (int i = C.size()-1; i>=0 ; i--)
        {
            printf("%d",C[i]);
        }
    }
    else
    {
        auto C = sub(B, A);
        //逆序输出结果
        for (int i = C.size()-1; i>=0 ; i--)
        {
            printf("%d",C[i]);
        }
    }


    return 0;
}