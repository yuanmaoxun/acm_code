
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

#define Maxn 1000005
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
    ll i, t, j, k, l, r, m, n;
    // res, sum, ans, key, len;
    int year, mon, day;
//    char str[Maxn];
//    int num[Maxn];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE

    while(~scanf("%lld%lld%lld",&l, &r, &k)) {
        ll sum = 1;
        i = 0;
        int flag = 0;
        while(sum <= r) {
            if(sum >= l){
                num[i++] = sum;
                flag = 1;
                }
            sum *= k;
            if(sum < 0)
                break;
            //cout <<sum <<endl;
        }
        if(flag == 0)
            cout << "-1" <<endl;
        else {
            for(j = 0; j < i; j++) {
                if(j == i-1) {
                    cout << num[j] <<endl;
                }
                else {
                    cout << num[j] <<" ";
                }
            }
        }
    }
return 0;
}




