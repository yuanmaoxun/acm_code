//kengkeng
#include <ios>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <cstdio>
#include <cwchar>
#include <iosfwd>
#include <limits>
#include <locale>
#include <memory>
#include <string>
#include <vector>
#include <cassert>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <cwctype>
#include <fstream>
#include <iomanip>
#include <istream>
#include <numeric>
#include <ostream>
#include <sstream>
#include <utility>
#include <iostream>
#include <iterator>
#include <valarray>
#include <algorithm>
#include <exception>
#include <stdexcept>
#include <streambuf>
#include <functional>
#define Maxn 205
#define Maxm 500
#define INF 0xffff;
#define ll long long
#define Mod 1000000007
#define PI  3.1415926535898
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1|1
#define debug puts("here is a BUG");
#define Clear(name, num) memset(name, num, sizeof(name));
using namespace std;

int num[Maxm];
int flag[Maxn];
int n, a, b;
int ans;

void bfs(int a, int e) {
    queue<int> q;
    q.push(a);
    int temp;
    flag[a] = 1;
    while(!q.empty()) {
         temp = q.front();
        q.pop();
        if(temp == e)
            break;
        int next = temp + num[temp];
        if(next >= 1 && next <= n && !flag[next]) {
            q.push(next);
            flag[next] = flag[temp] + 1;
            //cout <<ans <<endl;
        }
        next = temp - num[temp];
        if(next >=1 && next <= n && !flag[next]) {
            q.push(next);
            flag[next] = flag[temp] + 1;
            //cout <<ans <<endl;
        }
    }
    if(temp != e)
        flag[e] = 0;
}

int main(){
    int i, t, j, k, m;
    int res, sum, key, len;
    int year, mon, day;
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    while(~scanf("%d%d%d",&n, &a, &b)){
        if(n == 0) break;
        for(i = 1; i <= n; i++)
            cin >> num[i];
        Clear(flag, 0);
        bfs(a, b);
        cout <<flag[b] - 1 <<endl;
    }
return 0;
}





