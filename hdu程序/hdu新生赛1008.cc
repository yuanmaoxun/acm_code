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
#define Maxn 10005
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

int main(){
    ll i, t, j, k, m, n;
    ll res, sum, ans, key, len;
    int year, mon, day;
    char str[Maxn];
    int num[Maxm];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int x[Maxn];
    int p[Maxn];
    while(~scanf("%d",&t)) {
        for(int Count = 1; Count <=t; Count++ ){
            scanf("%lld%lld%lld", &n, &m, &k);
            sum = ans = 0;
            for(i = 0; i < n; i++) {
                scanf("%d",&x[i]);
            }
            for(i = 0; i < m; i++) {
                scanf("%d", &p[i]);
                sum += x[p[i]-1];
                x[p[i]-1] = 0;
            }
            ans += m;
            if(sum > k) {
                cout << "-1" <<endl;
                continue;
            }

            else {
//                    cout <<"ans" <<ans <<endl;
                sort(x,x+n);
                k -= sum;
                for(i = 0; i < n; i++) {
                    if(x[i] == 0)
                        continue;
                    if(k < 0) {
                        ans--;
                        break;
                    }
                    else {
                        k-=x[i];
                        ans++;
                    }
//                    cout  << "k:"<< k << endl;
                }
                cout << ans <<endl;
            }

        }

    }
return 0;
}





