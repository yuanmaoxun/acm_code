#include <bits/stdc++.h>
    laotou.top();            //返回栈顶元素     queue front  queue 解决广搜；
    laotou.push(1);            //压进元素
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
    stack<int> laotou,gaoxiang;  //存放数据类型  记住一定<>  无清空操作  // 解决深搜
    while(!(laotou.empty()))
        laotou.pop();              //清除栈顶元素
        gaoxiang.pop();

    while(!laotou.empty()) {
        cout << laotou.top();
        laotou.pop();
    }
    return 0;
}
