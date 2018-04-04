// #723B.cpp
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
    int n;
    char str[10005];
	while(~scanf("%d",&n)) {
		scanf("%s",str);
		int Max = 0;
		int Min = 0;
		int sumMax = 0;
		int sumMin = 0;
		bool flag = false;
		for (int i = 0; i < n; ++i) {
			if(str[i] == '(') {
				Max = max(Max,sumMax);
				sumMax = 0;
				flag = true;
				continue;
			}
			if(str[i] == ')') {
				if(sumMin != 0)
					Min++;
				sumMin = 0;
				flag= false;
				continue;
			}
			if(flag) {
				if(str[i] == '_' && sumMin != 0) {
					Min++;
					sumMin = 0;
				}
				else if(str[i] != '_'){
					sumMin++;
				}
			}
			else {
				if(str[i] == '_' && sumMax != 0) {
					Max = max(sumMax,Max);
					sumMax = 0;
				}
				else if(str[i]!='_') {
					sumMax++;
				}
			}
		}
		Max = max(Max,sumMax);
		printf("%d %d\n",Max, Min);
	}
	return 0;
}
/*
6
(_A__)
16
a_(_AAA_A)_abbbb
1
a
1
_
8
AA(AAA)A
*/