# include <iostream>
# include <cstdio>
# include <cstring>

using namespace std;

char list[10000009];
int divMod(char* ch,int num)
{
    int s = 0;
    for(int i=0; ch[i]!='\0'; i++)
        s = (s*10+ch[i]-'0')%num;

    return s;
}

int main()
{
    int test,num,m;
    int cas=0;
    while(~scanf("%s",list))
    {
        if(divMod(list,73) == 0&& divMod(list,137) == 0)
        {
            printf("Case #%d: YES\n",++cas);
        }
        else
        {
            printf("Case #%d: NO\n",++cas);
        }
    }
    return 0;
}
