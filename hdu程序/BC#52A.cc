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

int main() {
    int i, t, j, k, m, n, x, y, w;
    int res, sum, ans, key, len;
    int year, mon, day;
    char str[Maxn];
    int num[Maxm];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt", "r", stdin);
#endif // ONLINE_JUDGE
    while(~scanf("%d%d%d%d", &x, &y, &w, &n)) {
            res = 0;
            j = 0;
            k = 0;
        for(i = 0; ;i++){
            if(j == 0)
                res++;
            if(k == w)
                k = 0, res++;
            if(res == n)
                break;
            if(j == x){
                i += (y - 1);
                j = 0;
                k = 0;
                continue;
            }
            j++;
            k++;
        }
       cout << i <<endl;

    }
    return 0;
}





