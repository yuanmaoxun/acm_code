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

#define Maxn 200005
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

struct Point  {
    int x;
    int y;
}P[Maxn];

int main(){
    int i, t, j, k, m, n;
    ll res, sum, ans, key, len;
    int year, mon, day;
//    char str[Maxn];
//    int num[Maxn];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE

    while(~scanf("%d",&n)) {
        map <int,int> Add;
        map <int,int> Dec;
        map <int,int> :: iterator iter1;
        map <int,int> :: iterator iter2;
        for(i = 0; i < n; i++) {
            scanf("%d%d",&P[i].x, &P[i].y);
            res = P[i].x + P[i].y;
            ans = P[i].y - P[i].x;
            Add[res]++;
            Dec[ans]++;
        }
        sum = 0;
        for(iter1 = Add.begin();iter1!=Add.end();iter1++) {
            ll temp = iter1->second;
            sum += temp*(temp-1)/2;
        }
        //cout <<"sum:" <<sum <<endl;
        for(iter2 = Dec.begin();iter2!=Dec.end();iter2++) {
            ll temp = iter2->second;
            sum += temp*(temp-1)/2;
        }
        printf("%lld\n",sum);
    }
return 0;
}





