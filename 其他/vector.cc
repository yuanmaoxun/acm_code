#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int>  laotou;        // ��̬�������飻
    laotou.push_back(1);
    laotou.push_back(5);
    laotou.push_back(3);    //ѹ��Ԫ�أ�
     cout << laotou[1];      //
     laotou.erase(1,3);      //ɾ��Ԫ������ҿ�
     laotou.pop_back();      //ɾ��ĩβ
     laotou.clear();             //���
     laotou.at(1);            //����Ԫ��  ���Խ��  ����
     laotou.begin();          //��һ��Ԫ�ص�λ��
     laotou.end();
    vector<int>::iterator it = laotou.begin();
    it++;
    *it;
    int len_lt = laotou.size();
    for(it = laotou.begin(); it != laotou.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}
