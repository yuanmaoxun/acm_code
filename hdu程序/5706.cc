// 5706.cpp
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
#define what_is(x) cout << #x << " is " << x << endl;
#define CLEAR(name, init) memset(name, init, sizeof(name));
const double eps = 1e-8;
const int MAXN = 1000 + 5;
using namespace std;

bool vis [MAXN][MAXN];
char str[MAXN][MAXN];
int dir[4][2] = { 1,0,-1,0,0,1,0,-1};
int n,m;
int ans;
void dfs1(int x,int y) {
	for (int i = 0; i < 4; ++i) {
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];
		if (xx >= n || yy >= m || xx < 0 || yy < 0) {
			continue;
		}
		if (str[x][y]=='g'&&str[xx][yy] == 'i' || (str[x][y] == 'i' && str[xx][yy] == 'r') ) {
			dfs1(xx,yy);
		}
		if (str[x][y] == 'r' && str[xx][yy] == 'l') {
			ans++;
		}
	}
}

void dfs2(int x,int y) {
    for (int i = 0; i < 4; ++i) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx >= n || yy >= m || xx < 0 || yy < 0) {
            continue;
        }
        if ((str[x][y] == 'c' && str[xx][yy] == 'a') ) {
            dfs2(xx,yy);
        }
        if (str[x][y] == 'a' && str[xx][yy] == 't') {
            ans++;
        }
    }
}


int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    int T;
    int res1,res2;
    while(~scanf("%d",&T)) {
    	while(T--) {
            scanf("%d%d",&n,&m);
            res1 = 0;
            res2 = 0;
            for (int i = 0; i < n; ++i) {
                scanf("%s",str[i]);
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (str[i][j] == 'g') {
                        ans = 0;
                        dfs1(i,j);
                        res1 += ans;
                    }
                    if (str[i][j] == 'c') {
                        ans = 0;
                        dfs2(i,j);
                        res2 += ans;
                    }
                }
            }
            printf("%d %d\n",res1,res2 );
        }
    }
    return 0;
}