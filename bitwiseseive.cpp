#define MAX 100000000//max num to prime
#define LMT 10000 //sqrt(MAX)
 
int flag[MAX/64];
int prime[100000000],total;
 
#define chkC(n) (flag[n>>6]&(1<<((n>>1)&31)))
#define setC(n) (flag[n>>6]|=(1<<((n>>1)&31)))
 
void sieve()
{
    unsigned i,j,k;
 
    flag[0]|=0;
    for(i=3;i<LMT;i+=2)
        if(!chkC(i))
            for(j=i*i,k=i<<1;j<MAX;j+=k)
                setC(j);
 
    prime[(j=0)++] = 2;//prime starts from 0 position
    for(i=3;i<MAX;i+=2)
        if(!chkC(i))
        {
            prime[j++] = i;
            //printf("%d\n",primes[j-1]);
        }
    total = j-1;
