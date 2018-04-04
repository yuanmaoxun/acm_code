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

#define Maxn 105
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
#define Clear(name, num) memset(name, num, sizeof(name));
using namespace std;
typedef struct {
    int u;
    int v;
    int w;
}edge;
edge edges[Maxm];
int father[Maxn];
int i,j;
bool cmp(edge a, edge b) {
    return a.w < b.w;
}

int find_set(int n) {
    return father[n] == n?n:father[n] = find_set(father[n]);
}
void Kruskal (int len) {
    int sum = 0;
    for(int i = 0; i < len; i++) {
        int x = find_set(edges[i].u);
        int y = find_set(edges[i].v);
        if(x!=y) {
            sum += edges[i].w;
            father[y]=x;
        }
    }
    cout << sum <<endl;
}

int main(){
    int i, t, j, k, m, n;
    int res, sum, ans, key, len;
    int year, mon, day;
//    char str[Maxn];
    int num[Maxn][Maxn];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int u,v,w;
    while(~scanf("%d",&n)) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                cin >> num[i][j];
            }
        }
        k = 0;
        for(i = 1; i <= n; i++)
            father[i] = i;
        for(i = 0; i < n; i++) {
            for(j = i+1; j < n; j++) {
                edges[k].u = i+1;
                edges[k].v = j+1;
                edges[k].w = num[i][j];
                k++;
            }

        }
        sort(edges,edges+k,cmp);
        Kruskal(k);
    }
return 0;
}





