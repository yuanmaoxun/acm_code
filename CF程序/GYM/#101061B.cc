// MatrixQuickPow.cpp
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
const int MAXN = (int)1e5 + 5;
const LL Mod = 1000000007;
using namespace std;

#define Maxn 10

struct Matrix {
	int r,c;
	LL at[Maxn][Maxn];
	Matrix(){}
	Matrix(int r,int c):r(r), c(c) {}
	void clear() {
		CLEAR(at, 0);
		r = c =0;
	}
	void init () {
		clear();
		for (int i = 0; i < Maxn; ++i) {
			at[i][i] = 1;
		}
	}
	void unit() {
		clear();
		for (int i = 0; i < Maxn; ++i) {
			at[i][i] = 1;
		}
	}
	friend Matrix operator * (const Matrix& A,const Matrix& B) {
		Matrix M(A.r,B.c);
		for (int i = 0; i < A.r; ++i) {
			for (int j = 0; j < B.c; ++j) {
				M.at[i][j] = 0;
				for(int k = 0; k < A.c; k++) {
					M.at[i][j] += A.at[i][k] * B.at[k][j];
					M.at[i][j] %= Mod;
				}
			}
		}
		return M;
	}
	friend Matrix operator ^ (const Matrix A, int n) {
		if (A.r != A.c) {
			exit(-2);
		}
		Matrix res ,tmp = A;
		res.init();
		res.r = res.c = A.r;
		if (n == 0) {
			return res;
		}
		while(n) {
			if(n&1)
				res = (res * tmp);
			tmp = tmp * tmp;
			n >>= 1;
		}
		return res;
	}
};

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
	SYNC_CLOSE;
	int T;
	int n;
	while(~scanf("%d",&T)) {
		while(T--) {
			scanf("%d",&n);
			if(n == 1){
				printf("3\n");
				continue;
			}
			Matrix base = Matrix(3,3);
			int k = 1;
			for (int i = 0; i < 3; ++i) {
				for (int j = 0; j < 3; ++j) {
					base.at[i][j] = k++;
				}
			}
			Matrix res = base ^ (n-1);
			LL ans = 0;
			for (int i = 0; i < 3; ++i) {
				for (int j = 0; j < 3; ++j) {
					ans += res.at[i][j];
					ans = ans%Mod;
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}