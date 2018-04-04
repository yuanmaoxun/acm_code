#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Maxn 100005
#define Maxm 9
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
char number[26] = {'2', '2', '2', '3', '3', '3', '4', '4', '4', //A~I
                '5', '5', '5', '6', '6', '6', '7', '7', '7', //J~R
                '7', '8', '8', '8', '9', '9', '9', '9'};//S~Z
char str[Maxn][Maxm];
char num[80];
int main(){
    int i, t, j, k, m, n;
    int res, sum, ans, key, len;
    int year, mon, day;
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    scanf("%d", &n);
    k = 0;
    for(i = 0; i < n; i++){
        scanf("%s", num);
        for(j = 0; num[j] != '\0'; j++){
            if(k == 3){
                str[i][k] = '-';
                k++;
            }
            if(num[j] >= 'A' && num[j]<='Z'){
                str[i][k] = number[num[j]-'A'];
            }
            else if(num[j] >= '0' && num[j] <= '9'){
                str[i][k] = num[j];
            }

            else if(num[j] == '-'){
                continue;
            }
            k++;
        }
        k = 0;
    }
    qsort(str, n, 9, strcmp);
    int flag = 0;
    int cnt = 1;
    for(j = 1; j < n; j++){
        if(strcmp(str[j], str[j-1]) == 0){
            flag = 1;
            cnt++;
        }
        else{

            if(cnt > 1){
                printf("%s %d\n", str[j-1], cnt);
            }
            cnt = 1;
        }
    }
    if(cnt > 1){
        printf("%s %d\n", str[j-1], cnt);
    }
    if(!flag)
        printf("No duplicates.\n");
    return 0;
}
