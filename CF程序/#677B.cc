// #677B.cpp
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
    LL num[100005];
    LL n,h,k;
	while(~scanf("%lld%lld%lld",&n,&h,&k)) {
		LL sum = 0;
		LL time = 0;
		for(int i = 0; i < n; i++) {
			scanf("%lld",&num[i]);
			if(sum + num[i] > h){
				sum = 0;
				time++;
			}
			sum += num[i];
			time += sum/k;
			sum %= k;
		}
		if(sum)
			time++;
		//cout <<sum <<":" << time<<endl;
		printf("%lld\n", time);
	}
	return 0;
}