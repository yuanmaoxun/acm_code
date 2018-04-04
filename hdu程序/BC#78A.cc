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
//    int num[Maxn];
#ifndef ONLINE_JUDGE
    freopen("D://Desktop//ACM//input.txt","r",stdin);
#endif
    int T;
    ll a,b,c,d;
    ll num[4];
    while(~scanf("%d",&T)) {
        while(T--) {
            scanf("%I64d %I64d %I64d %I64d",&a,&b,&c,&d);
            if(a == 0 || b == 0 || c == 0|| d == 0){
                printf("No\n");
                continue;
            }
            num[0]=a;num[1]=b;num[2]=c;num[3]=d;
            sort(num,num+4);
        //printf("%llu %d %d %d\n",a-b , b-a < c+d ,c-b < a+d, d-a < b+c);
//            if(a-b-c < d && b-a-c < d && c-b-a < d && d-a-b < c){
//                printf("Yes\n");
//            }
            if(num[3] - num[2] -num[1] < num[0])
                printf("Yes\n");
            else {
                printf("No\n");
            }
        }
    }
return 0;
}





