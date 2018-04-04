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
#define Mod 1000000007
#define PI  3.1415926535898
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1|1
#define debug puts("here is a BUG");
#define Clear(name, num) memset(name, num, sizeof(name));

using namespace std;

int gcd(int m, int n) {
    return m % n == 0 ? n : gcd(n, m % n);
}

int main(){
    int i, t, j, k, m, n;
    int res, sum, ans, key, len;
    int year, mon, day;
    char str[Maxn];
    int num[Maxm];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int h, mi, sec;
    while(~scanf("%d", &t)) {
        while(t--) {
            scanf("%d:%d:%d", &h, &mi, &sec);
            if(h >= 12)
                h -= 12;
            //cout << h <<" "<< mi << " " << sec <<endl;
            int hm = abs(3600 * h + 60 * mi + sec - 720 * mi - 12 * sec);
            int hs = abs(3600 * h + 60 * mi + sec - 720 * sec);
            int ms = abs(720 * mi + 12 * sec - 720 * sec);
            //cout << hm << " "<< hs <<" "<< ms <<endl;
            if(hm >= 180 * 120) hm = 360 * 120 - hm;
            if(hs >= 180 * 120) hs = 360 * 120 - hs;
            if(ms >= 180 * 120) ms = 360 * 120 - ms;
            int hmg = gcd(hm, 120);
            int hsg = gcd(hs, 120);
            int msg = gcd(ms, 120);
            //cout << hmg <<" "<< hsg << " " << msg <<endl;
            if(hmg == 120)
                cout << hm / 120 << " ";
            else
                cout << hm / hmg << "/" << 120 / hmg <<" ";
            if(hsg == 120)
                cout << hs / 120 << " ";
            else
                cout << hs / hsg << "/" << 120 / hsg <<" ";
            if(msg == 120)
                cout << ms / 120 << " " << endl;
            else
                cout << ms / msg << "/" << 120 / msg << " " <<endl;
        }
    }
return 0;
}





