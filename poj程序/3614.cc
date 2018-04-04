// 3614.cpp
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
const int MAXN = 3005;
using namespace std;
int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    int C,L;
    int Min,Max;
    int spf,num;
    typedef pair <int,int> Pair;
    Pair cow[MAXN];
    Pair bottle[MAXN];
    while(~scanf("%d%d",&C,&L)) {
    	priority_queue<int,vector<int>,greater<int> > Q;
    	for (int i = 0; i < C; ++i) {
    		scanf("%d%d",&cow[i].first,&cow[i].second);
    	}
    	for (int i = 0; i < L; ++i) {
    		scanf("%d%d",&bottle[i].first,&bottle[i].second);
    	}
    	int res = 0;
    	sort(cow,cow+C);
    	sort(bottle,bottle+L);
    	int j = 0;
    	for (int i = 0; i < L; ++i) {
    		while(j < C && cow[j].first <= bottle[i].first) {  
            	Q.push(cow[j].second);  
            	j++;  
        	}  
    		while(!Q.empty() && bottle[i].second) {
    			int Top = Q.top();
    			Q.pop();
    			if (Top < bottle[i].first) {
    				continue;
    			}
    			res++;
    			bottle[i].second--;
    		}
    	}
    	printf("%d\n",res);
    }
    return 0;
}
