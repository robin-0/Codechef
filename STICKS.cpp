﻿ /* بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ */
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
#include <map>
#include <list>
#include <stack>
#include <set>
#include <deque>
 
using namespace std;
 
#define PI acos(-1.0)
#define MAX 1000015
#define MOD 1000000007
#define EPS 1e-9
 
#define OUTPUT freopen("myfile.txt","w",stdout);
#define INPUT freopen("B-large-practice.in","r",stdin);
#define DEBUG(a) cout<<a<<endl;
#define FPEQUAL(FP1,FP2) fabs(FP1-FP2)<=EPS
#define FPLT(FP1,FP2) (FP1-FP2)<=EPS
#define FPGT(FP1,FP2) (FP1-FP2)>=EPS
#define BIGGER(a,b) (a>=b ? a : b)
#define SMALLER(a,b) (a<=b ? a : b)
#define getInt(a) scanf("%d",&a);
#define getLong(a) scanf("%lld",&a);
#define pb push_back
#define ppb pop_back
 
#define INF 1000000000
 
 
 
int main()
{
    //Bismillahir Rahmanir Rahim
    //Rabbi Zidni Ilma
 
    int T;
    
    int arra[2000];
 
    int ffirst,ssecond;
    int N,i;
 
    getInt(T)
 
    while(T--)
    {
        for(i=0;i<2000;i++)
            arra[i]=0;
 
        getInt(N)
 
        while(N--)
        {
            getInt(i);
 
            arra[i]++;
        }
 
        ffirst=-1;
        ssecond=-1;
 
      
        for(i=1999;i>=0;i--)
        {
            if(arra[i]>1)
            {
                if(ffirst==-1)
                {
                    ffirst=i;
 
                    if(arra[i]>3)
                    {
                        ssecond=i;
                    }
                }
 
                else if(ssecond==-1)
                {
                    ssecond=i;
                }
            }
 
            if(ffirst!=-1 && ssecond!=-1)
                break;
        }
 
        
        if(ffirst==-1 || ssecond==-1)
        {
            printf("-1\n");
        }
 
        else
        {
            printf("%d\n",ffirst*ssecond);
        }
    }
 
 
 
    return 0;
}
 
 