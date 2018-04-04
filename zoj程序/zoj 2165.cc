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
#define Maxn 25
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

char str[Maxn][Maxn];
int sx, sy, ans, h, w;
int score[Maxn][Maxn];
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
bool vis[Maxn][Maxn];

void dfs(int x, int y) {
    vis[x][y] = true;
    for(int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if(xx < 0 || yy < 0 || xx >= h || yy >= w || vis[xx][yy] || str[xx][yy] == '#')
            continue;
        dfs(xx, yy);
        ans++;
    }
}

int main(){
    int i, t, j, k, m, n;
    int res, sum, key, len;
    int year, mon, day;

    int num[Maxm];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    while(~scanf("%d%d", & w, &h)){
            if(w == 0 && h == 0)
            break;
        for(i = 0; i < h; i++)
            scanf("%s", str[i]);
        for(i = 0; i < h; i++)
            for(j = 0; j < w; j++)
                if(str[i][j] == '@') {
                    sx = i;
                    sy = j;
                }
        Clear(vis, false);
        ans = 1;
        dfs(sx, sy);
        /*for(i = 0; i < h; i++){
            for(j = 0; j < w; j++)
                cout << str[i][j] << " " ;
            puts("");
        }*/
        /*for(i = 0; i < h; i++){
            for(j = 0; j < w; j++)
                cout << vis[i][j] << " " ;
            puts("");
        }*/
        cout <<ans <<endl;
    }
return 0;
}





