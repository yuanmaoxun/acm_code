#include <iostream>
using namespace std;
static int digit = 1;     //���ֵ�λ��
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
    int value[500];      //�洢����
    friend Node operator + (const Node& a,const Node& b); //��Ԫ����ʵ������Node���͵����ݼӷ�
};

/*
����+��������ʵ������Node���͵����ݽ��мӷ�����
*/
Node operator+ (const Node& a,const Node& b)
{
    Node temp;  //��ʱ����
    int i;
    for(i = 1;i <= digit;i++)
    {
        temp.value[i] = a.value[i] + b.value[i];
    }

    for(i = 1;i < digit;i++)  //��λ����
    {
        if(temp.value[i] >= 10)
        {
            temp.value[i+1] += temp.value[i]/10;
            temp.value[i] %= 10;
        }
    }

    if(temp.value[digit] >= 10)  //�ж��Ƿ���������ֽ����˽�λ
    {
        temp.value[digit+1] = temp.value[digit]/10;
        temp.value[digit] %= 10;
        ++digit; //���λ����10���ͽ�λ
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
