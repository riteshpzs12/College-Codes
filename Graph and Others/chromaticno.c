#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void check(int,int);
int* notadjset(int,int,int);

int vd[30];
int e[30][2];
	

void main()
{
	int i, V, E, v1, v2, l;
	printf("enter the number of vertices(<15) and the number of edges(<30)\n");
	scanf("%d%d",&V, &E);
	printf("enter the the edges(i.e for AB edge enter A & B in perfect sequence, and  the name is 0 - 14)\n");
	for(i=0; i<E; i++)
	{
		scanf("%d%d", &v1, &v2);
		vd[v1]++;
		vd[v2]++;
		e[i][0] = v1;
		e[i][1] = v2;
		if(v1 == v2)
			printf("self loop is a contradictory case for graph colouring\n");
	}
	check(E,V);
	int col[V], col1_adj[10], col2_adj[10];
	int col1, col2, colour, q, count, flag, p = 0;
	for(q=0;q<V;q++)
		col[q] = 0;
	colour = 1;
		q = 0;
		label: do
		{
			if(col[p] != 0)
				p++;
		}while(p<V);
		if(p == V)
		{
			printf("colouring done ....chromatic no is %d\n", col - 1);
			exit(0);
		}	
		col[p] = colour;
		col1 = p;
		flag = V-1-vd[col1];
		*col1_adj = notadjset(col1,V,E);
		label1: if(col[col1_adj[q]] != 0)
		{
			if(q<flag)
				q++;
			else
			{
				p++;
				colour++;
				goto label;
			}
		}
		else
			col[col1_adj[q]] = colour;
		col2 = col1_adj[q];
		*col2_adj = notadjset(col2,V,E);
		count = 0;
		for(i=0;i<V-vd[col1]-1;i++)
		{
			for(l=0;l<V-1-vd[col2];l++)
			{
				if(col1_adj[i]==col2_adj[l])
				{
					col1_adj[count] = col1_adj[i];
					count++;
				}
			}
		}
		if(count != 0)
		{
			flag = count - 1;
			goto label1;
		}
		else
		{
			p++;
			colour++;
			goto label;
		}
}

void check(int E, int V)
{
	int i;
	for(i =0; i<V-1; i++)
	{
		if(vd[i] != vd[i+1])
			break;
	}
	if(i == V-1 && vd[i] == V-1)
	{
		printf("it is a complete graph.. so the chomatic no is %d\n", V);
		exit(0);
	}
	for(i =0; i<E; i++)
	{
		if(vd[i] != 2)
			break;
	}	
	if(i == E)
	{
		printf("the graph is a circuit with %d no of vertices .. so the chromatic no is\n", V);
		if(V%2 == 0)
			printf("2\n");
		else
			printf("3\n");
		exit(0);
	}
}

int* notadjset(int j, int V, int E)
{
	int flag, i, k;
	flag = vd[j];
	int hash[V];
	for(i=1; i<=V-1; i++)
		hash[i] = 0;
	for(i=0; i<E; i++)
	{
		if(e[i][0] == j)
		{
			hash[e[i][1]]++;
		}
		if(e[i][1] == j)
		{
			hash[e[i][0]]++;
		}
	}
	int unchk[V-flag-1];
	i = 0;
	for(k=0;k<=V-1;k++)
	{
		if(hash[k] == 0 && k != j)
		{
			unchk[i] = k;
			i++;
		}	
	}
	return *unchk;	
}	
	
