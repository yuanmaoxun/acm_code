// #707D.cpp
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
const int MAXN = (int)1e9 + 5;
using namespace std;
int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    char str[50005];
    while(~scanf("%s",str)) {
    	queue<char>Q;
    	int len = strlen(str);
    	if(len < 26){
    		puts("-1");
    		continue;
    	}
    	int sum = 0;
    	int vis[26] = {0};
    	for (int i = 0; i < 26; ++i) {
    		if(str[i] =='?') {
    			sum++;
    		}
    		else {
    			vis[str[i]-'A']++;
    		}
    	}
    	int l = 0;int r=25;
    	bool flag = false;
    	while(r < len) {
    		int ans = 0;
    		for (int i = 0; i < 26; ++i) {
    			if(!vis[i]) {
    				ans++;
    			}
    		}
    		if (ans == 0) {
    			flag = true;
    			break;
    		}
    		if(ans <= sum) {
    			flag = true;
    			break;
    		}
    		if(str[l]!='?'){
    			vis[str[l]-'A']--;
    		}
    		else {
    			sum--;
    		}
    		l++;
    		r++;
    		if(str[r]!='?'){
    			vis[str[r]-'A']++;
    		}
    		else {
    			sum++;
    		}
    	}
    	if (flag) {
    		int j;
    		for (int i = 0; str[i]; ++i) {
    			if (str[i] == '?' && i >= l) {
    				for (j = 0; j < 26; ++j) {
    					if(!vis[j]) {
    						printf("%c",j+'A');
    						vis[j]++;
    						break;
    					}

    				}
					if(j == 26) {
					    printf("A");
					}
    			}
    			else if(str[i] == '?') {
    				printf("A");
    			}
    			else {
    				printf("%c",str[i]);
    			}
    		}
    		puts("");
    	}
    	else{
    		puts("-1");
    	}
    }
    return 0;
}