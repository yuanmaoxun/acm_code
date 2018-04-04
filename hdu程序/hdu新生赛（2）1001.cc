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
#define Maxm 25
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
    //int res, sum, ans, key, len;
    int year, mon, day;
    char str[Maxn][Maxm];
    int num[Maxn];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int flag[105];
    while(~scanf("%d",&n)) {
        Clear(flag, 0);
        Clear(num,0);
        for(i = 1; i <= n; i++) {
            scanf("%s", str[i]);
            strlwr(str[i]);
            num[i] = strlen(str[i]);
        }
        int sum;
        int ans = 0;
        for(i = 1; i <= n; i++) {

            for(j = i+1; j <=n; j++) {
                sum = 0;
                if(num[i] == num[j]){
                    for(k = 0; k < num[i]; k++) {
                        if(str[i][k] == str[j][k]) {
                            sum++;
                        }
                    }
                    if(sum > 2)
                        flag[i] = flag[j] = 1;
                }
            }
        }
        for(i = 1; i <= n; i++) {

            if(flag[i] == 1)
                ans++;
        }
        cout << ans <<endl;
    }
return 0;
}





