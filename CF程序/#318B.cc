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
#define Maxm 4005
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
int num[Maxm][Maxm];
int main(){
    int i, t, j, k, m, n;
    int res, sum, ans, key, len;
    int year, mon, day;
    char str[Maxn];

#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    while(~scanf("%d%d", &n, &m)) {
        int len[Maxm];
        Clear(len, 0);
        int a[Maxm] ,b[Maxm];
        //debug
        for(i = 1; i <= m; i++) {
            cin >> a[i] >> b[i];
            num[a[i]][b[i]] = num[b[i]][a[i]] = 1;
            len[a[i]]++;
            len[b[i]]++;

           // cout << i <<endl;
        }
        int Min = 1000000;
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n ;j++) {
                if(num[a[i]][j] == num[b[i]][j]) {
                    Min = min(Min, len[i]+len[b[i]]+len[j]-6);
                }
            }
        if(Min < 1000000)
            cout << Min <<endl;
        else
            cout << "-1" <<endl;
    }
return 0;
}





