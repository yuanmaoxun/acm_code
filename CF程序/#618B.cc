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

#define Maxn 55
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

int num[Maxn][Maxn];
int len[Maxn];
int main(){
    int i, t, j, k, m, n;
    int res, sum, ans, key;
    int year, mon, day;
//    char str[Maxn];

#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE

    while(~scanf("%d",&n)) {
        for(i = 1; i <= n; i++) {
            int Max = 0;
            for(j = 1; j <= n; j++) {
                scanf("%d",&num[i][j]);
                Max = max(Max,num[i][j]);
            }

            int Count = 0;
            for(j = 1; j <= n; j++){
                if(num[i][j] == Max)
                    Count++;
            }
            len[i] = Count;
        }
        for(i = 1; i <= n; i++)
        if(len[i] == 1){
            len[i] = 0;
            break;
        }
        printf("%d",n-len[1]);
        for(i = 2; i <= n; i++) {
            printf(" %d",n-len[i]);
        }
        puts("");
    }
return 0;
}





