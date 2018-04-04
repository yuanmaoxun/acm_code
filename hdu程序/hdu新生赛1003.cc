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
#include <bits/stdc++.h>
#define Maxn 105
#define Maxm 100005
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

int f(int m) {
    for(int i = 2; i*i <= m; i++) {
        if(m % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(){
    int i, t, j, k, m, n;
    int res, sum, ans, key, len;
    int year, mon, day;
    char str[Maxn];
    int num[Maxm];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    while(~scanf("%d",&t)) {
        for(int Count = 1; Count <= t; Count++) {
            scanf("%d",&n);
            if(n == 1 || n == 2 ||n == 3) {
                cout << "4" <<endl;
                continue;
            }
            double sn = sqrt(n);
            int ans1 = int(sn);
            int ans2 = int(sn) + 1;
            for(i = ans1; i >= 2; i--) {
                if( f(i) ) {
                    ans1= i;
                    break;
                }
            }
            for(i = ans2;; i++) {
                if( f(i) ) {
                    ans2= i;
                    break;
                }
            }
            //cout << ans1<<" " <<ans2 <<endl;
            if(n - ans1*ans1 < ans2*ans2 - n) {
                cout << ans1*ans1 <<endl;
            }
            else {
                cout << ans2 * ans2 <<endl;
            }
        }
    }
return 0;
}




