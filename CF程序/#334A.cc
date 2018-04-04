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
#include <bits/stdc++.h>
#define Maxn 1005
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
    char str[Maxn];
    int num[Maxm];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int m1, m2, m3 ,m4, m5;
    int w1,w2,w3,w4,w5;
    int hs, hu;
    while(~scanf("%d%d%d%d%d",&m1, &m2, &m3 ,&m4, &m5)) {
        scanf("%d%d%d%d%d",&w1, &w2, &w3 ,&w4, &w5);
        scanf("%d%d",&hs,&hu);
        int sum1 = max(150,500-2*m1-50*w1);
        int sum2 = max(300,1000-4*m2-50*w2);
        int sum3 = max(450,1500-6*m3-50*w3);
        int sum4 = max(600,2000-8*m4-50*w4);
        int sum5 = max(750,2500-10*m5-50*w5);
        sum = sum1+ sum2+sum3+sum4+sum5+100*hs-50*hu;
        cout <<sum <<endl;
    }
return 0;
}





