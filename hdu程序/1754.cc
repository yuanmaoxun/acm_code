// 1754.cpp
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
const int MAXN = 2*(int)1e5 + 5;
using namespace std;

int Max[MAXN << 2];
int n,m;

void Push_up(int rt) {
	Max[rt] = max(Max[rt << 1] , Max[rt << 1|1]);
}

void Build (int l,int r,int rt) {
	if ( l == r) {
		scanf("%d",&Max[rt]);
		return ;
	}
	int mid = (l+r) / 2;
	Build(lson);
	Build(rson);
	Push_up(rt);
}

int Query(int L,int R, int l,int r, int rt) {
	int ans = 0;
	if (L <= l && R >= r) {
		return Max[rt];
	}
	int mid =(r+l) / 2;
	if (L <= mid) {
		ans = max(ans,Query(L,R,lson));
	}
	if (R > mid) {
		ans = max(ans,Query(L,R,rson));
	}
	return ans;
}

void Update(int point, int add,int l,int r,int rt) {
	if (l == r) {
		Max[rt] = add;
		return;
	}
	int mid = (l+r)/2;
	if (point <= mid) {
		Update(point,add,lson);
	}
	else {
		Update(point,add,rson);
	}
	Push_up(rt);
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    char str[2];
    int a,b;
    while(~scanf("%d%d",&n,&m)) {
    	Build(1,n,1);
    	for (int i = 0; i < m; ++i) {
    		scanf("%s %d %d",str,&a,&b);

    		if (str[0] == 'Q') {
    			printf("%d\n", Query(a,b,1,n,1));
    		}
    		if (str[0] == 'U') {
    			Update(a,b,1,n,1);
    		}
    	}
    }
    return 0;
}