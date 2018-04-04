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
#define Maxm 500
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
struct SP {
    int value;
    int l;
    int r;
}S[320000];
bool cmp(SP a, SP b) {
   return  a.value > b.value;
}

int main(){
    int i, t, j, k, m, n;
    int  sum, ans, key, len;
    int year, mon, day;
    char str[Maxn];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    //int num[1005][1005];
    int res[805];

    while(~scanf("%d", &n)) {
        Clear(res, 0);
        Clear(S,0);
        k = 0;
        for(i = 2; i <= 2*n; i++)
            for(j = 1; j < i; j++) {
                cin >> m;
                S[k].value = m;
                S[k].l = i;
                S[k].r = j;
                k++;
            }
        sort(S, S + k,cmp);
        /*for(i = 0; i < k; i++){
            cout << S[i].value <<  S[i].l << S[i].r << endl;;
        }*/
        res[S[0].l] = S[0].r;
        res[S[0].r] = S[0].l;
        for(i = 1; i < k; i++) {
            if(res[S[i].l] == 0&&res[S[i].r] == 0) {
                res[S[i].l] = S[i].r;
                res[S[i].r] = S[i].l;
            }
        }
        //debug
        cout << res[1] ;
        for(i = 2; i <= 2*n; i++)
            cout << " "<< res[i];
        puts("");
    }
return 0;
}




