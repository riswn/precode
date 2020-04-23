#include<stdio.h>
using namespace std;
#define m 10000009
#define ll long long
bool flag[m+5];
vector<ll>prime;
void seive()
{
    memset(flag,1,sizeof(flag));
    for(ll i=2;i<=m;i++)
    {
        if(flag[i])
        {
            for(ll j=i*i;j<=m;j+=i)
            {
                flag[j]=0;
            }
        }
    }
    for(ll i=2;i<=m;i++)
    {
        if(flag[i])
            prime.push_back(i);
    }
}
int main()
{
   ll t;
   scanf("%lld",&t);
   seive();
   for(ll i=1;i<=t;i++)
   {
       ll n,cnt=0;
       scanf("%lld",&n);
       for(ll j=0;v[j]<=n/2;j++)
       {
           if(flag[n-v[j]])
               cnt++;
       }
       printf("Case %lld: %lld\n",i,cnt);
   }
   return 0;
}
