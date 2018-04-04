#include <bits/stdc++.h>
using namespace std;
const string month[13] = {"January", "February", "March"};
const int days[13] = {31, 28, 31};
int main() {
    /*map<string, vector<int> > m;    // 第一个
    for(int i = 0; i < 3; i++) {
        m[month[i]] = days[i];
    }
    if (m.find("January") != m.end())
    cout << m["January"] << endl;
    map<string, vector<int> >::iterator it;
    for(it = m.begin(); it != m.end(); it++) {    只能it++  不能it——；
        it->first it->second
    }*/
    int a[3] = {2, 1, 3};
    sort(a, a + 3);
    do {
        for(int i = 0; i < 3; i++) {
            cout << a[i] << " \n"[i == 2];
        }
    }while(next_permutation(a, a + 3));
    int x = 1, y = 2;
    swap(x, y);
    res = max(res, maxn);
    return 0;
}
