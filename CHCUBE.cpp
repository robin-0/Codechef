/* بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ */
/* رَّبِّ زِدْنِى عِلْمًا */



#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main()
{
    int T,col[7],i,j,test;
    char inp[20];
    scanf("%d",&T);
    while(T--)
    {
        for(i=0;i<6;i++)
        {
            scanf("%s",inp);

            if(!strcmp(inp,"black"))
                col[i]=0;
            else if(!strcmp(inp,"blue"))
                col[i]=1;
            else if(!strcmp(inp,"red"))
                col[i]=2;
            else if(!strcmp(inp,"green"))
                col[i]=3;
            else if(!strcmp(inp,"yellow"))
                col[i]=4;
            else if(!strcmp(inp,"orange"))
                col[i]=5;

        }

        if(  ((col[1]==col[2])&&(col[2]==col[5])) ||  ((col[1]==col[3])&&(col[3]==col[5])) ||  ((col[0]==col[3])&&(col[3]==col[5])) ||  ((col[0]==col[2])&&(col[2]==col[5])) ||  ((col[1]==col[2])&&(col[2]==col[4])) ||  ((col[1]==col[3])&&(col[3]==col[4])) ||  ((col[0]==col[2])&&(col[2]==col[4])) ||  ((col[0]==col[3])&&(col[3]==col[4])) )
                printf("YES\n");
        else
                printf("NO\n");
    }


    return 0;
}
