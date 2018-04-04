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
};

bool judge (Point n,Point m) {
    if(n.x * m.y - m.x*n.y > 0){
        return true;
    }
    else
        return false;

}

int main() {
//    char str[Maxn];
//    int num[Maxn];
#ifndef ONLINE_JUDGE
    freopen("D://Desktop//ACM//input.txt","r",stdin);
#endif
    int n,i;
    Point p[Maxn];
    while(~scanf("%d",&n)) {
        for(int i = 0; i <= n; i++) {
            scanf("%d %d",&p[i].x,&p[i].y);
        }
        Point Dot[Maxn];
        int k = 0;
        for(i = 0; i < n; i++) {
            Dot[k].x = p[i].x - p[i+1].x;
            Dot[k].y = p[i].y - p[i+1].y;
            k++;
        }
        int res = 0;
        for(int i = 0; i < k-1; i++) {
            if(judge(Dot[i],Dot[i+1]))
                res++;
        }
        printf("%d\n",res);
    }
return 0;
}





