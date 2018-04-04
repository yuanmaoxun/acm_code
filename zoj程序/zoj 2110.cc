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
#define LL long long
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
#define PI 3.1415926535897932626
#define EXIT exit(0);
#define PAUSE system("pause");
#define DEBUG puts("Here is a BUG");
#define SYNC_CLOSE ios::sync_with_stdio(false);
#define what_is(x) cerr << #x << " is " << x << endl;
#define CLEAR(name, init) memset(name, init, sizeof(name));
const double eps = 1e-8;
const int MAXN = (int)1e1 + 5;
using namespace std;

int dx, dy;
int n, m, t;
bool isescape;
bool vis[MAXN][MAXN];
char maze[MAXN][MAXN];
const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int x, int y, int cur) {
    if (cur > t || isescape) return ;
    if (x == dx && y == dy) {
        isescape = cur == t;
        return ;
    }
    int tt = (t - cur) - (abs(x - dx) + abs(y - dy));
    if (tt < 0 || tt & 1) return ;
    for(int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx < 0 || xx >= n || yy < 0 || yy >= m || maze[xx][yy] == 'X' || vis[xx][yy]) continue;
        vis[xx][yy] = true;
        dfs(xx, yy, cur + 1);
        if (isescape) return ;
        vis[xx][yy] = false;
    }
}
int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    while(cin >> n >> m >> t) {
        if (n == 0 && m == 0 && t == 0) break;
        int cnt = 0;
        CLEAR(vis, 0);
        isescape = false;
        int sx, sy;
        for(int i = 0; i < n; i++) {
            cin >> maze[i];
            for(int j = 0; maze[i][j]; j++) {
                if (maze[i][j] == 'S') { sx = i; sy = j; }
                if (maze[i][j] == 'D') { dx = i; dy = j; }
                if (maze[i][j] == 'X') cnt++;
            }
        }
        if (n*m - cnt < t) { puts("NO"); continue; }
        vis[sx][sy] = true;
        dfs(sx, sy, 0);
        if (isescape) puts("YES");
        else puts("NO");
    }
    return 0;
}
