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
#define PI  3.1415926535898
#define ll long long
#define Maxn 55
#define debug puts("bug");
using namespace std;
int main(){
    int i, t, j, k, m, n;
    double res, sum1,sum2, ans, key, len;
    int year, mon, day;
    char String[105];
    string  score;
    int num;
    while(~scanf("%d",&n)) {
        sum1 = sum2 = 0.0;
        while(n--){
            cin >> num;
            cin >> score;
        if(score == "A")  {sum2 += num * 4.0;        sum1 += num;}
        if(score == "A-")  {sum2 += num * 3.7;        sum1 += num;}
        if(score == "B+")  {sum2 += num * 3.3;        sum1 += num;}
        if(score == "B-")  {sum2 += num * 2.7;        sum1 += num;}
        if(score == "B")  {sum2 += num * 3.0;        sum1 += num;}
        if(score == "C+")  {sum2 += num * 2.3;        sum1 += num;}
        if(score == "C")  {sum2 += num * 2.0;        sum1 += num;}
        if(score == "C-")  {sum2 += num * 1.7;        sum1 += num;}
        if(score == "D")  {sum2 += num * 1.3;        sum1 += num;}
        if(score == "D-")  {sum2 += num * 1.0;        sum1 += num;}
        if(score == "F")  {sum2 += num * 0;        sum1 += num;}
        if(score == "N" || score == "P")        sum2 += num * 0;
        }
        if(sum1 == 0 || sum2 == 0)
            cout << "0.00" << endl;
        else
//        cout << sum1 <<endl << sum2 <<endl;
        printf("%.2lf\n",sum2 / sum1);
        }
return 0;
}





