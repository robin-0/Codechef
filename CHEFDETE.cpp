/* بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ */
/* رَّبِّ زِدْنِى عِلْمًا */



#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define OUTPUT freopen("myfile.txt","w",stdout);
#define INPUT freopen("input.txt","r",stdin);
#define pi acos(-1.0)
#define MAX 200005
#define MOD 1000000007
#define INF 1000000



int main ()
{
    int N,i,temp,array[MAX]={0,};

    scanf("%d",&N);

    for(i=0;i<N;i++)
    {
        scanf("%d",&temp);
        array[temp]=1;
    }

    for(i=1;i<=N;i++)
    {
        if(array[i]==0)
        {
            printf("%d",i);
            i++;
            break;
        }
    }

    for(;i<=N;i++)
    {
        if(array[i]==0)
        {
            printf(" %d",i);

        }
    }

    printf("\n");

    return 0;

}

