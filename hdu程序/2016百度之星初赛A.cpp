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
#define Maxn 10005
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
int main() {
    ll T, x, k, c, j;
    ll m;
    int flag;
    int mod[Maxn], num[Maxn];
    scanf("%lld", &T);
    int Case = 1;
    int ok;
    int index;
    while(T--) {
        ok = 0;
        index = 0;
        Clear(mod,0);
        scanf("%lld%lld%lld%lld", &x, &m, &k, &c);
        for(j = 0; j != m; ++j) {
            index = (index * 10 + x) % k;
            num[j] = index;
            mod[index] += 1;
            if(mod[index] >= 2) {
                ok = j;
                break;
            }
        }
        if(j >= m) {
            ok = m;
        }
        for(j = 0; j <= ok; j++) {
            if(num[j] == index) {
                ok = ok - j;
                flag = j;
                break;
            }
        }
        printf("Case #%d:\n",Case++);
        if(num[(m - flag - 1)%ok + flag] != c)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
