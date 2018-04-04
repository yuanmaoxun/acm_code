// #722A.cpp
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
int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    int n,h,m;
    char str[105];
	while(~scanf("%d",&n)) {
		scanf("%s",str);
		if((str[0] - '0')*10+str[1]-'0' > n) {
			if(n == 12 && str[1] == '0' )
				str[0] = '1';
			else
				str[0] = '0';
		}
		if(n == 12) {
			if(((str[0] - '0')*10+str[1]-'0' > n)) {
				if(str[1] == '0' )
					str[0] = '1';
				else
					str[0] = '0';
			}
			else if((str[0] - '0')*10+str[1]-'0' == 0){
				str[0] = '1';
			}
		}
		else {
			if((str[0] - '0')*10+str[1]-'0' >= n) {
					str[0] = '0';
			}
		}
		if((str[3] - '0')*10+str[4]-'0' > 59) {
			str[3] = '0';
		}
		printf("%s\n",str);
	}
	return 0;
}