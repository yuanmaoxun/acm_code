// 1003.cpp
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
const int MAXN = 1000005;

using namespace std;
    int ans[MAXN];
    int arr[MAXN];
int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif

    int n;
    int T;
    while(~scanf("%d",&T)) {
    	while(T--) {
    		int ans = 0;
    		scanf("%d",&n);
    		for(int i = 0; i < n; i++) {
    			scanf("%d",&arr[i]);
    		}
    		for (int i = 0; i < n; ++i) {
    			if (arr[i] % 8 ==0) {
    				ans ^= arr[i]-1;
    			}
    			else if(arr[i]%8 == 7) {
    				ans ^= arr[i]+1;
    			}
    			else{
    				ans ^= arr[i];
    			}
    		}
    		if(ans) {
    			puts("First player wins.");
    		}
    		else
    			puts("Second player wins.");
    	}
    }

    return 0;
}