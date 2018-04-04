// #719.cc
//线段树+矩阵快速幂
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

#define Maxn 5

struct Matrix {
	int r,c;
	LL at[Maxn][Maxn];
	Matrix(){}
	Matrix(int r,int c):r(r), c(c) {}
	void clear() {
		CLEAR(at, 0);
		r = c = 2;
	}
	void init () {
		at[0][0] = at[1][1] = 1;
		at[0][1] = at[1][0] = 0;
	}
	void unit() {
		at[0][0] = at[0][1] = at[1][0] = 1;
		at[1][1] = 0;
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
	friend Matrix operator +(const Matrix& A,const Matrix& B) {
		Matrix M (A.r,B.c);
		for (int i = 0; i < A.r; ++i) {
			for (int j = 0; j < B.c; ++j) {
				M.at[i][j] = (A.at[i][j]+B.at[i][j])%Mod;
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
Matrix add[MAXN << 2];
Matrix sum[MAXN << 2];


void PushUp(int rt) {
	sum[rt] = sum[rt<<1]+sum[rt<<1|1];
}

void PushDown(int rt) {
	add[rt<<1] = add[rt<<1]*add[rt];
	add[rt<<1|1] = add[rt<<1|1]*add[rt];
	sum[rt<<1] = sum[rt<<1]*add[rt];
	sum[rt<<1|1] = sum[rt<<1|1] * add[rt];
	add[rt].init();
}

void Build(int l,int r,int rt) {
	int n;
	add[rt].clear();
	sum[rt].clear();
	add[rt].init();
	sum[rt].unit();

	if (l == r) {
		scanf("%d",&n);
		sum[rt] = sum[rt]^(n-1);
		return;
	}
	int m = (l+r)>>1;
	Build(lson);
	Build(rson);
	PushUp(rt);
}

void Update(int L,int R,Matrix c,int l,int r,int rt) {
	
	if (L <= l && R >= r) {
		add[rt] = add[rt]*c;
		sum[rt] = sum[rt]*c;
		return ;
	}
	PushDown(rt);
	int m = (r+l) >> 1;
	if (L <= m) {
		Update(L,R,c,lson);
	}
	if(R>m) {
		Update(L,R,c,rson);
	}
	PushUp(rt);

}
LL Query(int L,int R,int l,int r,int rt) {
	if(L <= l && R >= r)
		return sum[rt].at[0][0];
	PushDown(rt);
	int m = (l+r) >> 1;
	LL res = 0;
	if(L <= m) res = (res+Query(L,R,lson))%Mod;
	if(R > m) res = (res+Query(L,R,rson))%Mod;
	return res;

}
int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
	int tp;
	int L,R,x;
	int n,m;
	scanf("%d%d",&n,&m);
	Build(1,n,1);
	while(m--) {
		scanf("%d",&tp);
		if (tp == 1) {
			scanf("%d%d%d",&L,&R,&x);
			Matrix temp = Matrix(2,2);
			temp.unit();
			temp = temp^x;
			Update(L,R,temp,1,n,1);
		}
		else {
			scanf("%d%d",&L,&R);
			LL ans = Query(L,R,1,n,1);
			printf("%lld\n",ans);
		}
	}
	return 0;
}