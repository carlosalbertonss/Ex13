#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main (void)
{
	int mudar,flag=0,i,novaescolha=0,ganhoumudando=0,ganhousemmudar=0,perdeusemmudar=0,perdeumudando=0,porta1=0,porta2=0,porta3=0,escolho1,escolho2,escolho3,gerapremio,geraescolha;
	srand(time(NULL));
	//bloco responsavel por gerar em que porta fica o premio
	
	for(i=0;i<=100;i++)
	{

		gerapremio=rand()%2;
		if(gerapremio==0)
		{
			porta1=1;
			porta2=0;
			porta3=0;
		}
		if(gerapremio==1)
		{
			porta1=0;
			porta2=1;
			porta3=0;
		}
		if(gerapremio==2)
		{
			porta1=0;
			porta2=0;
			porta3=1;
		}
		//bloco responsavel por gerar a primeira escolha do jogador
	
		geraescolha=rand()%3;
		if(geraescolha==0)
			escolho1=1;
		if(geraescolha==1)
			escolho2=1;
		if(geraescolha==2)
			escolho3=1;
		//bloco responsavel por saber se ganhou na primeira jogada e caso ganhe volte uma contaguem
	
		if(escolho1==porta1)
		{
			novaescolha=1;
			i--;
		}
		if(escolho2==porta2)
		{	
			novaescolha=1;
			i-;
		}
		
		
		if(escolho3==porta3)
		{
			novaescolha=1;
			i--;
		}
	
		//bloco responsavel por gerar a segunda escolha garatid pelo ultimo if que que a primeira é errada,a variavel mudar vai fazer a esolha do jogador, se mudar=0, ele ficou com a primeira opção,se nao ele mudou, a flag é para que apenas cada escolha seja avaliada a cada loop.
		if((novaescolha==0)&&(flag==0))
		{
			mudar=rand()%1;
			if(escolho1==1)
			{	
				escolho1=0;
				if(mudar==0)
				{	
					escolho2=1;
					if(escolho2==porta2)
						ganhousemmudar++;
					else
						perdeusemmudar++;
				}
				if(mudar==1)
				{	
					escolho3=1;
					if(escolho3==porta3)
						ganhoumudando++;
					else
						perdeumudando++;
				}
				flag=1;
			}
			if((escolho2==1)&&(flag==0))
			{	
				escolho2=0;
				if(mudar==0)
				{
					escolho1=1;
					if(escolho1==porta1)
						ganhousemmudar++;
					else
						perdeusemmudar++;
				}
				if(mudar==1)
				{
					escolho3=1;
					if(escolho3==porta3)
						ganhoumudando++;
					else
						perdeumudando++;
				}
				flag=1;
			}
			if((escolho3==1)&&(flag==0))
			{
				escolho3=0;
				if(mudar==0)
				{
					escolho1=1;
					if(escolho1==porta1)
						ganhousemmudar++;
					else
						perdeusemmudar++;
				}
				if(mudar==1)
				{
					escolho2=1;
					if(escolho2==porta2)
						ganhoumudando++;
					else
						perdeumudando++;
				}
				flag=1;
			}
		}
		//zerando as variaveis paranova contaguem
		escolho1=0;
		escolho2=0;
		escolho3=0;
		flag=0;
		novaescolha=0;

	}

	printf("Ganhou mudando :%d,Ganhou sem mudar :%d.\n",ganhoumudando,ganhousemmudar);
	return 0;

}

			

	
	
		
