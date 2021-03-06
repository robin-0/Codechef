/* بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ */
/* رَّبِّ زِدْنِى عِلْمًا */



#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>

using namespace std;

#define OUTPUT freopen("myfile.txt","w",stdout);
#define INPUT freopen("input.txt","r",stdin);
#define DEBUG(a) cout<<a<<endl;
#define PI acos(-1.0)
#define MAX 1000005
#define MOD 1000000007
#define EPS 1e-9
#define BIGGER(a,b) (a>=b ? a : b)
#define SMALLER(a,b) (a<=b ? a : b)
#define getInt(a) scanf("%d",&a);
#define getLong(a) scanf("%lld",&a);
#define pb push_back


int main()
{
    int T;
    int len,i,j,half,cnt,test;
    char inp[MAX];

    getInt(T)

    while(T--)
    {
        scanf("%s",inp);

        len=strlen(inp);

        if(len==1)
        {
            printf("NO\n");
            continue;
        }

        test=0;

        if(len%2==0)
        {
            i=0;
            j=len/2;

            cnt=0;

            for(;;)
            {
                if(inp[i]!=inp[j])
                    cnt++;

                i++;
                j++;

                if(j==len)
                    break;
            }

            if(cnt==0)
                test=1;
        }

        else
        {
            cnt=0;

            i=0;
            j=len/2;

            for(;;)
            {
                if(inp[i]!=inp[j])
                {
                    i--;
                    cnt++;
                }

                i++;
                j++;

                if(j==len)
                    break;
            }

            if(cnt<2)
                test=1;


            cnt=0;

            i=0;
            j=(len/2)+1;

            for(;;)
            {
                if(inp[i]!=inp[j])
                {
                    j--;
                    cnt++;
                }

                i++;
                j++;

                if(j==len)
                    break;
            }

            if(cnt<2)
                test=1;

        }

        if(test==1)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
