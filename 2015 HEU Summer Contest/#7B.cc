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
#define Maxn 100005
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

int d, n, top, res;

struct Edge {
    int u;
    int v;
    int next;
    int step;
}edge[Maxn];

struct Tnode {
    int head;
}Head[Maxn];

void add_edge(int u, int v) {   //按出度添加边
    edge[top].v = v;
    edge[top].next = Head[u].head;
    Head[u].head = top++;
}

void dfs (int root, int step) {
    int k;
    if (Head[root].head == -1)
        return;
    k = Head[root].head;
    while(k != -1) {
        int temp = edge[k].v;
        edge[k].step = step + 1;
        if(edge[k].step > d)
            res ++;
        dfs(temp, edge[k].step);
        k = edge[k].next;
    }
}

int main(){
    int i, t, j, k, m, x, y;
    int sum, ans, key, len;
    int year, mon, day;
    char str[Maxn];
    int num[Maxm];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    while(~scanf("%d",&t)) {
        while(t--) {
            scanf("%d%d",&n,&d);
            top = res = 0;
            Clear(Head, -1);
            Clear(edge, 0);
            for(i = 1; i < n; i++) {
                scanf("%d%d",&x,&y);
                add_edge(x, y);
                }
            dfs(0, 0);
            /*for(i = 0; i < n; i++)
                cout << edge[i].step <<endl;
                */
            cout << res << endl;
        }
    }
return 0;
}





