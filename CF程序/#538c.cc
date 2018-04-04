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
int main() {
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        bool flag = true;
        int a, b;
        int prea=0, preb=0;
        int res = 0;
        int ans = 0;
        scanf("%d%d", &prea, &preb);
        ans = preb + prea - 1;
        m--;
        while (m--){
            scanf("%d%d", &a, &b);
            if (abs(b - preb) > a - prea)
                flag = false;
            if (flag){
                int disd = a - prea;
                int dish =b - preb;
                if (dish >=0){
                    res = preb + dish;
                    disd -= dish;
                    res += disd / 2;
                    ans = max(ans, res);
                }
                else {
                    disd += dish;
                    res= preb+disd / 2;
                    ans = max(ans, res);
                }

            }
            prea = a;
            preb = b;
        }
        if (flag){
            preb += n - prea;
            ans = max(ans, preb);
        }
        if (flag)
            printf("%d\n", ans);
        else
            puts("IMPOSSIBLE");
    }
return 0;
}
