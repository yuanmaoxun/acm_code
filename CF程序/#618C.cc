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

struct Point{
    ll x;
    ll y;
    int index;
}P[Maxn];

bool cmp (Point a,Point b) {
    if(a.x != b.x) {
        return a.x < b.x;
    }
    else {
        return a.y < b.y;
    }

}
int main(){
    int i, t, j, k, m, n;
    int res, sum, ans, key, len;
    int year, mon, day;
//    char str[Maxn];
//    int num[Maxn];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE

    while(~scanf("%d",&n)) {
        for(i = 0; i < n; i++) {
            scanf("%lld",&P[i].x);
            scanf("%lld",&P[i].y);
            P[i].index = i+1;
        }
        sort(P,P+n,cmp);
        for(i = 0; i < n-2; i++) {
            if( (P[i].x-P[i+1].x)* (P[i].y-P[i+2].y) - (P[i].y-P[i+1].y)* (P[i].x-P[i+2].x)!=0 ){
                printf("%d %d %d\n",P[i].index,P[i+1].index,P[i+2].index);
                break;
            }
        }
    }
return 0;
}





