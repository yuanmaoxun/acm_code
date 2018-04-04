//kengkeng
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
#define Maxn 1005
#define Maxm 5005
#define INF 0x7fffffff
#define ll long long
#define Exit exit(0);
#define Mod 1000000007
#define PI  3.1415926535898
#define Pause system("pause");
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1|1
#define debug puts("here is a BUG");
#define Clear(name, num) memset(name, num, sizeof(name));

using namespace std;

int n,p;
int Graph[Maxn][Maxn];  //������Ķ���ͼ
int ans;  //���ƥ����
int sx[Maxn],sy[Maxn];  //path��������ʾ��DFS�㷨�����������������״̬������
int cx[Maxn],cy[Maxn];  //��õ�ƥ�������X�����еĶ���iƥ���Y�����еĶ���cx[i]
/*
��X�����еĶ�����������������������Ѱ������·
����������·ֻ��ʹ��ǰ��ƥ������1
*/

int path(int u) {
    sx[u] = 1;
    for(int v = 1; v <= n; v++) {
        if( (Graph[u][v] > 0) && (!sy[v]) ) {   //v��u�ڽ�vδ���ʹ�
            sy[v] = 1;
            //���vû��ƥ��������v�Ѿ�ƥ���ˣ�����y[v]���������ҵ�һ������·
            if(!cy[v] ||path(cy[v])) {
                //�ڻ���ʱ�޸�����·�ϵ�ƥ�䣬�Ӷ���ƥ������1��
                cx[u] = v;
                cy[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int MaxMatch() {   //�������㷨
    ans = 0;
    memset(cx,0,sizeof(cx));
    memset(cy,0,sizeof(cy));
    //����A��B���������ģʽ0��������ɿ��Թ�����ģʽ0����ҵ����Ҫ��������
    for(int i = 1; i <= p; i++) {
        if( !cx[i] ) {
            memset(sx,0,sizeof(sx));
            memset(sy,0,sizeof(sy));
            ans += path(i);
        }
    }
    //cout << "ans:" << ans <<endl;
    return 0;
}

int main(){
    int i,j,k,m;
    int u,v;
    int T;

    while(~scanf("%d",&T)) {
        while(T--) {
            scanf("%d%d",&p,&n);
            memset(Graph,0,sizeof(Graph));
            for(int i = 1; i <= p; i++) {
                scanf("%d",&m);
                for(int j = 1; j <= m; j++) {
                    scanf("%d",&v);
                    Graph[i][v] = 1;
                }
            }
            MaxMatch();
            //cout << "ans:" << ans <<endl;
            if(ans == p)
                puts("YES");
            else
                puts("NO");
        }
    }
return 0;
}



