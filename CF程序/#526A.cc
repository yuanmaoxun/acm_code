// #526A.cpp
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
int main() {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    char str[105];
    int d;
    int n;

	while(~scanf("%d",&n)) {
		scanf("%s",str);
		d = 1;
		bool flag = false;
		while(d <= n/4) {
			for(int i = 0; i + 4*d < n; i++){
				if(str[i] == '*' && str[i+d] == '*' && str[i+2*d] == '*' && str[i+3*d] == '*' && str[i+4*d] == '*') {
					flag = true;
					break;
				}
			}
			if(flag)
				break;
			d++;
		}
		if(flag)
			printf("yes\n");
		else
			puts("no\n");
	}
	return 0;
}