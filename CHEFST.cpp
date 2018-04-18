/* بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ */
/* رَّبِّ زِدْنِى عِلْمًا */



#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define OUTPUT freopen("myfile.txt","w",stdout);
#define INPUT freopen("input.txt","r",stdin);
#define pi acos(-1.0)
#define MAX 100005


int main()
{
	long long int T,n1,n2,m,max,sum;

	scanf("%lld",&T);

	while(T--)
	{
		scanf("%lld%lld%lld",&n1,&n2,&m);

		if(n2>n1)
		{
			n1=n1^n2;
			n2=n1^n2;
			n1=n1^n2;
		}

		max=(m*(m+1))/2;

		if(max>=n2)
		{
			sum = n1 - n2;
		}
		else
		{
			sum = n1 + n2- 2*max ;
		}

		printf("%lld\n",sum);
	}

    return 0;

}

