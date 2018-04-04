//kengkeng
#include<bits/stdc++.h>
#define Maxn 200005
#define Maxm 5005
#define INF 0xffff;
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

struct Point {
    int x;
    int y;
};

bool cmp1(Point a,Point b) {
    return a.x < b.x;
}

bool cmp2(Point a,Point b) {
    return a.y < b.y;
}
bool cmp3(Point a,Point b) {
    if(a.x!=b.x)
        return a.x < b.x;
    else {
        return a.y<b.y;
    }
}
int main() {
//    char str[Maxn];
//    int num[Maxn];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int n;
    //int num[n];
    while(~scanf("%d",&n)) {
        Point num[Maxn];
        for(int i = 0; i < n; i++) {
            scanf("%d %d",&num[i].x,&num[i].y);
        }
        ll res = 0;
        sort(num,num+n,cmp1);
        int temp = num[0].x;
        ll sum = 0;
        for(int i = 0; i < n; i++){
            if(temp == num[i].x){
                sum++;
            }
            else {
                res += sum*(sum-1)/2;
                temp = num[i].x;
                sum = 1;
            }
        }
        res += sum*(sum-1)/2;
        //cout <<"res"<<res <<endl;
        sort(num,num+n,cmp2);
        temp = num[0].y;
        sum = 0;
        for(int i = 0; i < n; i++){
            if(temp == num[i].y){
                sum++;
            }
            else {
                res += sum*(sum-1)/2;
                temp = num[i].y;
                sum = 1;
            }
        }
        res += sum*(sum-1)/2;
        //cout <<"res"<<res <<endl;
        sort(num,num+n,cmp3);
        Point temp1;
        temp1.x = num[0].x;
        temp1.y = num[0].y;
        sum = 0;
        for(int i = 0; i < n; i++){
            if(temp1.x== num[i].x && temp1.y == num[i].y){
                sum++;
            }
            else {
                res -= sum*(sum-1)/2;
                temp1.x= num[i].x;
                temp1.y = num[i].y;
                sum = 1;
            }
        }
        res -= sum*(sum-1)/2;
        printf("%lld\n",res);
    }
return 0;
}





