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

using namespace std;

#define OUTPUT freopen("myfile.txt","w",stdout);
#define INPUT freopen("input.txt","r",stdin);
#define DEBUG(a) cout<<a<<endl;
#define PI acos(-1.0)
#define MAX 100005
#define MOD 100000007
#define EPS 1e-9
#define BIGGER(a,b) (a>=b ? a : b)
#define getInt(a) scanf("%d",&a);


int main()
{
    int T,len1,len2,i,test;
    char S1[MAX],S2[MAX];

    getInt(T)

    while(T--)
    {
        scanf("%s",S1);
        scanf("%s",S2);

        len1=strlen(S1);
        len2=strlen(S2);

        test=0;

        bool one[30]={0,};
        bool two[30]={0,};

        for(i=0;i<len1;i++)
        {
            one[S1[i]-'a']=1;
        }

        for(i=0;i<len2;i++)
        {
            two[S2[i]-'a']=1;
        }

        for(i=0;i<26;i++)
        {
            if(one[i]==1 && two[i]==1)
            {
                test=1;
                break;
            }
        }

        if(test==1)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
 }


