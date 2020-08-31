#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define fr(i,p,q) for(i=p;i<q;i++)

void win(int);
void check(int);
void blast(int,int,int);
void input(int,int,int);
void print();

int a[20][20];

int main()
{
	int i, j, x, y, count, n, cnt, win_check = 0;
	count = 0;
	fr(i,0,10)
		fr(j,0,10)
		{
			a[i+5][j+5] = 0;
		}
	printf("enter number of players(2-6)\n");
	scanf("%d", &n);
	if(n == 2)
		printf("player 1 --> *\t player 2 --> #\n");
	else if(n == 3)
		printf("player 1 --> *\t player 2 --> #\t player 3 --> @\n");
	else if(n == 4)
		printf("player 1 --> *\t player 2 --> #\t player 3 --> @\t player 4 --> $\n");			
	else if(n == 5)
		printf("player 1 --> *\t player 2 --> #\t player 3 --> @\t player 4 --> $\t player 5 --> &\n");
	else if(n == 6)
		printf("player 1 --> *\t player 2 --> #\t player 3 --> @\t player 4 --> $\t player 5 --> &\t player 6 --> ?\n");	
	print();
	for(;;)
	{
		cnt = count%n + 1;
		printf("enter co rodinate for player %d\n", cnt);
		printf("enter x corodinate -  ");
		scanf("%d", &y);
		printf("enter y corodinate - ");
		scanf("%d", &x);
		printf("\n");
		if(a[x+5][y+5]==0||a[x+5][y+5]/10==cnt)
		{
			input(x,y,cnt);
			count++;
			win_check++;
			print();
			if(win_check>n)
				win(cnt);
		}
		else
			printf("invalid input\n   TRY AGAIN\n");
	}
}

void input(int x, int y, int cnt)
{
	if(a[x+5][y+5]==0)
		a[x+5][y+5] = cnt*10 + 1;
	else
		a[x+5][y+5]++;
	check(cnt);
}

void check(int cnt)
{
	int i, j, chk = 0;
	fr(i,0,10)
		fr(j,0,10)
		{
			if(i==0||i==9||j==0||j==9)
			{
				if(i+j==9||i==j)
				{
					if(a[i+5][j+5]%10>1)
					{
						blast(i+5,j+5,cnt);
						a[i+5][j+5] = a[i+5][j+5] - 2;
						chk++;
					}
				}
				else
				{
					if(a[i+5][j+5]%10>2)
					{
						blast(i+5,j+5,cnt);
						a[i+5][j+5] = a[i+5][j+5] - 3;
						chk++;
					}
				}
			}
			else
			{
				if(a[i+5][j+5]%10>3)
				{
					blast(i+5,j+5,cnt);
					a[i+5][j+5] = a[i+5][j+5] - 4;
					chk++;
				}
			}
			if(a[i+5][j+5]%10 == 0)
				a[i+5][j+5] = 0;
		}
	if(chk>0)
		check(cnt);
}

void blast(int i, int j, int cnt)
{
//	printf("calling blast in %d  %d\n", i, j);
	a[i+1][j] = a[i+1][j]%10 + cnt*10 + 1;
	a[i][j+1] = a[i][j+1]%10 + cnt*10 + 1;
	a[i][j-1] = a[i][j-1]%10 + cnt*10 + 1;
	a[i-1][j] = a[i-1][j]%10 + cnt*10 + 1;
}

void win(int cnt)
{
	int m, n, flag = 0;
	fr(m,0,10)
		fr(n,0,10)
		{
			if(a[m+5][n+5]/10 != 0&&a[m+5][n+5]/10 != cnt)
				flag = 1;
		}
		if(flag == 0)
		{
			printf("player %d wins the game\n", cnt);
			exit(0);
		}
}

void print()
{
	int i, j, ch, no;
	printf(" \t");
	fr(j,0,10)
		printf(" %d   ", j);
	printf("\n\n");
	fr(i,0,10)
		{
			printf("%d\t", i);
			fr(j,0,10)
			{
				ch = a[i+5][j+5]/10;
				if(ch>0)
					{
						if(ch == 1)
							printf("%d* ", a[i+5][j+5]%10);
						else if(ch == 2)
							printf("%d# ", a[i+5][j+5]%10);
						else if(ch == 3)
							printf("%d@ ", a[i+5][j+5]%10);
						else if(ch == 4)
							printf("%d$ ", a[i+5][j+5]%10);
						else if(ch == 5)
							printf("%d& ", a[i+5][j+5]%10);
						else if(ch == 6)
							printf("%d? ", a[i+5][j+5]%10);
						}					
					else
						printf("   ");
						printf("||");	
				}
				printf("\n\t");
				fr(no,0,10)
						printf("---  ");	
				printf("\n");
			}
}
