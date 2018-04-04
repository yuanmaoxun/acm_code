// 1002.cpp
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
#define ll long long
#define lson l, mid, rt<<1
#define rson mid+1, r, rt<<1|1
#define PI 3.1415926535897932626
#define EXIT exit(0);
#define PAUSE system("pause");
#define DEBUG puts("Here is a BUG");
#define SYNC_CLOSE ios::sync_with_stdio(false);
#define what_is(x) cout << #x << " is " << x << endl;
#define CLEAR(name, init) memset(name, init, sizeof(name));
const double eps = 1e-8;
const int Maxn = (int)1e9 + 5;
using namespace std;

ll num[1000005];


int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    int T;
    int n;
    int k = 0;
for (int a = 0; a < 30; ++a) {
	for (int b = 0; b < 30; ++b) {
		for (int c = 0; c < 30; ++c) {
			for (int d = 0; d < 30; ++d) {
				num[k++] = (ll)(pow(2,a) * pow(3,b)*pow(5,c)*pow(7,d));
			}
		}
	}
}

	sort(num,num+k);
    while(~scanf("%d",&T)) {
    	for (int i = 0; i < T; ++i) {
    		scanf("%d",&n);
    		int index = lower_bound(num,num+k,n)-num;
    		printf("%d\n", num[index]);
    	}
    }
    return 0;
}