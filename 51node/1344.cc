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
#define Maxm 50005
#define INF 0xffff;
#define ll long long
#define Mod 1000000007
#define PI  3.1415926535898
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1|1
#define debug puts("here is a BUG");
#define Clear(name, num) memset(name, num, sizeof(name));
using namespace std;

int main(){
    int i, t, j, k, m, n;
    ll res, sum, ans, key, len;
    int year, mon, day;
    char str[Maxn];
    ll num[Maxm];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    while(~scanf("%d",&n)){
        for(i = 0; i < n; i++)
            scanf("%lld", &num[i]);

        sum = 0;

        for(i = n - 1; i >= 0; i--)
            if(num[i] < 0) {
                k = i;
                break;
            }

        for(i = k; i >= 0; i--) {
            sum += -num[i];
            if(sum <= 0)
                sum = 0;
            //cout << sum << endl;
        }
        if(sum < 0)
            cout << "0" << endl;
        else
             cout << sum << endl;
    }
return 0;
}




