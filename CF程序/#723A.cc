// #723A.cpp
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
    int x,y,z;
    int num[5];
	while(~scanf("%d%d%d",&num[0],&num[1],&num[2])) {
		sort(num,num+3);
		int res = (num[1]-num[0]) +(num[2]-num[1]);
		printf("%d\n",res); 
	}
	return 0;
}