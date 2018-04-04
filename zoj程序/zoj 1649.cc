
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
#define Exit exit(0);
#define Mod 1000000007
#define PI  3.1415926535898
#define Pause system("pause");
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1|1
#define debug puts("here is a BUG");
#define Clear(name, num) memset(name, num, sizeof(name));
using namespace std;

struct Point {
    int x;
    int y;
    int time;
};
int n, m;
int sx, sy, dx, dy;
char str[Maxn][Maxn];
int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int mintime[Maxn][Maxn];

int bfs (Point s) {
    int i;
    queue<Point> q;
    q.push(s);
    Point hd;
    while(!q.empty()) {
        hd = q.front();
        q.pop();
        for(i = 0; i < 4; i++) {
            int xx = hd.x + dir[i][0];
            int yy = hd.y + dir[i][1];
            if(xx >= 0 && xx < n && yy >= 0 && yy < m && str[xx][yy] != '#') {
                Point next;
                next.x = xx;
                next.y = yy;
                next.time = hd.time + 1;
                if(str[xx][yy] == 'x')
                    next.time++;
                if(next.time < mintime[xx][yy]){
                    mintime[xx][yy] = next.time;
                    q.push(next);
                }
            }
        }
    }
    return mintime[dx][dy];
}
int main(){
    int i, t, j, k;
    int res, sum, ans, key, len;
    int year, mon, day;
    int num[Maxm];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    while(~scanf("%d%d", &n, &m)) {
        for(i = 0; i < n; i++)
            scanf("%s", str[i]);
        for(i = 0; i < n; i++)
        for(j = 0; j < m; j++) {
            if(str[i][j] == 'r')
                sx = i, sy = j;
            if(str[i][j] == 'a')
                dx = i, dy = j;
            mintime[i][j] = 100000;
        }
        Point start;
        start.x = sx;
        start.y = sy;
        start.time = 0;
        mintime[sx][sy] = 0;
        int mint = bfs(start);
        if(mint < 100000) {
            cout << mint << endl;
        }
        else {
            cout << "Poor ANGEL has to stay in the prison all his life." << endl;
        }
    }
return 0;
}

