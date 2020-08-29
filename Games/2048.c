#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//hiiiiiii
int a[4][4];

void upswipe();
void rightswipe();
void downswipe();
void leftswipe();
void swipe(int,int,int,int);
void add();
void print();

int main()
{
	int ch;
	add();
	for(;;)
	{
		add();
		print();
		printf("\tEnter 1 for upswipe\n\t2 for right swipe\n\t3 for downswipe\n\t4 for leftswipe\n");
		scanf("%d", &ch);
		if(ch==1)
			upswipe();
		else if(ch==2)
			rightswipe();
		else if(ch==3)
			downswipe();
		else if(ch==4)
			leftswipe();
		else
			printf("wrong choice\n");
	}
}

void upswipe()
{
	int loc, i, j, s, cnt, ch;
	ch = 1;
	for(j=0;j<4;j++)
	{
		s = 9999;
		cnt = 0;
		loc = 3;
		while(loc>=cnt)
		{
			if(a[cnt][j]==0)
			{
				swipe(ch,cnt,loc,j);
				loc--;
			}
			else if(s == a[cnt][j])
			{
				a[cnt-1][j] = 2*s;
				s = 9999;
				swipe(ch,cnt,loc,j);
				loc--;
			}
			else
			{
				s = a[cnt][j];
				cnt++;
			}	
		}
	}
}

void rightswipe()
{
	int loc, i, j, s, cnt, ch;
	ch = 2;
	for(j=0;j<4;j++)
	{
		s = 9999;
		cnt = 3;
		loc = 0;
		while(loc<=cnt)
		{
			if(a[j][cnt]==0)
			{
				swipe(ch,cnt,loc,j);
				loc++;
			}
			else if(s == a[j][cnt])
			{
				a[j][cnt+1] = 2*s;
				s = 9999;
				swipe(ch,cnt,loc,j);
				loc++;
			}
			else
			{
				s = a[j][cnt];
				cnt--;
			}	
		}
	}
}

void downswipe()
{
	int loc, i, j, s, cnt, ch;
	ch = 3;
	for(j=0;j<4;j++)
	{
		s = 9999;
		cnt = 3;
		loc = 0;
		while(loc<=cnt)
		{
			if(a[cnt][j]==0)
			{
				swipe(ch,cnt,loc,j);
				loc++;
			}
			else if(s == a[cnt][j])
			{
				a[cnt+1][j] = 2*s;
				s = 9999;
				swipe(ch,cnt,loc,j);
				loc++;
			}
			else
			{
				s = a[cnt][j];
				cnt--;
			}	
		}
	}
}
void leftswipe()
{
	int loc, i, j, s, cnt, ch;
	ch = 4;
	for(j=0;j<4;j++)
	{
		s = 9999;
		cnt = 0;
		loc = 3;
		while(loc>=cnt)
		{
			if(a[j][cnt]==0)
			{
				swipe(ch,cnt,loc,j);
				loc--;
			}
			else if(s == a[j][cnt])
			{
				a[j][cnt-1] = 2*s;
				s = 9999;
				swipe(ch,cnt,loc,j);
				loc--;
			}
			else
			{
				s = a[j][cnt];
				cnt++;
			}	
		}
	}
}

void swipe(int ch, int cnt, int loc, int j)
{
	int i;
	if(ch == 1)
	{
		for(i=cnt;i<loc;i++)
		{
			a[i][j] = a[i+1][j];
		}		
		a[loc][j] = 0;
	}
	if(ch == 2)
	{
		for(i=cnt;i>loc;i--)
		{
			a[j][i] = a[j][i-1];
		}		
		a[j][loc] = 0;
	}
	if(ch == 3)
	{
		for(i=cnt;i>loc;i--)
		{
			a[i][j] = a[i-1][j];
		}		
		a[loc][j] = 0;
	}
	if(ch == 4)
	{
		for(i=cnt;i<loc;i++)
		{
			a[j][i] = a[j][i+1];
		}		
		a[j][loc] = 0;
	}
}

void add()
{
	int c, b;
	do{
		c = rand()%4;
		b = rand()%4;
	}while(a[c][b] != 0);
	a[c][b] = (rand()%2 + 1)*2;
}

void print()
{
	int m, n;
	for(m=0;m<4;m++)
	{
		for(n=0;n<4;n++)
			printf("%4d", a[m][n]);
		printf("\n");
	}
}

