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
#include <map>
#include <list>
#include <stack>
#include <set>
#include <deque>

using namespace std;

#define OUTPUT freopen("myfile.txt","w",stdout);
#define INPUT freopen("in.in","r",stdin);
#define DEBUG(a) cout<<a<<endl;
#define PI acos(-1.0)
#define MAX 100005
#define MOD 1000000007
#define EPS 1e-9
#define BIGGER(a,b) (a>=b ? a : b)
#define SMALLER(a,b) (a<=b ? a : b)
#define getInt(a) scanf("%d",&a);
#define getLong(a) scanf("%lld",&a);
#define pb push_back
#define ppb pop_back
#define setBit(a,n) a|(1<<n)
#define setBitStatement(a,n) a|=1<<n;
#define resetBit(a,n) a&=~(1<<n);
#define checkBit(a,n) ((a&(1<<n))!=0)
#define toggleBit(a,n) a^=1<<n;
#define doubleingEqual(a,b) (fabs(a-b)<=EPS)
#define doubleingLess(a,b) ((b-a)>=EPS)
#define doubleingGreater(a,b) ((a-b)>=EPS)

#define INF 1000000000
 
long long int arr[100005];

int main()
{
	// Bismillahir Rahmanir Rahim 
	// Rabbi Zidni Ilma 

	int T,N;
	long long int summ,minn,temp;
	int ans;
	int i;

	getInt(T)

	while(T--)
	{
		getInt(N)

		summ = 0 ;

		for(i=0;i<N;i++)
		{
			getLong(arr[i])

			summ+=arr[i];
		}

		ans = 1 ;
		minn = summ + arr[0];

		for(i=1;i<N;i++)
		{
			temp = summ + arr[i];

			if(temp<minn)
			{
				minn=temp;
				ans = i+1;
			}
		}

		printf("%d\n",ans);
	}


    return 0;
}