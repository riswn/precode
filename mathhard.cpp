
#include<bits/stdc++.h>
using namespace std;
#define m 5000006
#define ull unsigned long long
vector<ull>phi(m);
void etf()
{
    //phi[0]=0;
    //phi[1]=1;
    for(ull i=0; i<=m; i++)
        phi[i]=i;
    for(ull i=2; i<=m; i++)
    {
        if(phi[i]==i)
        {
            for(ull j=i; j<=m; j+=i)
            {
                phi[j]-=phi[j]/i;
            }
        }
    }
    for(ull i=1; i<m; i++)
    {
        phi[i]=phi[i-1]+phi[i]*phi[i];
        //cout<<phi[i]<<endl;
    }
}
int main()
{
    ull a,b,t,s;
    scanf("%llu",&t);
    etf();
    for(ull j=1; j<=t; j++)
    {
        s=0;
        scanf("%llu %llu",&a,&b);

        printf("Case %llu: %llu\n",j,phi[b]-phi[a-1]);
    }
    return 0;
}
