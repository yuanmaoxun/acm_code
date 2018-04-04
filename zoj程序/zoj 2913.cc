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
#define Maxm 500
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
int nz, nr;
int mz[Maxn];
int edge[Maxn][10];
int res[Maxn];
int cur;
int reach[Maxn];

void bfs(int s) {
    int i, a, b;
    int val, at;
    queue<int> q[2];
    a = 0, b = 1, val = 0;
    if(reach[s] < cur) {
        q[b].push(s);
        reach[s] = cur;
        res[s] = max(res[s], val+1);
    }
    while(!q[b].empty()) {
        swap(a, b);
        val++;
        while(!q[a].empty()) {
            at = q[a].front();
            q[a].pop();
            for(i = 0; i < mz[at]; i++) {
                if(reach[edge[at][i]] < cur) {
                    q[b].push(edge[at][i]);
                    reach[edge[at][i]] = cur;
                    res[edge[at][i] ]= max(res[ edge[at][i] ], val + 1);
                }
            }
        }
    }
}

int main() {
    int i, t, j, k, m, n;
    int  sum, ans, key, len;
    int year, mon, day;
    char str[Maxn];
    int num[Maxm];
    int score[Maxn][Maxn];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt", "r", stdin);
#endif // ONLINE_JUDGE
    int id, mr, ret, center;
    while(~scanf("%d", &t)) {
        while(t--) {
            Clear(reach, -1);
            Clear(res, 0);
            cur = 0;
            scanf("%d%d", &nz, &nr);
            for(i = 0; i < nz; i++) {
                cin >> id;
                cin >> mz[id];
                for(j = 0; j < mz[id]; j++)
                    cin >> edge[id][j];
            }
            for(i = 0; i < nr; i++) {
                cin >> mr;
                for(j = 0; j < mr; j++) {
                    cin >> id;
                    bfs (id);
                    cur++;
                }
            }
            ret = INT_MAX;
            center = -1;
            for(i = 0; i < 10000; i++) {
                if (reach[i] == cur-1 && res[i] < ret ) {
                    ret = res[i] ;
                    center = i;
                }
            }
            cout << ret << " " << center << endl;
        }
    }
    return 0;
}





