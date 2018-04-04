
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

int dir[8][2] = { {-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};

int main(){
    int i, t, j, k, m, n;
    int res, sum, ans, key, len;
    int year, mon, day;
    char str[Maxn][Maxn];
//    int num[Maxn];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE

    while(~scanf("%d %d",&n, &m)) {
        for(i = 0; i < n; i++) {
            scanf("%s",str[i]);
        }
        int x,y;
        int Count;
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                x = i; y = j;
                Count = 0;
                if(str[i][j] == '*') {
                    continue;
                }
                for(k = 0; k < 8; k++) {
                    int xx = x + dir[k][0];
                    int yy = y + dir[k][1];
                    if(xx < 0|| yy < 0 || xx>=n ||yy >= m)
                        continue;
                    if(str[xx][yy] == '*') {
                        Count++;
                    }
                }
                str[i][j] = Count+'0';
            }
        }
        for(i = 0; i < n; i++)
            for(j = 0; j < m; j++){
                putchar(str[i][j]);
                if(j == m-1)
                    puts("");
            }
    }
return 0;
}




