// #710A.cpp
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
const int MAXN = 5;
using namespace std;


int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    char str[MAXN];
	while(~scanf("%s",str)) {
		if((str[0] == 'a' && str[1] == '8') || (str[0] == 'a' && str[1] == '1') ||(str[0] == 'h' && str[1] == '8') || (str[0] == 'h' && str[1] == '1'))
			printf("3\n");
		else if(str[0] == 'a' ||str[0] == 'h' || str[1] == '1' || str[1] =='8')
			printf("5\n");
		else
			printf("8\n");
	}
	return 0;
}