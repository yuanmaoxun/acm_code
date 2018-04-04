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


int main(){
    int i, t, j, k, m, n;
    int res, sum, ans, key, len;
    int year, mon, day;
    char str[Maxn];
    ll num[Maxn];
    int s[Maxn*2];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE

    while(~scanf("%d%d",&n, &k)) {
        for(i = 0; i<n; i++){
            scanf("%lld",&num[i]);
        }
        if(n  == k*2) {
            ll Max = 0;
            for(i = 0; i < k; i++){
                Max = max(Max,num[i] + num[n-i-1]);
            }
            printf("%lld\n",Max);
        }
        else if(n < 2*k && n > k){
            ll Max = 0;
            for(i = 0; i < n-k; i++) {
                Max = max(Max,num[i] + num[(n-k)*2-i-1]);
            }
            Max = max(Max, num[n-1]);
            printf("%lld\n",Max);
        }
        else {
                cout << num[n-1]<<endl;
            }
    }
return 0;
}





