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

struct Point {
    int x,y;
    double disT;
    double disA;
    double disB;
};
bool cmp(Point a, Point b) {
    return a.disT > b.disT;
}


int main() {
//    char str[Maxn];
//    int num[Maxn];
#ifndef ONLINE_JUDGE
    freopen("D://Desktop//ACM//input.txt","r",stdin);
#endif
    int T;
    ll ax,ay,bx,by,tx,ty;
    while(~scanf("%lld%lld%lld%lld%lld%lld",&ax,&ay,&bx,&by,&tx,&ty)) {
        Point p[Maxn];
        scanf("%d",&n);
        int sum = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d%d",&p[i].x,&p[i].y);
            p[i].disT = sqrt((p[i].x-tx)*(p[i].x-tx) + (p[i].y-ty)*(p[i].y-ty));
            p[i].disA = sqrt((p[i].x-ax)*(p[i].x-ax) + (p[i].y-ay)*(p[i].y-ay));
            p[i].disB = sqrt((p[i].x-bx)*(p[i].x-bx) + (p[i].y-by)*(p[i].y-by));
            sum += p[i].disT;
        }
        int flag1 = 0,flag2 = 0;
        for(int i = 0; i < n; i++) {
            sum += min()
        }
    }
return 0;
}





