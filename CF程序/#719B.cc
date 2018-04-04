// #719B.cpp
#include <bits/stdc++.h>
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

char str[100005];
    int n;

int solve(char ch, char sh) {
	int cntr = 0;
	int cntb = 0;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
	 	if(i&1) {
	 		if (str[i] == ch) {
	 			continue;
	 		}
	 		if (str[i] == sh) {
	 			if (cntr) {
	 				--cntr;
	 			}
	 			else {
	 				ans++;
	 				cntb++;
	 			}
	 		}
	 	}
	 	else {
	 		if (str[i] == sh) {
	 			continue;
	 		}
	 		if (str[i] == ch) {
	 			if (cntb) {
	 				--cntb;
	 			}
	 			else {
	 				ans++;
	 				cntr++;
	 			}
	 		}
	 	}
	 }
	 return ans; 
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif

	while(~scanf("%d",&n)) {
		// int sumb = 0;
		// int sumr = 0;
		scanf("%s",str);
		
		int ans = min(solve('b','r'),solve('r','b'));

		printf("%d\n",ans);
	}
	return 0;
}