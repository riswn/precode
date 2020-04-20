#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define m 1000003
ll bigmod(ll n,ll p)
{
    ll res=1%m;
     n=n%m;
    while(p)
    {
        if(p&1)
            res=(res*n)%m;
        n=(n*n)%m;
        p>>=1;
    }
    return res;
}
int main()
{
    int t;
    scanf("%d",&t);
    ll fact[m+5];
    fact[0]=1;
    for(ll i=1;i<=m;i++)
        fact[i]=(i*fact[i-1])%m;
    for(ll i=1;i<=t;i++)
    {
        ll n,k;
        scanf("%lld %lld",&n,&k);
        ll v=(fact[k]*fact[n-k])%m;
        ll ans=(fact[n]*bigmod(v,m-2))%m;
        printf("Case %lld: %lld\n",i,ans);
    }
    return 0;
}
