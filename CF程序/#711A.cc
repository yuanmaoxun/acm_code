// #711A.cpp
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
const int MAXN = (int)1e3 + 5;
using namespace std;
int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    int T;
    char str[MAXN][10];
	while(~scanf("%d",&T)) {
		for (int i = 0; i < T; ++i) {
			scanf("%s",str[i]);
		}
		bool flag = false;
		for (int i = 0; i < T; ++i) {
			if ((str[i][0]=='O' && str[i][1] =='O') || (str[i][3]=='O' && str[i][4] =='O')) {
				flag = true;
				if (str[i][0]=='O' && str[i][1] =='O') {
					str[i][0]='+';str[i][1] ='+';
					break;
				}
				else {
					str[i][3]='+'; str[i][4] ='+';
					break;
				}
			}
		}
		if (flag) {
			cout <<"YES" << endl;
			for (int i = 0; i < T; ++i) {
				cout << str[i] <<endl;
			}
		}
		else {
			cout << "NO" <<endl;
		}
		
	}
	return 0;
}