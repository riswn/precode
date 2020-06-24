#include <bits/stdc++.h>
using namespace std;
#define m 1000000
#define ll long long
#define IOS ios::sync_with_stdio(0); cout.tie(0);
#define endl "\n"
const ll inf=(1LL<<60)-1;
//vector<ll>vo,ve;
set<ll>s;
ll x,y,n,k,q;
struct query
{
    int index,L,R;
    bool operator<(const query &other)const
    {
        int bl=L/k;
        int br=other.L/k;
        if(bl==br)
            return R<other.R;
        return bl<br;
    }
} query[m+10];
int a[m+10],ans[m+10],sum=0;
void add(int index)
{
    sum+=a[index];
}
void remove(int index)
{
    sum-=a[index];
}
void solve()
{
    cin>>n;
    k=sqrtl(n);
    for(int i=0; i<n; i++)
        cin>>a[i];
    cin>>q;
    for(int i=0; i<q; i++)
    {
        cin>>query[i].L>>query[i].R;
        query[i].index=i;
    }
    sort(query,query+q);
    int L=0,R=-1;
    for(int i=0; i<q; i++)
    {
        while(R<query[i].R)
            add(++R);
        while(L<query[i].L)
            remove(L++);
        while(R>query[i].R)
            remove(R--);
        while(L>query[i].L)
            add(--L);
        //cout<<sum<<endl;
        ans[query[i].index]=sum;
    }
    for(int i=0;i<q;i++)
        cout<<ans[i]<<endl;
}
int main()
{
    IOS;
    solve();
    return 0;
}
//33g5iazc
