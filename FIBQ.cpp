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
#define MAX 100005
#define MOD 1000000007
#define EPS 1e-9
#define BIGGER(a,b) (a>=b ? a : b)
#define SMALLER(a,b) (a<=b ? a : b)
#define getInt(a) scanf("%d",&a);
#define getLong(a) scanf("%lld",&a);
#define pb push_back



int array[MAX];

struct matrix
{
    int a;
    int b;
    int c;
    int d;
}I,Fibo,Inv,Inv2;

struct node
{
    int value;
    struct matrix A;
}nodes[4*MAX],Zero,temp;

struct matrix matrixMultiplication( struct matrix A , struct matrix B);
struct matrix matrixExponentiation (struct matrix A , int power);
struct node opeartion( int LC , int RC );
struct node opeartion( struct node LC , struct node RC );
void initialize(int nodeN,int low,int high);
struct node query (int nodeN , int low , int high , int L , int R);
void update (int nodeN , int low , int high , int i , int value);

struct matrix matrixMultiplication( struct matrix A , struct matrix B)
{
    struct matrix C;

    long long int aa = (((((long long int)A.a)*((long long int)B.a)%MOD) + (((long long int)A.b)*((long long int)B.c)%MOD))%MOD);
    long long int bb = (((((long long int)A.a)*((long long int)B.b)%MOD) + (((long long int)A.b)*((long long int)B.d)%MOD))%MOD);
    long long int cc = (((((long long int)A.c)*((long long int)B.a)%MOD) + (((long long int)A.d)*((long long int)B.c)%MOD))%MOD);
    long long int dd = (((((long long int)A.c)*((long long int)B.b)%MOD) + (((long long int)A.d)*((long long int)B.d)%MOD))%MOD);

    C.a=(int)aa;
    C.b=(int)bb;
    C.c=(int)cc;
    C.d=(int)dd;


    return C;
}

struct matrix matrixExponentiation (struct matrix A , int power)
{
    if(power==0)
        return I;
    else if(power==1)
        return A;
    else if(power%2 ==0)
    {
        struct matrix temp = matrixExponentiation(A,power>>1);
        return matrixMultiplication(temp,temp);
    }
    else
    {
        struct matrix temp = matrixExponentiation(A,power>>1);
        return matrixMultiplication( matrixMultiplication(temp,temp) , A);
    }
}

struct node opeartion( int LC , int RC )
{
    struct node temp;
    temp.A = matrixMultiplication(matrixMultiplication(nodes[LC].A,nodes[RC].A),Fibo);

    temp.A.a = ((long long int)temp.A.a + (long long int)nodes[LC].A.a + (long long int)nodes[RC].A.a)%MOD;
    temp.A.b = ((long long int)temp.A.b + (long long int)nodes[LC].A.b + (long long int)nodes[RC].A.b)%MOD;
    temp.A.c = ((long long int)temp.A.c + (long long int)nodes[LC].A.c + (long long int)nodes[RC].A.c)%MOD;
    temp.A.d = ((long long int)temp.A.d + (long long int)nodes[LC].A.d + (long long int)nodes[RC].A.d)%MOD;

    temp.value = (temp.A.a );

    return temp;
}

struct node opeartion( struct node LC , struct node RC )
{
    struct node temp;
    temp.A = matrixMultiplication(matrixMultiplication(LC.A,RC.A),Fibo);

    temp.A.a = ((long long int)temp.A.a + (long long int)LC.A.a + (long long int)RC.A.a)%MOD;
    temp.A.b = ((long long int)temp.A.b + (long long int)LC.A.b + (long long int)RC.A.b)%MOD;
    temp.A.c = ((long long int)temp.A.c + (long long int)LC.A.c + (long long int)RC.A.c)%MOD;
    temp.A.d = ((long long int)temp.A.d + (long long int)LC.A.d + (long long int)RC.A.d)%MOD;

    temp.value = (temp.A.a );

    return temp;
}

void initialize(int nodeN,int low,int high)
{
    if(low==high)
    {
        nodes[nodeN].A=matrixExponentiation(Fibo,array[low]-1) ;
        nodes[nodeN].value=nodes[nodeN].A.a  ;
        return;
    }

    int leftNode = nodeN<<1;
    int rightNode = leftNode + 1;
    int mid=(low+high)>>1;

    initialize(leftNode,low,mid);
    initialize(rightNode,mid+1,high);

    nodes[nodeN] = opeartion(leftNode, rightNode);
}

struct node query (int nodeN , int low , int high , int L , int R)
{
    //printf("\t%d %d\n",low,high);
	if(L<=low && R>=high)
		return nodes[nodeN];
	else if(high<L || R<low)
		return Zero;

	int leftNode = nodeN<<1;
    int rightNode = leftNode + 1;
	int mid=(low+high)>>1;

	struct node left = query(leftNode,low,mid,L,R);
	struct node right = query(rightNode,mid+1,high,L,R);

	return opeartion(left,right);
}

void update (int nodeN , int low , int high , int i , int value)
{
    if(low==high && low==i)
    {
        nodes[nodeN].A=matrixExponentiation(Fibo,value-1) ;
        nodes[nodeN].value=nodes[nodeN].A.a  ;
        return;
    }

    else if(high<i || i<low)
        return ;

    int leftNode = nodeN<<1;
    int rightNode = leftNode + 1;
    int mid=(low+high)>>1;

    update(leftNode,low,mid,i,value);
    update(rightNode,mid+1,high,i,value);

    nodes[nodeN] = opeartion(leftNode, rightNode);
}

int main()
{
    int n,m;
    int i,value,L,R;
    char inp[50];

    I.a=1;
    I.b=0;
    I.c=0;
    I.d=1;

    Fibo.a=1;
    Fibo.b=1;
    Fibo.c=1;
    Fibo.d=0;

    Zero.value=0;
    Zero.A.a=0;
    Zero.A.b=0;
    Zero.A.c=0;
    Zero.A.d=0;

    /*while (1)
    {
        int a;
        getInt(a);

        struct matrix temp = matrixExponentiation(Fibo,a-1);

        printf("%d %d\n%d %d\n",temp.a,temp.b,temp.c,temp.d);
        printf("\t%d\n",temp.a,temp.b);
    }*/

    getInt(n)
    getInt(m)

    for(i=0;i<n;i++)
    {
        getInt(array[i]);
    }

    initialize(1,0,n-1);

    while(m--)
    {
        scanf("%s",inp);

        if(inp[0]=='Q')
        {
            getInt(L)
            getInt(R)

            if(L>R)
            {
                L=L^R;
                R=L^R;
                L=L^R;
            }

            L--;
            R--;

            printf("%d\n",query(1,0,n-1,L,R).value);
        }

        else
        {
            getInt(i)
            getInt(value)

            update(1,0,n-1,i-1,value);
        }

    }





    /*for(i=1;i<20;i++)
    {
        printf("Node %d\n",i);
        printf("%d %d\n%d %d\n",nodes[i].A.a,nodes[i].A.b,nodes[i].A.c,nodes[i].A.d);
        printf("%d\n",nodes[i].value);
    }*/

    return 0;
}


