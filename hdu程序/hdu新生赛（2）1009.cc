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
    int res, sum, ans, key, len;
    int year, mon, day;
    char str[2];
//    int num[Maxn];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int wl,wa,wd;
    int bl,ba,bd;
    while(~scanf("%s",str)) {
        scanf("%d%d%d",&wl,&wa,&wd);
        scanf("%d%d%d",&bl,&ba,&bd);
        if(wa-bd <= 0) {
            cout << "Warrior loses" <<endl;
            continue;
        }
        if((wa - bd) > 0 && (ba-wd) < 0 ) {
            cout << "Warrior wins" <<endl;
            continue;
        }
        int sumw ,sumb;
        if((wa - bd) > 0 && (ba-wd)>0 ) {
            sumw = bl%(wa-bd)!=0 ? bl/(wa-bd)+1 : bl/(wa-bd) ;
            sumb = wl%(ba-wd)!=0 ? wl/(ba-wd)+1 : wl/(ba-wd) ;
            if(str[0] == 'W') {
                sumw=sumw - 1;
            }
            else {
                sumb=sumb - 1;
            }
            //cout << sumw << " "<<sumb <<endl;
            if(sumw < sumb) {
                cout <<"Warrior wins" <<endl;
            }
            else {
                cout <<"Warrior loses" <<endl;
            }
            continue;
        }
    }
return 0;
}





