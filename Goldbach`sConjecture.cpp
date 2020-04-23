#include<stdio.h>
using namespace std;
#define m 10000009
#define ll long long
bool flag[m+5];
vector<ll>prime;
void seive()
{
    memset(flag,1,sizeof(flag));
    ll val=sqrt(m);
    for(ll i=2;i<=val;i++)
    {
        if(flag[i])
        {
            for(ll j=i;j*i<=m;j++)
            {
                flag[i*j]=0;
            }
        }
    }
    for(ll i=2;i<=m;i++)
    {
        if(flag[i])
            prime.push_back(i);
    }
}
ll findsol(ll n)
{
    ll res=0;
    for(ll i=2;i<=n/2;i++)
    {
        if(flag[i] && flag[n-i])
            res++;
    }
    return res;
}
int main()
{
   ll t;
   scanf("%lld",&t);
   seive();
   for(ll i=1;i<=t;i++)
   {
       ll n;
       scanf("%lld",&n);
       printf("Case %lld: %lld\n",i,findsol(n));
   }
   return 0;
}
