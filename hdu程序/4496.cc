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
#define Maxm 5005
#define INF 0x7fffffff
#define ll long long
#define Exit exit(0);
#define Mod 1000000007
#define PI  3.1415926535898
#define Pause system("pause");
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1|1
#define debug puts("here is a BUG");
#define Clear(name, num) memset(name, num, sizeof(name));

using namespace std;

int father[Maxn];
vector<pair<int,int> > edges;
int res[Maxn];
bool sum[Maxn];
int n,m;
int Count;

int find_set(int n) {
    return father[n] == n ? n:father[n] = find_set(father[n]);
}

void isConnected() {
    for(int i = 0; i < n; i++) {
        father[i] = i;
    }
    int i;
    res[m-1] = n;
    for(i = m-1; i > 0; i--) {
        int u = edges[i].first;
        int v = edges[i].second;

        u = find_set(u);
        v = find_set(v);
        if(u != v) {
            father[u] = v;
            res[i-1] = res[i]-1;
        }
        else {
            res[i-1] = res[i];
        }
    }
}

int main() {
//    char str[Maxn];
//    int num[Maxn];
#ifndef ONLINE_JUDGE
    freopen("D://Desktop//ACM//input.txt","r",stdin);
#endif
    int T;
    while(~scanf("%d %d",&n,&m)) {
        edges.clear();
        int u,v;
        for(int i = 0; i < m; i++) {
            scanf("%d%d",&u,&v);
            edges.push_back(make_pair(u,v));
        }
        isConnected();
        for(int i = 0; i < m; i++) {
            printf("%d\n",res[i]);
        }
    }
return 0;
}





