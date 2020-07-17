#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1ll<<45
ll n,m,dis[1005];
vector<ll>g[1005],cost[1005];
struct node
{
    ll id,cost;
    const bool operator<(const node&p)
    const
    {
        return cost>p.cost;
    }
};
void dij(ll s)
{
    for(ll i=0; i<=n; i++)
        dis[i]=inf;
    dis[s]=0;
    priority_queue<node>pq;
    pq.push({s,dis[s]});
    while(!pq.empty())
    {
        node top=pq.top();
        pq.pop();
        int u=top.id;
        for(ll i=0; i<g[u].size(); i++)
        {
            ll v=g[u][i];
            if(dis[v]>dis[u]+cost[u][i])
            {
                dis[v]=dis[u]+cost[u][i];
                pq.push({v,dis[v]});
            }
        }
    }
}
int main()
{
    ll t;
    scanf("%lld",&t);
    for(ll i=1; i<=t; i++)
    {
        scanf("%lld %lld",&n,&m);
        for(int j=0;j<n;j++)
        {
            g[j].clear();
            cost[j].clear();
        }
        while(m--)
        {
            ll u,v,c;
            scanf("%lld %lld %lld",&u,&v,&c);
            g[u].push_back(v);
            g[v].push_back(u);
            cost[u].push_back(c);
            cost[v].push_back(c);
        }
        dij(1);
        if(dis[n]==inf)
        {
            printf("Case %lld: Impossible\n",i);
        }
        else
            printf("Case %lld: %lld\n",i,dis[n]);
            //printf("uyhfguaifg\n");

    }
    return 0;

}
