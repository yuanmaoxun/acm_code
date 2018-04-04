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
    int res, sum, ans, key, len;
    double  Rm, R, r, x, y, vx, vy;
    char String[105];
    while(cin >> Rm >> R >> r >> x >> y >> vx >> vy) {
        double flag1 =  (y * vx - vy * x  ) * (y * vx - vy * x  ) / ( vy * vy + vx * vx)  - (R + r) * (R + r);
        double flag2 =  (y * vx - vy * x  ) * (y * vx - vy * x  ) / ( vy * vy + vx * vx)  - (Rm + r) * (Rm + r);
        if(flag1 < 0 && vx * (-x) + vy * (-y) > 0){   //***与R相交
            if(flag2 >= 0){   //与Rm不相交
                double l1 = (R + r) * (R + r) - (y * vx - vy * x  ) * (y * vx - vy * x  ) / ( vy * vy + vx * vx);
 //               cout << l1 << endl;
                double t1 = sqrt(l1) / sqrt(vx * vx + vy * vy);
                printf("%.3lf\n",t1 * 2);
            }
            else {
                double l2 =  (R + r) * (R + r) - (y * vx - vy * x  ) * (y * vx - vy * x  ) / ( vy * vy + vx * vx) ;
                double l3 =  (Rm + r) * (Rm + r) - (y * vx - vy * x  ) * (y * vx - vy * x  ) / ( vy * vy + vx * vx);
                double l = sqrt(l2) - sqrt(l3);
//                cout << l2 << endl << l3 << endl << l <<endl;
                double t2 = l / sqrt(vx * vx + vy *vy);
                printf("%.3lf\n",t2 * 2);
//                debug
            }
        }
        else
            cout << "0.000" << endl;
    }
return 0;
}






