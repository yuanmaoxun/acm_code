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
//    char str[Maxn];
    int num[Maxn];
#ifndef ONLINE_JUDGE
    freopen("D://Desktop//ACM//input.txt","r",stdin);
#endif
    int T;
    ll n,m;
    int x;

    while(~scanf("%lld%lld",&n,&m)) {
        set<int> S;
        for(int i= 0; i <n; i++) {
            scanf("%d",&x);
            S.insert(x);
        }
        ll sum = 0;
        ll k = 1;
        ll Count=0;
        while(k) {
            if(sum >= m){
                break;
            }
            if(!S.count(k)){
                sum += k;
                num[Count] = k;
                Count++;
            }
            k++;
        }
        if(sum > m)
            Count--;
        printf("%lld\n",Count);
        for(int i = 0; i < Count; i++){
            if(i == Count-1)
                printf("%d\n",num[i]);
            else
                printf("%d ",num[i]);

        }
    }
return 0;
}





