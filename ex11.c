#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> /* de espaco aqui1!!!!!!! */
#include "libeco.h"

#define LA 10
#define CA 10
#define LB (CA)
#define CB 10
//variaveis do problema
int A[LA][CA]={{0}},
	B[LB][CB]={{0}},
	C[LA][CB]={{0}},
	t1A, t1B, t2A, t2B, tm1, tm2;
///as funçoes preenche agora iram preencher as matrizes completas
void *preenche1A(void *);//função 1 que preenchera a
void *preenche1B(void *);//função 1 que prencherá b
void *preenche2A(void *);//função 2 que prencherá a
void *preenche2B(void *);//função 2 que preeenchera b
void *multiplica1(void *);
void *multiplica2(void *);
volatile char lk=UNLOCKED;
int main(void) //sem espaco
{
	pthread_t p1A, p1B, p2A,p2B,m1,m2;
	t1A=pthread_create(&p1A,NULL,preenche1A,NULL); //linha 26
	t1B=pthread_create (&p1B,NULL,preenche1B,NULL);
	t2A=pthread_create (&p2A,NULL,preenche2A,NULL);
	t2B=pthread_create (&p2B,NULL,preenche2B,NULL);
	if(t1A || t1B || t2A || t2B)
		exit(EXIT_FAILURE);
	pthread_join (p1A,NULL);
	pthread_join(p1B,NULL);
	pthread_join(p2A,NULL);
	pthread_join(p2B,NULL);
	tm1=pthread_create(&m1,NULL,multiplica1,NULL);
	tm2=pthread_create(&m2,NULL,multiplica2,NULL);
	if(tm1 || tm2)
		exit(EXIT_FAILURE);
	pthread_join(m1,NULL);
	pthread_join(m2,NULL);
	return EXIT_SUCCESS;
}
void *preenche1A (void *p1A)
{
	int l,c;
	for(l=0;l<LA;l++)
		for(c=0;c<CA;c++)
			while (getlock(&lk));
			if (A[l][c]==0)
			{
				A[l][c]=1;
				printf("P1A= A[%d][%d]=%d\n",l,c,A[l][c]);
				unlock(&lk);
				delay(10);
			}
			
	return NULL;
}
void *preenche1B (void *p1B)
{
	int l,c;
	for(l=0;l<LB;l++)
		for(c=0;c<CB;c++)
			while(getlock(&lk));
			if(B[l][c]==0)
			{
				B[l][c]=1;
				printf("P1B= B[%d][%d]=%d\n",l,c,B[l][c]);
				unlock(&lk);
				delay(10);
			}
			
	return NULL;
}
void *preenche2A (void *p2A)
{
	int l,c;
	for(l=0;l<LA;l++)
		for(c=0;c<CA;c++)
			while(getlock(&lk)); // falta ponto-e-virgula!!!
			if(A[l][c]==0)
			{
				A[l][c]=2;
				printf("P2A= A[%d][%d]=%d\n",l,c,A[l][c]);
				unlock(&lk);
				delay(10);
			}
			else;
			
	return NULL;
}
void *preenche2B (void *p2B)
{
	int l,c;
	for (l=0;l<LB;l++)
		for (c=0;c<CB;c++)
			while(getlock(&lk));
			if(B[l][c]==0)
			{
				B[l][c]=2;
				printf("P2B= B[%d][%d]=%d\n",l,c,B[l][c]);
				unlock(&lk);
				delay(100);
			}
	return NULL;
}
void *multiplica1 (void *m1)
{
	int c,i,m,n;
 	c=CB;
	for(m=0;m<LA;m++)
		for(n=0;n<CB;n++)
			for(i=0;i<c;i++)
				
				while(getlock(&lk));
				if(C[m][n]==0)
				{
					C[m][n]+=((A[m][i])*(B[i][n]));
					printf("M1= C[%d][%d]=%d\n",m,n,C[m][n]);
					unlock(&lk);
					delay(10);
				}
				
	return NULL;
}
void *multiplica2 (void *m2)
{
	int c,i,m,n;
	c=CB;
	for(m=0;m<LA;m++)
		for(n=0;n<CB;n++)
			for(i=0;i<c;i++)
				while(getlock(&lk));
				if(C[m][n]==0)
				{
					C[m][n]+=((A[m][i])*(B[i][n]));
					printf("M2= C[%d][%d]=%d\n",m,n,C[m][n]);
					unlock(&lk);
					delay(10);
				}
	return NULL;
}

	
