// 5078.cpp
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
#define LL long long
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
#define PI 3.1415926535897932626
#define EXIT exit(0);
#define PAUSE system("pause");
#define DEBUG puts("Here is a BUG");
#define SYNC_CLOSE ios::sync_with_stdio(false);
#define what_is(x) cout << #x << " is " << x << endl;
#define CLEAR(name, init) memset(name, init, sizeof(name));
const double eps = 1e-8;
const int Maxn = (int)1000 + 5;
using namespace std;

struct Point {
	int t;
	LL x,y;
}point[Maxn];

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    int T;
    int n;
    while(~scanf("%d",&T)) {
    	while(T--) {
    		scanf("%d",&n);
    		for (int i = 0; i < n; ++i) {
    			scanf("%d%d%d",&point[i].t,&point[i].x,&point[i].y);
    		}
    		double ans = -1;
    		for (int i = 0; i < n; ++i) {
    			for (int j = i+1; j < n; ++j) {
    				LL xx = (point[i].x-point[j].x)*(point[i].x-point[j].x);
    				LL yy = (point[i].y-point[j].y)*(point[i].y-point[j].y);
    				double res = sqrt(xx + yy)/abs(point[i].t-point[j].t);
    				// printf("%.2lf", res);
    				ans = max(ans,res);
    			}
    		}
    		printf("%.10lf\n",ans);
    	}
    }
    return 0;
}