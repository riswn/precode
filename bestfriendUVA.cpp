#include<bits/stdc++.h>
using namespace std;
#define m 1000011
#define ull  long long
vector<ull>prime;
bool flag[m];
void seive()
{
    prime.push_back(2);
    for(ull i=3; i*i<m; i+=2)
    {
        if(flag[i]==0)
        {
            for(ull j=i+i; j<m; j+=i+i)
                flag[j]=1;
        }
    }
    for(ull i=3; i<m; i+=2)
    {
        if(flag[i]==0)
            prime.push_back(i);
    }
}
ull etf(ull n)
{
    ull res=n;
    for(ull i=0; i<prime.size() && prime[i]*prime[i]<=n; i++)
    {
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
                n/=prime[i];
            res/=prime[i];
            res*=prime[i]-1;
        }
    }
    if(n!=1)
    {
        res/=n;
        res*=n-1;
    }
    return res;
}
int main()
{
    ull t,n,q,x,s;
    scanf("%lld",&t); seive();
    for(ull i=1; i<=t; i++)
    {
        scanf("%lld %lld",&n,&q);

        vector<ull>d;
        vector<pair<ull,ull>>phi;
        printf("Case %lld\n",i);
        for(ull j=1; j*j<=n; j++)
        {
            if(n%j==0)
            {
                phi.push_back(make_pair(j,etf(n/j)));
                phi.push_back(make_pair(n/j,etf(j)));
            }
        }
        sort(phi.begin(),phi.end());
//        for(int i=0; i<phi.size(); i++)
//            cout<<phi[i].first<<" "<<phi[i].second<<endl;
        for(ull j=1; j<phi.size(); j++)
            phi[j].second+=phi[j-1].second;
        while(q--)
        {
            scanf("%lld",&x);
            ull mid,l=0,hi=phi.size()-1,pos=-1;
            while(l<=hi)
            {
                mid=(l+hi)/2;
                if(phi[mid].first<=x)
                {
                    l=mid+1;
                    pos=mid;
                }
                else
                    hi=mid-1;
            }
            if(pos==-1)
                printf("0\n");
            else
                printf("%lld\n",phi[pos].second);
        }
    }

    return 0;
}
