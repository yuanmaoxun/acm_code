#include<stdio.h>
#include<stack>
using namespace std;
int main()
{
    int t,n;
    char c,x,s[100005];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        getchar();

        if(n==2)
        {
            scanf("%c%c",&x,&c);
            if(x==')'&&c=='(')
            printf("Yes\n");
            else
            printf("No\n");
            continue;
        }
        scanf("%s",s);
        int flag=0;
        int flag1=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                flag+=1;
            }
            else if(s[i]==')')
            {
                flag-=1;
            }
            if(flag<0)
            {
                flag1++;
                flag+=2;
            }
        }
        if(flag==2&&flag1==1)
        printf("Yes\n");
        else if(flag==0&&flag1==0)
        printf("Yes\n");
        else
        printf("No\n");
    }
}