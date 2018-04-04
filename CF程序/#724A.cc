// #724A.cpp
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
    string Fir,Sec;
    string Week[7] = {"monday","tuesday","wednesday","thursday","friday","saturday","sunday"};
    int Month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int ans,res;
	while(cin >> Fir) {
		cin >> Sec;
		for (int i = 0; i < 7; ++i) {
			if (Fir == Week[i]) {
				ans = i+1;
			}
			if (Sec == Week[i]) {
				res = i+1;
			}
		}
		bool flag = false;
		for (int i = 0; i < 12; ++i) {
			if((Month[i]%7+ans)%7 == (res%7))
				flag = true;
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