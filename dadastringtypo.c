#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void Built();
void fill(int ,int ,int);
void display();

char typocheck[94][15];				//main typo reult array	
char keyboard1[4][14];				//Keyboard layout with out shift
char keyboard2[4][14];				//Keyboard layout with shift

int main(void)
{
	int length;
	char arr[100];
	printf("Enter the String\n");
	scanf("%s", arr);
	length = strlen(arr);
	//Transformation(arr, length);
	Built();
	display();
}

//int Transformation(char *arr, int l)
//{
//	int i;
//	char ar[5][l];
//	for(i=0;i<n;i++)
//	{
//		strcpy(*ar[i], arr);
//	}
//	*ar[0] = touper(arr);	
//	*ar[1] = tolower(arr);
//	strcpy(*ar[flag], arr);
//	ar[2][l-1] = NULL;
//	ar[3][l] = ar[3][l-1];
//	Built();
//	}
//	display();
//}
//
void Built()
{
	char buffer[14];
	int i, j;
	FILE *fp = fopen("qwerty.txt", "r");
	for(i=0;i<8;i++)
	{
		fscanf(fp,"%s", buffer);
		printf(" %s 1\n", buffer);
		for(j=0;j<14;j++)
		{
			if(i<4)
				keyboard1[i][j] = buffer[j];
			else
				keyboard2[i-4][j] = buffer[j];
		}
	}
	int cnt = 0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<14;j++)
		{
			if(keyboard1[i][j]!= " ")
			{	
				typocheck[cnt][0] = keyboard1[i][j];
				fill(i,j,cnt);
				cnt++;
			}
//			typocheck[cnt][0] = keyboard2[i][j];
//			fill(i,j);
//			cnt++;
		}
	}
}

void fill(int x, int y, int index)
{
	int yind = 1;
	if(0<x && keyboard1[x-1][y](int)!=32)
	{
		typocheck[index-1][yind] = keyboard1[x-1][y];
		yind++;
		typocheck[index-1][yind] = keyboard2[x-1][y];
		yind++;
	}
	else if(0<x && y<13 && keyboard1[x-1][y+1]!=" ")
	{
		typocheck[index-1][yind] = keyboard1[x-1][y+1];
		yind++;
		typocheck[index-1][yind] = keyboard2[x-1][y+1];
		yind++;
	}
	else if(0<y &&  keyboard1[x][y-1]!=" ")
	{
		typocheck[index-1][yind] = keyboard1[x][y-1];
		yind++;
		typocheck[index-1][yind] = keyboard2[x][y-1];
		yind++;
	}
	else if(y<13 &&  keyboard1[x][y+1]!=" ")
	{
		typocheck[index-1][yind] = keyboard1[x][y+1];
		yind++;
		typocheck[index-1][yind] = keyboard2[x][y+1];
		yind++;
	}
	else if(x<3)
	{
		if(0<y && keyboard1[x+1][y-1]!=" ")
		{
			typocheck[index-1][yind] = keyboard1[x+1][y-1];
			yind++;
			typocheck[index-1][yind] = keyboard2[x+1][y-1];
			yind++;
		}
		else if(keyboard1[x+1][y]!=" ")
		{
			typocheck[index-1][yind] = keyboard1[x+1][y-1];
			yind++;
			typocheck[index-1][yind] = keyboard2[x+1][y-1];
			yind++;
		}
	}
}

void display()
{
	int i, j;
	for(i=0;i<94;i++)
	{
		for(j=0;j<14;j++)
		{
			printf(" %c ", typocheck[i][j]);
		}
		printf("\n");
	}
}
 
