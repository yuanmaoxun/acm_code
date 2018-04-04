// Geometry.cpp
// 1002.cpp
#include <ios>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <cstdio>
#include <cwchar>
#include <iosfwd>
#include <limits>
#include <locale>
#include <memory>
#include <string>
#include <vector>
#include <cassert>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <cwctype>
#include <fstream>
#include <iomanip>
#include <istream>
#include <numeric>
#include <ostream>
#include <sstream>
#include <utility>
#include <iostream>
#include <iterator>
#include <valarray>
#include <algorithm>
#include <exception>
#include <stdexcept>
#include <streambuf>
#include <functional>
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
const int MAXN = 1005;
using namespace std;

#define Vector Point

#define ChongHe 0
#define NeiHan 1
#define NeiQie 2
#define INTERSECTING 3
#define WaiQie 4
#define XiangLi 5

int dcmp(double x) { return fabs(x) < eps ? 0 : (x < 0 ? -1 : 1); }

struct Point {
    double x, y;

    Point(const Point& rhs): x(rhs.x), y(rhs.y) { } //拷贝构造函数
    Point(double x = 0.0, double y = 0.0): x(x), y(y) { }   //构造函数

    friend istream& operator >> (istream& in, Point& P) { return in >> P.x >> P.y; }
    friend ostream& operator << (ostream& out, const Point& P) { return out << P.x << ' ' << P.y; }

    friend Vector operator + (const Vector& A, const Vector& B) { return Vector(A.x+B.x, A.y+B.y); }
    friend Vector operator - (const Point& A, const Point& B) { return Vector(A.x-B.x, A.y-B.y); }
    friend Vector operator * (const Vector& A, const double& p) { return Vector(A.x*p, A.y*p); }
    friend Vector operator / (const Vector& A, const double& p) { return Vector(A.x/p, A.y/p); }
    friend bool operator == (const Point& A, const Point& B) { return dcmp(A.x-B.x) == 0 && dcmp(A.y-B.y) == 0; }
    friend bool operator < (const Point& A, const Point& B) { return A.x < B.x || (A.x == B.x && A.y < B.y); }

    void in(void) { scanf("%lf%lf", &x, &y); }
    void out(void) { printf("%lf %lf", x, y); }
};

typedef vector<Point> Polygon;

struct Circle {
    Point c;    //圆心
    double r;   //半径

    Circle() { }
    Circle(const Circle& rhs): c(rhs.c), r(rhs.r) { }
    Circle(const Point& c, const double& r): c(c), r(r) { }

    Point point(double ang) const { return Point(c.x + cos(ang)*r, c.y + sin(ang)*r); } //圆心角所对应的点
    double area(void) const { return PI * r * r; }
};

double Dot(const Vector& A, const Vector& B) { return A.x*B.x + A.y*B.y; }  //点积
double Length(const Vector& A){ return sqrt(Dot(A, A)); }
double Angle(const Vector& A, const Vector& B) { return acos(Dot(A, B)/Length(A)/Length(B)); }  //向量夹角
double Cross(const Vector& A, const Vector& B) { return A.x*B.y - A.y*B.x; }    //叉积
double Area(const Point& A, const Point& B, const Point& C) { return fabs(Cross(B-A, C-A)); }



//两圆位置关系判定
int GetCircleLocationRelation(const Circle& A, const Circle& B) {
    double d = Length(A.c-B.c);
    double sum = A.r + B.r;
    double sub = fabs(A.r - B.r);
    if (dcmp(d) == 0) return dcmp(sub) != 0;
    if (dcmp(d - sum) > 0) return XiangLi;
    if (dcmp(d - sum) == 0) return WaiQie;
    if (dcmp(d - sub) > 0 && dcmp(d - sum) < 0) return INTERSECTING;
    if (dcmp(d - sub) == 0) return NeiQie;
    if (dcmp(d - sub) < 0) return NeiHan;
}

//两圆相交的面积
double GetCircleIntersectionArea(const Circle& A, const Circle& B) {
    int rel = GetCircleLocationRelation(A, B);
    if (rel < INTERSECTING) return min(A.area(), B.area());
    if (rel > INTERSECTING) return 0;
    double dis = Length(A.c - B.c);
    double ang1 = acos((A.r*A.r + dis*dis - B.r*B.r) / (2.0*A.r*dis));
    double ang2 = acos((B.r*B.r + dis*dis - A.r*A.r) / (2.0*B.r*dis));
    return ang1*A.r*A.r + ang2*B.r*B.r - A.r*dis*sin(ang1);
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
   freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    int T;
    double n;
    while(~scanf("%d",&T)) {
    	while(T--) {
    		scanf("%lf",&n);
	    	Point a ,b;
	    	a.x = 0;
	    	a.y = 0;
	    	b.x = -n/2.0;
	    	b.y = n/2.0;
	    	/*Circle B = new Circle(a,n);
            Circle S = new Circle(b,(n/2.0));*/
            Circle B,S;
            B.c = a;B.r = n;
            S.c = b;S.r = (n/2.0);
	    	//cout << B.area()<<endl;;
	    	double ans = GetCircleIntersectionArea(B,S);
	    	//cout << ans <<endl;;
	    	double res = S.area()-ans;
	    	printf("%.2lf\n",res*2);
	    }
    }
    return 0;
}