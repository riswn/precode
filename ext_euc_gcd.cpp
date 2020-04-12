#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll *X,*Y;
vector<ll>exeuc(ll a,ll b)
{
    ll x2,x1,y2,y1,x,y,r1,r2,r,q;
    x2=1;
    y2=0;
    x1=0;
    y1=1;
    for(r2=a,r1=b; r1!=0; r2=r1,r1=r,x2=x1,y2=y1,x1=x,y1=y)
    {
        q=r2/r1;
        r=r2%r1;
        x=x2-(q*x1);
        y=y2-(q*y1);
    }
    vector<ll>res;
    res.push_back(x2);
    res.push_back(y2);
    res.push_back(r2);
    return res;

}
int main()
{
    ll a,b;
    while(scanf("%lld %lld",&a,&b)==2)
    {
        vector<ll>res=exeuc(a,b);
        printf("%lld %lld %lld\n",res[0],res[1],res[2]);
    }
    return 0;
}
