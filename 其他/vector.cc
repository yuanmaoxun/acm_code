#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int>  laotou;        // 动态长度数组；
    laotou.push_back(1);
    laotou.push_back(5);
    laotou.push_back(3);    //压入元素；
     cout << laotou[1];      //
     laotou.erase(1,3);      //删除元素左臂右开
     laotou.pop_back();      //删除末尾
     laotou.clear();             //清空
     laotou.at(1);            //访问元素  检测越界  建议
     laotou.begin();          //第一个元素的位置
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
