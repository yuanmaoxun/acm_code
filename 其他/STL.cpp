#include <bits/stdc++.h>
    laotou.top();            //����ջ��Ԫ��     queue front  queue ������ѣ�
    laotou.push(1);            //ѹ��Ԫ��
    laotou.push(4);
    laotou.push(3);
    laotou.push(8);
    laotou.push(5);
    laotou.push(6);
    int t=laotou.size();
    for(int i = 1;i <= t;i++) {
        cout << laotou.top() << " ";
        gaoxiang.push(laotou.top());
        laotou.pop();
    }
    for(int i = 1;i<=t;i++) {
        laotou.push(gaoxiang.top());
using namespace std;
int main()  {
    stack<int> laotou,gaoxiang;  //�����������  ��סһ��<>  ����ղ���  // �������
    while(!(laotou.empty()))
        laotou.pop();              //���ջ��Ԫ��
        gaoxiang.pop();

    while(!laotou.empty()) {
        cout << laotou.top();
        laotou.pop();
    }
    return 0;
}
