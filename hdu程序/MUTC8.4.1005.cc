//¿Ó¿Ó
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#define INF 0xffff;
#define PI  3.1415926535898
#define ll long long
#define Maxn 5005
#define debug puts("here is a BUG");
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
using namespace std;

int main(){
    int i, t, j, k, m, n;
    int res, sum, ans, key, len;
    int year, mon, day;
    char str[105];
    int num[5005];
    int score[30][10];
    float  a[]={0,1312,2372.3,520.2,899.5,800.6,1086.5,1402.3,1313.9,1681,2080.7,495.8,737.7,577.5,786.5,1011.8,999.6,1251.2,1520.6,418.8,589.8,633.1,
658.8,650.9,652.9,717.3,762.5,760.4,737.1,745.5,906.4,578.8,762,947,941,1139.9,1350,403,549.5,600,640.1,652,684,702,710.2,719.7,804.4,
731,867,558.3,708.6,834,869.3,1008.4,1170,375.7,502.9,538.1,534.4,527,533.1,540,544.5,547.1,593.4,565.8,573,581,589.3,596.7,603.4,523.5,658.5,
761,770,760,840,880,870,890,1007.1,589.4,715.6,703,812.1,930,1037,380};
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    while(cin>> n >> m)
    {
       if(a[n] < a[m])
            cout << "SECOND BIGGER" << endl;
       else
           cout << "FIRST BIGGER" << endl;
    }
return 0;
}

