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

#define Maxn 1005
#define Maxm 5005
#define INF 0xffff;
#define ll long long
#define Exit exit(0);
#define Mod 1000000007
#define PI  3.1415926535898
#define Pause system("pause");
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1|1
#define debug puts("here is a BUG");
#define Clear(name, num) memset(name, num, sizeof(name))
using namespace std;

int father[Maxn];
vector<pair<int,int> > edges;
int n,m;
int find_set(int n) {

    return father[n] == n?n:father[n] = find_set(father[n]);
}

bool isConnected(int x,int y) {  //nÎªµãÊý
    for(int i = 0; i < n; i++)
        father[i] = i;
    for(int i = 0; i < m; i++) {
        if(i == x || i == y)
            continue;
        int u = edges[i].first;
        int v = edges[i].second;
        u = find_set(u);
        v = find_set(v);
        if(u!=v)
            father[u] = v;
    }
    int res = 0;
    bool root[Maxn];
    Clear(root,false);
    for(int i = 0; i < n; i++) {
        int r = find_set(i);
        if (!root[r]) {
            res++;
            root[r] = true;
        }
    }
    return res == 1;
}

int main(){
    //char str[Maxn];
    //int num[Maxm];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int u, v,w;
    int T;
    while(~scanf("%d", &T)) {
        while(T--) {
            edges.clear();
            scanf("%d",&n);
            m = n+1;
            for(int i = 0; i < m; i++) {
                scanf("%d%d",&u,&v);
                u--;v--;
                edges.push_back(make_pair(u,v));
            }
            int ans = 0;
            for(int i = 0; i < m ; i++) {
                for(int j = 0; j < i; j++) {
                    if(isConnected(i,j))
                        ans++;
                }
            }
            for(int i = 0; i < m; i++) {
                if (isConnected(i, i)) {
                    ans++;
                }
            }
            printf("%d\n",ans);
        }
    }
return 0;
}
