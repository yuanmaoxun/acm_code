// 1422.cpp
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
const int MAXN = 30005;
using namespace std;
int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    int n,m;
    int A[MAXN];
    int u[MAXN];
    while(~scanf("%d%d",&m,&n)) {
    	priority_queue<int, vector<int>, less<int> > que1;
    	priority_queue<int, vector<int>, greater<int> > que2;
    	for (int i = 0; i < m; ++i) {
    		scanf("%d",&A[i]);
    	}
    	for (int i = 1; i <= n; ++i) {
    		scanf("%d",&u[i]);
    	}
    	int j = 1;
    	int k = 1;
    	int i = 0;
    	while(j<=n) {
    		if (u[j] == i) {
    			if(que1.size() < k) {
    				int Top = que2.top();
    				que2.pop();
    				que1.push(Top);
    			}
    			printf("%d\n", que1.top());
    			j++;
    			k++;
    		}
    		else {
    			if(que1.size() < k) {
    				que2.push(A[i]);
    				int Top = que2.top();
    				que2.pop();
    				que1.push(Top);
    			}																																		
    			else {
    				int Top = que1.top();
    				if(Top <= A[i]) {
    					que2.push(A[i]);
    				}
    				else {
    					que1.pop();
    					que2.push(Top);
    					que1.push(A[i]);
    				}
    			}
    			i++;
    		}
    	}
    }
    return 0;
}