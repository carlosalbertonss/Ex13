#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main (void)
{
	int ganhou=0,firstdoor,premio,wins,porta1=0,porta2=0;
	srand(time(NULL));
	gerapremio=rand()%2;
	if(gerapremio==0)
	{
		portaA=1;
		portaB=0;
		portaC=0;
	}
	if(gerapremio==1)
	{
		portaA=0;
		portaB=1;
		portaC=0;
	}
	if(gerapremio==2)
	{
		portaA=0;
		portaB=0;
		portaC=1;
	}

	geraescolha=rand()%3;
	return 0;
}

			

	
	
		
