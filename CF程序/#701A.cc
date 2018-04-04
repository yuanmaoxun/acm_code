// #701A.cpp
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
const int MAXN = 100 + 5;
using namespace std;

struct Number {
    	int index;
    	int val;
    }num[MAXN];

    bool cmp(Number a,Number b) {
    	return a.val < b.val;
    }

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    int n;
    while(~scanf("%d",&n)) {
    	for (int i = 0; i < n; ++i)
    	{
    		scanf("%d",&num[i].val);
    		num[i].index = i+1;
    	}
    	sort(num,num+n,cmp);
    	for (int i = 0; i < n/2; ++i) {
    		printf("%d %d\n", num[i].index,num[n-i-1].index);
    	}
    }
	return 0;
}