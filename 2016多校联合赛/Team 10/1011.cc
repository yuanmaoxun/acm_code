// 1011.cpp
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
const int MAXN = 1005;
using namespace std;

int num[20] = {0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8};
int num1[11] = {0,1,6,6,5,5,5,7,6,6,7};

int main(int argc, char const *argv[]) {
//#ifndef ONLINE_JUDGE
//    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
//#endif
    int T;
    int k;
    int n;
    while(~scanf("%d",&T)) {
    	while(T--) {
    		LL sum = 0;
    		scanf("%d",&k);
    		for (int n = 1; n <= k; ++n) {
    			int ans = 0;
    			if (n < 20) {
	    			sum += num[n];
	    			// printf("%d\n",num[n]);
	    		}
	    		else if (n >= 20 && n < 100) {
	    			ans = num1[n/10] + num[n%10];
	    			sum += ans;
	    			// printf("%d\n",ans);
	    		}
	    		else if(n >= 100 && n<1000) {
	    			ans += num[n/100];
	    			ans += 7;
	    			if(n%100==0)
                    {
                        ans+=0;
                    }
                    else if(n%100<20)
                    {
                        ans+=num[n%100]+3;
                    }
	    			else if(n%100 >= 20) {
                        ans += num1[n%100/10] + num[n%10]+3;
	    			}
	    			else{
                        ans += num1[n/10%10] + num[n%10];
	    			}
	    			sum += ans;
	    			// printf("%d\n",ans);
	    		}
	    		else if(n == 1000){
	    			sum += 11;
	    			// printf("11\n");
	    		}
    		}
    		printf("%lld\n", sum);
    	}
    }
    return 0;
}
