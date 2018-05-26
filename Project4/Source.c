#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	int l, i, m, n, dl, koniec = 0, p = 0;
	char komenda[100];
	char push[] = "push(obiekt)", pop[] = "pop()", peek[] = "peek()", isEmpty[] = "isEmpty()", size[] = "size()", esc[] = "e";
	dl = 0;

	printf("\n");

	int stos[80];
	int operacje[80];
	int wyjsciowe[80];

	l = 80;

	for (i = 0; i<l; i++)
	{
		stos[i] = (int)NULL;
		operacje[i] = (int)NULL;
		wyjsciowe[i] = (int)NULL;
	}
	/*
	stos[0]=3;
	stos[1]=4;
	stos[2]=2;
	stos[3]=7;


	while(stos[dl]!=(int)NULL)
	{
	dl++;
	}

	//printf("Dlugosc to: %i\n",dl);

	while(koniec<1)
	{

	for(i=0;i<100;i++)
	{
	komenda[i]=(int)NULL;
	}


	printf("Jaka komende chcesz wykonac?\n");
	scanf("%s",komenda);





	if(strcmp(push,komenda)==0)
	{
	scanf("%i",&stos[dl]);
	dl++;
	}

	else if(strcmp(pop,komenda)==0)
	{
	stos[dl-1]=(int)NULL;
	dl--;
	printf("Dlugosc to: %i\n",dl);
	printf("Szczytowy element stosu to: %i\n",stos[dl-1]);
	}

	else if(strcmp(peek,komenda)==0)
	{
	printf("Szczytowy element stosu to: %i\n",stos[dl-1]);
	}

	else if(strcmp(isEmpty,komenda)==0)
	{
	if(stos[0]==NULL)
	{
	printf("True\n");
	}
	else
	{
	printf("False\n");
	}
	}

	else if(strcmp(size,komenda)==0)
	{
	printf("Dlugosc to: %i\n",dl);
	}

	if(strcmp(esc,komenda)==0)
	{
	koniec++;
	}
	}

	*/

	char wejsciowe[] = "((A+B)*C+D)/N";
	//"(A+B)*C";
	//"A*(B+C)-D/(E-F)";
	//"A*(B+C/(D-E))"
	//"A*B+C/((D-E)*F)"
	int g = 0;
	l = strlen(wejsciowe);
	m = 0;
	n = 0;

	for (i = 0; i <= l; i++)
	{
		if ((wejsciowe[i] == '*') || (wejsciowe[i] == '/') || (wejsciowe[i] == '('))
		{
			operacje[m] = wejsciowe[i];
			m++;
		}

		else if ((wejsciowe[i] == '+') || (wejsciowe[i] == '-'))
		{
			if (m - 1 >= 0)
			{
				if ((operacje[m - 1] != '*') && (operacje[m - 1] != '/'))
				{

					operacje[m] = wejsciowe[i];
					m++;
				}
				else
				{
					wyjsciowe[n] = operacje[m - 1];
					n++;
					operacje[m - 1] = wejsciowe[i];
				}
			}
		}
		//============================================


		else if ((wejsciowe[i] == ')'))
		{
			g = m;
			g--;
			m--;


			while (operacje[g] != '(')
			{
				if (g >= 0)
				{
					wyjsciowe[n] = operacje[g];
					n++;

					operacje[g] = (int)NULL;
					g--;
					m--;
				}
			}




		}

		//--------------------------------------------
		else
		{
			wyjsciowe[n] = wejsciowe[i];
			n++;
		}

		if (i == l)
		{
			//printf("%i",l);
			m--;
			n--;
			while (m >= 0)
			{
				if (operacje[m] != (int)NULL)
				{
					wyjsciowe[n] = operacje[m];
					operacje[m] = (int)NULL;
					m--;
					n++;
				}
			}
		}

	}




	for (i = 0; i<l; i++)
	{
		printf("%c", wejsciowe[i]);
	}

	printf("\n");

	for (i = 0; i<15; i++)
	{
		printf("%c", operacje[i]);
	}

	printf("\n");

	for (i = 0; i<15; i++)
	{
		printf("%c", wyjsciowe[i]);
	}

	printf("\n");

	system("PAUSE");

	return 0;
}
