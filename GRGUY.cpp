/* بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ */
/* رَّبِّ زِدْنِى عِلْمًا */



#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define OUTPUT freopen("myfile.txt","w",stdout);
#define INPUT freopen("input.txt","r",stdin);

int main(void) {
	
	char line1[200005],line2[200005];
	int way1,way2,T,i,n,root;
	
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",line1);
		scanf("%s",line2);
		n=strlen(line1);
		
		/*way 1*/
		if(line1[0]=='#')
			way1=-1;
		else
		{
			way1=0;
			root=1;
			for(i=1;i<n;i++)
			{
				if(root==1)
				{
					if(line1[i]=='#')
					{
						if(line2[i]!='#')
						{
							root=2;
							way1++;
						}
						else if((i<(n-1))&&(line2[i+1]!='#'))
						{
							root=2;
							i++;
							way1++;
						}
						else
						{
							way1=-1;
							break;
						}
					}
				}
				
				if(root==2)
				{
					if(line2[i]=='#')
					{
						if(line1[i]!='#')
						{
							root=1;
							way1++;
						}
						else if((i<(n-1))&&(line1[i+1]!='#'))
						{
							root=1;
							i++;
							way1++;
						}
						else
						{
							way1=-1;
							break;
						}
					}
				}
				
			}
		}
		
		/*way 2*/
		if(line2[0]=='#')
			way2=-1;
		else
		{
			way2=0;
			root=2;
			for(i=1;i<n;i++)
			{
				if(root==1)
				{
					if(line1[i]=='#')
					{
						if(line2[i]!='#')
						{
							root=2;
							way2++;
						}
						else if((i<(n-1))&&(line2[i+1]!='#'))
						{
							root=2;
							i++;
							way2++;
						}
						else
						{
							way2=-1;
							break;
						}
					}
				}
				
				if(root==2)
				{
					if(line2[i]=='#')
					{
						if(line1[i]!='#')
						{
							root=1;
							way2++;
						}
						else if((i<(n-1))&&(line1[i+1]!='#'))
						{
							root=1;
							i++;
							way2++;
						}
						else
						{
							way2=-1;
							break;
						}
					}
				}
				
			}
		}
		
		if(way1!=-1||way2!=-1)
		{
			printf("Yes\n");
			if(way1==-1)
				printf("%d\n",way2);
			else if(way2==-1)
				printf("%d\n",way1);
			else
				printf("%d\n", way1 < way2 ? way1 : way2);
		
		}
		else printf("No\n");
	}
	
	
	return 0;
}
