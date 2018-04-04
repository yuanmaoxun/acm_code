// 1010.cpp
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
const int MAXN = 1000 + 5;
using namespace std;

struct Node {
	int index;
	int follow;
}num[MAXN];

bool cmp(Node a,Node b) {
	return a.follow < b.follow;
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    int T;
    int Case;
    int n;

    while(~scanf("%d",&T)) {
    	Case = 1;
    	while(T--) {
    		vector<int> edges[MAXN];
    		scanf("%d",&n);

    		for (int i = 0; i < n; ++i) {
    			scanf("%d",&num[i].follow);
    			num[i].index = i+1;
    		}
    		sort(num,num+n,cmp);
    		bool flag = true;
    		int ans = 0;
    		for (int i = 0; i < n; ++i) {
    			if (i < num[i].follow) {
    				flag = false;
    				break;
    			}
    			for (int j = 0; j < num[i].follow; ++j) {
    				edges[num[i].index].push_back(num[j].index);
    				ans++;
    			}
    		}
    		if (flag) {
    			printf("Case #%d: ",Case++);
    			printf("Yes\n%d\n",ans);
    			for (int i = 1; i <= n; ++i) {
    				for (int j = 0; j < edges[i].size(); ++j) {
    					printf("%d %d\n",i,edges[i][j]);
    				}
    			}
    		}
    		else {
    			printf("Case #%d: ",Case++);
    			printf("No\n");
    		}
    	}
    }
    return 0;
}