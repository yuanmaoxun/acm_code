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

#define Maxn 10005
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
    ll i, t, j, k, m, n;
    ll res, sum, ans, key, len;
    int year, mon, day;
//    char str[Maxn];

#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    num[0] = 1;
    num[1] = 2;
    for(i = 2; i<=85; i++){
        num[i] = num[i-1] + num[i-2];
        //cout << num[i] <<endl;
    }
    int T;
    while(~scanf("%d",&T)) {
        while(T--) {
            scanf("%lld",&n);
            if(n == 1){
                cout << 1<<endl;
                continue;
            }
            if(n == 2) {
                cout << 1 <<endl;
                continue;
            }
            sum = 0;
            for(j = 0; j <= 85;j++ ) {
                sum += num[j];
                if(sum > n) {
                    cout << j <<endl;
                    break;
                }
                if(sum == n){
                    cout <<j+1 <<endl;
                    break;
                }
            }
           // cout <<"sum"<<sum<<endl;
            //cout << i+1 <<endl;
        }
    }
return 0;
}





