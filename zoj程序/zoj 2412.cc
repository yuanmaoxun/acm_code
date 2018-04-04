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
#define Maxn 55
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

int farm[11][4] = { {0,0,1,1}, {1,0,0,1}, {0,1,1,0}, {1,1,0,0} ,   // ÉÏÏÂ×óÓÒ
                    {0,1,0,1}, {1,0,1,0}, {1,0,1,1}, {0,1,1,1},
                    {1,1,1,0}, {1,1,0,1}, {1,1,1,1} };
int dir[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

bool vis[Maxn][Maxn];
char str[Maxn][Maxn];
int n, m;
void dfs(int x, int y, int id) {
    vis[x][y] = true;
    for(int i = 0; i < 4; i++)
        if(farm[id][i]) {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            char k = str[xx][yy] - 'A';
            if(xx >= 0 && yy >= 0 && xx < m && yy < n && !vis[xx][yy] && farm[k][(i + 2) % 4])
                dfs(xx, yy, k);
        }
}

int main(){
    int i, t, j, k;
    int res, sum, ans, key, len;
    int year, mon, day;
    int num[Maxm];
    int score[Maxn][Maxn];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    while(~scanf("%d%d", &m, &n)) {
        if(n < 0 || m < 0)
        break;
        ans = 0;
        Clear(vis, false);
        for(i = 0; i < m; i++)
            scanf("%s", str[i]);
        /*for(i = 0; i < m; i ++)
            puts(str[i]);*/
        for(i = 0; i < m; i++)
            for(j = 0; j < n; j++)
                if(!vis[i][j]) {
                    dfs(i, j, str[i][j] - 'A');
                    ans++;
                }
        cout << ans << endl;
    }
return 0;
}




