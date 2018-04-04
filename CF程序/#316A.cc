
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

int main(){
    int i, t, j, k, m, n;
    int res, sum, ans, key, len;
    int year, mon, day;
    char str[Maxn];
    int num[105][105];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int flag[105];
    int Max;
    cin >> n >> m;

    Clear(flag, 0);
    for(i = 1; i <= m ; i++){
        Max = -1;
        for(j = 1; j <= n; j++) {
            cin >> num[i][j];
            Max = max(Max, num[i][j]);
        }
        //cout << Max << endl;
        for(k = 1; k <= n; k++) {
            if(num[i][k] == Max){
            //cout << "k" << k <<endl;
                flag[k]++;
                break;
            }
        }
    }
    /*for(i = 1; i <= m; i++ ) {
        cout <<flag[i] <<endl;;
    }*/
    Max = -1;
    for(i = 1; i <= n; i++ ) {
        Max = max(Max, flag[i]);
    }
    //cout << Max <<endl;
    for(i = 1; i <= n; i++){
        if(flag[i] == Max){
        cout << i << endl;
        break;}
    }
return 0;
}




