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


ll num[Maxn];
int main(){
    ll i, t, j, k, m, n;
    ll res, sum, ans, key, len;
    int year, mon, day;
//    char str[Maxn];

#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    n = 2;k = 0;
    for(i = 2; n <= 1000000000000000005; i++ ) {
        n = n*2;
        sum = n - 1;

        for(j = i-2; j >= 0; j--){
            //cout << sum << " " << pow(2,j) <<endl;
            num[k++] = sum-(long long)(pow(2,j));
        }
    }
    while(~scanf("%lld %lld",&n, &m)) {
        int l,r;
        for(i = 0; i < k; i++){
            if(num[i] >= n) {
                l = i;
                break;
            }
        }
        for(i = 0; i < k; i++){
            if(num[i] > m) {
                r = i;
                break;
            }
        }
        cout << r - l <<endl;
    }
return 0;
}





