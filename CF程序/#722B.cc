// #722B.cpp
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
    int num[105];
	while(~scanf("%d",&n)) {
		for (int i = 0; i < n; ++i) {
			cin >> num[i];
		}
		char str[1005];
		bool flag = true;
		getchar();
		for (int i = 0; i < n; ++i) {
			
			gets(str);
			int sum = 0;
			int len = strlen(str);
			for (int j = 0; j < len; ++j) {
				if(str[j] == 'a' || str[j]=='e' || str[j]=='i' || str[j]=='o' || str[j]=='u' || str[j]=='y')
					sum++;
			}
			// cout << "sum:"<<sum <<endl;
			if(sum != num[i]){
				flag = false;
			}
		}
		if (flag) {
			puts("YES");
		}
		else {
			puts("NO");
		}
	}
	return 0;
}