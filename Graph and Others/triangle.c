#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void cross(int,int,int,int);
//void find(int **);

int rescheck;
int a[3][2];

int main(void)
{
	int n, count = 0;   //n number of test cases, array for the co ordinate of the 3 point,  count -- counter;
	int i,j,cnt;
	int chk[2][2];
	printf("enter the number of test cases\n");
	scanf("%d", &n);
	while(n>0)
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<2;j++)
			{
				scanf("%d", &a[i][j]);
			}
		}
		n--;
		while(cnt<2)
		{
			chk[cnt][0] = max(cnt);
			chk[cnt][1] = min(cnt);
			cnt++;
		}
		if(chk[0][0]*chk[0][1]<=0 && chk[1][0]*chk[1][1]<=0)
		{
			find();
			if(rescheck != -7777)
				count++;
		}	
	}
	printf("%d",count);
}
void find()
{
	int x1,y1,x2,y2,i;
	rescheck = -9999;
	for(i=0;i<3;i++)
	{
		x1 = a[(i+1)%3][0] - a[i][0];
		x2 = a[i][0];
		y1 =a[(i+1)%3][1] - a[i][1];
		y2 = a[i][1];
		cross(x1,y1,x2,y2);
	}
}

void cross(int ax,int ay,int bx,int by)
{
	int tmp = 0;
	if(rescheck == -9999)
		rescheck = ax*by - ay*bx;
	else if(rescheck == -7777)
		return;
	else
	{
		tmp = ax*by - ay*bx;
		if(tmp*rescheck<0)
			rescheck = -7777;
		else
			rescheck = tmp;
	}
}
int min(cnt)
{
	int x,y,z;
	x = a[0][cnt];
	y = a[1][cnt];
	z = a[3][cnt];
	if(x<y)
	{
		if(x<z)
			return x;
		else
			return z;
	}
	else
		if(y<z)
			return y;
		else
			return z;
}

int max(cnt)
{
	int x,y,z;
	x = a[0][cnt];
	y = a[1][cnt];
	z = a[3][cnt];
	if(x>y)
	{
		if(x>z)
			return x;
		else
			return z;
	}
	else
		if(y>z)
			return y;
		else
			return z;
}

