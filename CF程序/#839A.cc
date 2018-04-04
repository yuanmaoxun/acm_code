// #839A.cpp
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

    int n,m;
    int num[105];
	while(~scanf("%d%d",&n,&m)) {
		for (int i = 0; i < n; ++i) {
			scanf("%d",&num[i]);
		}
		int res = -1;
		int sum1 = 0;
		int sum2 = 0;

		for (int i = 0; i < n; ++i) {
			if (sum1 >= m) {
				res = i+1;
				break;
			}
			if (num[i] >= 8) {
				sum2 += num[i]-8;
				sum1 += 8;
			}
			else{
				sum1 += min(8,num[i]+sum2);
				if(num[i]+sum2 >= 8){
					sum2 -= 8-num[i];
				}
				else {
					sum2 = 0;
				}
			}
			if (sum1 >= m) {
				res = i+1;
				break;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}