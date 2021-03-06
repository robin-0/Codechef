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
#define EPS 1e-8


int main ()
{
    int T;
    long long int row,column,k,x,y,heart;
    double nume,deno;
    double ans;

    scanf("%d",&T);

    while(T--)
    {
        ans=0.0;
        scanf("%lld%lld%lld",&row,&column,&k);
        deno=(double)((row*(row+1))/2) * (double)((column*(column+1))/2);
//printf("%.7lf\n",deno+EPS);
        while(k--)
        {
            scanf("%lld",&heart);

            x=heart%column;
            y=(heart/column) + 1 ;

            if(x==0)
            {
                x=column;
                y--;
            }

            nume = (double)(x*y) * (double)((column-x+1)*(row-y+1));
//printf("%.7lf\n",nume+EPS);
            ans+=(nume)/(deno);
        }

        printf("%.7lf\n",ans+EPS);

    }



    return 0;

}

