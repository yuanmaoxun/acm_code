#include <iostream>
using namespace std;
static int digit = 1;     //数字的位数
class Node
{
public:
    Node()
    {
        for(int i = 0;i < 500;i++)
        {
            value[i] = 0;
        }
    }
    int value[500];      //存储数据
    friend Node operator + (const Node& a,const Node& b); //友元函数实现两个Node类型的数据加法
};

/*
重载+操作符，实现两个Node类型的数据进行加法运算
*/
Node operator+ (const Node& a,const Node& b)
{
    Node temp;  //临时数据
    int i;
    for(i = 1;i <= digit;i++)
    {
        temp.value[i] = a.value[i] + b.value[i];
    }

    for(i = 1;i < digit;i++)  //进位处理
    {
        if(temp.value[i] >= 10)
        {
            temp.value[i+1] += temp.value[i]/10;
            temp.value[i] %= 10;
        }
    }

    if(temp.value[digit] >= 10)  //判断是否这个大数又进行了进位
    {
        temp.value[digit+1] = temp.value[digit]/10;
        temp.value[digit] %= 10;
        ++digit; //最高位大于10，就进位
    }
    return temp;
}


int main()
{
    int N;
    while(cin>>N) {
    digit = 1;
    Node a,b,c;
    a.value[1] = 1;
    b.value[1] = 1;
    c.value[1] = 1;
    for(int i = 2; i <= N;i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    if(N==0) cout<<endl;
    else{
    for(int i = digit;i >= 1;i--)
    {
        cout<<c.value[i];
    }
    cout<<endl;
    }
    }
    return 0;
}
