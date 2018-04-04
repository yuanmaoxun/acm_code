#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <set>
using namespace std;
struct inter {
    int a;int b;int c;int d;
    bool operator<(const inter  &temp)const {
        if(this->a!=temp.a)
            return (this->a<temp.a);
        else if(this->b != temp.b)
           return (this->b<temp.b);
        else if(this->c != temp.c)
           return (this->c<temp.c);
        else if(this->d != temp.d)
           return (this->d<temp.d);
        else return false;
    }
}ip[1005], PIN,temp1;
set<inter> res;
int main(){
    int i,j,m,n,t,ans[1005];
    int Case;
        cin >> t;
        Case = 0;
        while(t--){
                Case++;
            cin >> n >> m;
            for(i = 0;i < n;i++)
                scanf("%d.%d.%d.%d",&ip[i].a,&ip[i].b,&ip[i].c,&ip[i].d);
            for(i = 0;i < m;i++) {
                res.clear();
                scanf("%d.%d.%d.%d",&PIN.a,&PIN.b,&PIN.c,&PIN.d);
                for(j = 0;j < n;j++) {
                    temp1.a = PIN.a&ip[j].a  ;
                    temp1.b = PIN.b&ip[j].b  ;
                    temp1.c = PIN.c&ip[j].c ;
                    temp1.d = PIN.d&ip[j].d  ;
                    res.insert(temp1);
                    }
                ans[i]=res.size();
            }
            printf("Case #%d:\n",Case);
            for(i=0;i<m;i++)
                cout << ans[i] << endl;
    }
return 0;
}
