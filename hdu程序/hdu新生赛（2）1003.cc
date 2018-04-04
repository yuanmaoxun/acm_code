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
    ll res, sum, ans, key, len;
    int year, mon, day;
//    char str[Maxn];
//    int num[Maxn];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int num1[Maxn];
    int num2[Maxn];
    while(~scanf("%d%d",&n, &m)) {
        for(i = 0; i < n; i++)
            scanf("%d",&num1[i]);
        for(i = 0; i < m; i++)
            scanf("%d",&num2[i]);
        //sort(num1,num1+n);
        sort(num2,num2+m);
        sum = 0;
        for(i = 0; i < n; i++) {
            k = upper_bound(num2, num2+m,num1[i]) - num2-1;
            if(k == 0)
                sum += abs(num1[i]-num2[k]);
            else
                sum+=min(abs(num1[i]-num2[k-1]),abs(num2[k]-num1[i]));
        }
        cout << sum <<endl;
    }
return 0;
}





