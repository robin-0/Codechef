/* بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ */
/* رَّبِّ زِدْنِى عِلْمًا */



#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define OUTPUT freopen("myfile.txt","w",stdout);
#define INPUT freopen("input.txt","r",stdin);
#define PI acos(-1.0)
#define MAX 100005
#define MOD 1000000007
#define EPS 1e-9

long long int bigMod(long long int a , long long int p , long long int M);

long long int bigMod(long long int a , long long int p , long long int M)
{
    if(p==0)
        return 1;
    else if(p==1)
        return a;
    else if(p%2==0)
    {
        long long int temp=bigMod(a,p/2,M);
        return (temp*temp)%M;
    }
    else
    {
        long long int temp=bigMod(a,p/2,M);
        return (((temp*temp)%M) *a)%M;
    }
}

int main ()
{
    long long int T,i,N,x;
    long long int Array[MAX],M,old,n,r,ans,neww;



    scanf("%lld",&T);

    while(T--)
    {
        scanf("%lld%lld%lld",&N,&x,&M);

        for(i=1;i<=N;i++)
        {
            scanf("%lld",&Array[i]);
        }



        n=M-1;
        n%=MOD;
        r=0;
        old=1;
        ans=(Array[x]) %MOD;

        for(i=x-1;i>0;i--)
        {
            n++;
            n%=MOD;
            r++;
            r%=MOD;
            neww=(old * ((n * (bigMod( r ,MOD-2 ,MOD))%MOD)% MOD)) % MOD;
            //printf("\t%lld\n",neww);
            ans= (ans + ((neww*(Array[i] % MOD))%MOD))%MOD;
            old=neww;
        }

        printf("%lld\n",ans);


    }

    return 0;

}

