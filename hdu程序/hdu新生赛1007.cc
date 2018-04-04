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
#define Clear(name, num) memset(name, num, sizeof(name))
using namespace std;

int father[Maxn];
int Max;
int sum;

int find_set(int n) {

    return father[n] == n?n:father[n] = find_set(father[n]);
}

int main(){
    int i, t, j, k, m, n;
    int res, ans, key, len;
    int year, mon, day;
    //char str[Maxn];
    //int num[Maxm];
    int Fibo[Maxn];
    int sum[Maxn];
    int num[Maxn];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int u, v;
    int flag[Maxn];
    Fibo[0] = 0;
    Fibo[1] = 1;
    for(k = 2; Fibo[k-1] <= 1000000000; k++) {
        Fibo[k] = Fibo[k-1] + Fibo[k-2];
    }
    while(~scanf("%d%d", &n, &m)) {
        Clear(sum, 0);
        Clear(flag, 0);
        for(int i = 1; i <= n; i++) {
            father[i]=i;
        }
        for(i = 1; i <= n; i++) {
            cin >> num[i];
            if(binary_search(Fibo,Fibo + k,num[i])) {
                flag[i] = 1;
            }
        }
        for(i = 1; i <= m; i++) {
            cin >> u >> v;
            if(find_set(u) != find_set(v)) {
                father[find_set(u)] = find_set(v);
            }
        }
        int Max = 0;
        for(i = 1; i <= n; i++) {
            if(flag[i] == 1) {
                sum[find_set(i)]++;
            }
        }

        for(i = 1; i <= n; i++) {
            Max = max(Max, sum[i]);
        }
        cout << Max << endl;
    }
return 0;
}




