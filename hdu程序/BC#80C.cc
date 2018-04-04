
#include<cstdio>
#include<cstdlib>
#include<time.h>
#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>

//#include<bits/c++std.h>

#define Size 1000005
#define inf 2e9
#define INF 2e18
#define LL long long int
#define i64 __int64
#define ULL unsigned long long
#define Mod 1000000007
#define pi 4*atan(1)
#define eps 1e-8
#define lson now*2,l,l+(r-l)/2
#define rson now*2+1,l+(r-l)/2+1,r
#define Max(a,b) (a)>(b)?(a):(b)
#define N 4
using namespace std;
LL n,m,k;
int ql,qr,pos;

LL multi(LL a, LL b, LL mod)//快速乘法取模，防止两个过大的数相乘爆LL
{
    LL ans = 0;
    a %= mod;
    while(b)//原理与快速幂类似，将一个数装换为二进制，按位相乘再求和
    {
        if(b&1)
        {
            ans = (ans + a) % mod;
        }
        b >>= 1;
        a = (a + a) % mod;
    }
    return ans;
}

LL QuickMod(LL a, LL b, LL mod)//利用了快速乘法的快速幂，防止爆LL
{
    if(b == 0)
        return 1;
    LL ans = 1;
    a %= mod;
    while(b)
    {
        if(b&1)
        {
            ans = multi(ans, a, mod);
        }
        b >>= 1;
        a = multi(a, a, mod);
    }
    return ans;
}

struct Matrix
{
	LL mat[N][N];
    ///double mat[N][N];浮点型
	int row;//行
	int col;//列
	Matrix():row(N),col(N){}
	Matrix(int r,int c):row(r),col(c){}//构造函数
};

LL MOD;

Matrix Mul(Matrix left,Matrix right);
Matrix Pow(Matrix x,LL n);
Matrix MulMod(Matrix left,Matrix right);
Matrix PowMod(Matrix x,LL n);

void Show(Matrix x);




void Show(Matrix x)
{

	for(int i = 0 ; i < x.row ; i++)
	{
		for(int j = 0 ; j < x.col ; j++)
		{
			printf("%6lld",x.mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

Matrix Mul(Matrix left,Matrix right)
{
	Matrix res;
	if(left.col != right.row)	return res;

	res.row = left.row;
	res.col = right.col;

	for(int i = 0 ; i < left.row ; i++)
	{
		for(int j = 0 ; j < right.col; j++)
		{
			res.mat[i][j] = 0;
			for(int k = 0 ; k < left.col ; k++)
			{
				res.mat[i][j] += left.mat[i][k] * right.mat[k][j];
			}
		}
	}
	return res;
}

Matrix Pow(Matrix x,LL n)
{
	Matrix res ;

	res.row = x.row;
	res.col = x.col;

	for(int i = 0 ; i < res.row ;i++)
	{
		for(int j = 0 ; j < res.col ; j++)
			res.mat[i][j] = 0;
		res.mat[i][i] = 1;
	}

	while(n)
	{
		if(n&1)	res = Mul(res,x);
		x = Mul(x,x);
		n >>= 1;
	}

	return res;
}

Matrix MulMod(Matrix left,Matrix right)
{
	Matrix res;

	if(left.col != right.row)	return res;

	res.row = left.row;
	res.col = right.col;

	for(int i = 0 ; i < left.row ; i++)
	{
		for(int j = 0 ; j < right.col; j++)
		{
			res.mat[i][j] = 0;
			for( k = 0 ; k < left.col ; k++)
            {
                res.mat[i][j] += (left.mat[i][k] * right.mat[k][j]) % MOD;
                res.mat[i][j] %= MOD;
            }
            res.mat[i][j] %= MOD;
		}
	}
	return res;
}
///如果结果可能有负数，答案同一化成(ans%MOD+MOD)%MOD

Matrix PowMod(Matrix x,LL n)
{
	Matrix res ;

	res.row = x.row;
	res.col = x.col;

	for(int i = 0 ; i < res.row ;i++)
	{
		for(int j = 0 ; j < res.col ; j++)
			res.mat[i][j] = 0;
		res.mat[i][i] = 1;
	}

	while(n)
	{
		if(n&1)	res = MulMod(res,x);
		x = MulMod(x,x);
		n >>= 1;
	}

	return res;
}

int main()
{
    #ifndef ONLINE_JUDGE
//        freopen("input.txt","r",stdin);
//        freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE
    int t;
    int x,y,z;
    LL a,b,c;
    srand(time(NULL));
    int Case=0;
    cin>>t;
    while(t--)
//    while(scanf("%d",&n)==1)
    {
//        printf("Case #%d: ",++Case);
        LL q,p;
        scanf("%I64d%I64d%I64d%I64d%I64d",&n,&a,&b,&c,&p);
        MOD = p-1;
        Matrix m1(3,3);
        memset(m1.mat,0,sizeof(m1.mat));
        m1.mat[0][0] = 1;
        m1.mat[0][1] = 0;
        m1.mat[0][2] = 1;
        Matrix m2(3,3);
        memset(m2.mat,0,sizeof(m2.mat));
        m2.mat[0][0] = c;
        m2.mat[0][1] = 1;
        m2.mat[1][0] = 1;
        m2.mat[2][0] = 1;
        m2.mat[2][2] = 1;
        LL tmp2 = QuickMod(a,b,MOD+1);
        if(n == 1)
        {
            cout<<1<<endl;
            continue;
        }
        else if(n == 2)
        {
            cout<<tmp2<<endl;
            continue;
        }
        Matrix ans = PowMod(m2,n-2);
        LL tmp = (ans.mat[0][0] % MOD + ans.mat[2][0] % MOD) % MOD;
        LL tmp3 = QuickMod(tmp2,tmp,(MOD+1));
        cout<<tmp3 % (MOD+1)<<endl;
    }
    return 0;
}
