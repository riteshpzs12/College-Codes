#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int cnt,score,move,lvl;					//cnt the number of afected ones, score the required score,move left moves,lvl counter......
int a[20][20];							//I TRIED TO NOT TO MAKE IT GLOBAL ......BUT THIS HELPS...

int main(void)
{
	int i, j, x, y, flag; //array declaretion, loop vriable , flag pointer, user coordinates;
	for(i=0;i<20;i++)
		for(j=0;j<20;j++)
			a[i][j]=0;
//	stg_cnt = 0;                        //initially 0.
	score = 0;
	fillup(**a);                      // calling the function to fill up the matrix... 1st call
	display(a);						    // shows the matrix situation.....1st call
	for(;;)
	{
		printf("\n\nenter input, coordinate\n");
		scanf("%d", &x);                     //scanning the inpuuts
		scanf("%d", &y);
		input_check(a,x,y);
	}
}

void fillup(int **a)
{
	int i, j;
	for(i=0;i<20;i++)
		for(j=0;j<20;j++)
		{
			if(a[i][j] == 0)
				a[i][j] = rand()%5;
		}
}

void display(int **a)                    //the whole printing part;
{
	int i, j, ch;
	printf("   ");
	for(j=0;j<20;j++)
		printf(" %d ", j);
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			printf(" %d  ", i);
			ch = a[i][j];
			switch(ch)
			{
				case 1:printf(" * ");
				case 2:printf(" $ ");
				case 3:printf(" # ");
				case 4:printf(" @ ");
				case 0:printf("   ");
			}
			printf("|");
		}	
		printf("\n");
		for(i=0;i<60;i++)
			printf("_");
	}
}

void input_check(int **a, int x, int y)
{
	if(a[x][y] == 0)                            //checks if the input is in null postion;
	{
		printf("\ninvalid input.........try again...\n");
		return;                                  //if yes then return and tells to take input again;
	}
	else
	{
		blaststack(a,x,y);                        //blast stack creates the stack of the blocks that are blasting for the particular input...and if 
		printf("\ninput not apropriate.......\n");//it exceeds the minimum requirement then the input is valid and the working functions start calling
		return;                                   //each other in cahin.. if not then it returns here with the invalid input and then returns to the
	}                                             //to the main fuction for taking input again;
}

void blaststack(int **a, int x, int y)             //creates the stack of blasting blocks;
{
	int i, j, flag;                    //two variable, a counter, the user input number/color that are going to blast in chain, a flag;
	static int adj[20][20];            //check matrix for tagging those nodes whose surrounding nodes are checked,adj matrix creates the
	cnt = 1;                           //adjacency list .. by nonzero it means that it is in blast radius, 0 means unaffected;
	adj[x][y] = 1;
	traverse(a,x,y,adj);
	if(cnt<2)
		return;
	shift(a,adj);					//shifts the whole universe,, KIDDING.... shifts columnwise as lot of blocks are destroyed.
	display(a);
	stagecheck(a);					//check the player is still allowed to play...
	gamecheck();					//HARD PART ""CHATTTER"" HELP ME HERE..
}

void traverse(int **a,int x,int y,int **adj)    //traverses the whole chain way and counts and keeps track in adj matrix of affected blocks....
{      											
	if(a[x+1][y]==a[x][y]&&adj[x+1][y]==0)		//takes the current node and finds those it can affect and creates a recurssive loop..if the data of
	{											//x,y co ordinate is not entered already then assign it in adj matrix and makes it the current node..
		adj[x+1][y]	= cnt;
		cnt++;									//counts the total no of affected matrix for scoring  purpose..
		traverse(a,x+1,y,adj);					//recursive call......1st
	}
	if(a[x-1][y]==a[x][y]&&adj[x-1][y]==0)
	{
		adj[x-1][y]	= cnt;
		cnt++;
		traverse(a,x-1,y,adj);
	}
	if(a[x][y+1]==a[x][y]&&adj[x][y+1]==0)
	{
		adj[x][y+1]	= cnt;
		cnt++;
		traverse(a,x,y+1,adj);
	}
	if(a[x][y-1]==a[x][y]&&adj[x][y-1]==0)
	{
		adj[x][y-1]	= cnt;
		cnt++;
		traverse(a,x,y-1,adj);
	}
}

void shift(int  **a, int **adj)		//after destroy the affectedd ones the columnwise shift happens ...
{
	int i, j, k;
	for(i=0;i<20;i++)
		for(j=0;j<20;j++)
		{
			if(adj[i][j]>0)
			{
				for(k=i;k>0;k--)
					a[k][j] = a[k-1][j];		//the shift line
			}
			a[0][j] = 0;		//and for each shift the value of the top most shifted block is made to 0.........
			adj[i][j] = 0;		//destroyed ones are made ack to 0 in adj matix.........
		}
}

void stagecheck()
{
	int cur_scr,high_scr;					//current score..
	FILE *fp;
	if(move == 1)							//checks if it is the last allwed move,.........
	{
		if(cnt*cnt>=score)					// checks if he surives in that move,, means he achieves the score target.........
			lvl++;
		else								//if not then its a game over........
		{
			fp = fopen("r","save.txt");
			printf("game over...\n");		//print the game ending line...
			fscanf(fp,"%d",&cur_scr);
			cur_scr = cur_scr + cnt*cnt;
			printf("your score....%d\n",cur_scr); //shows the final score......
			fscanf(fp,"%d",&high_scr);				
			if(high_scr<cur_scr)					//checks if the current score got past the previous high score...
				printf("CONGO,,, YOU HAVE MADE A NEW HIGH ScORE");
			move--;
			fclose fp;
			savedata(cur_scr);						// tracking it all in the file...
			exit(0);
		}
		move = 10 + (lvl - 1)*5;					// if he survives then update the remaining move and require score..
		score = (pow(2,lvl-1))*1000;
		fp = fopen("r","save.txt");
		fscanf(fp,"%d",&cur_scr);		
		cur_scr = cur_scr + cnt*cnt;
		savedata(cur_scr);							// track it all bla blah blah.....
		fclose fp;
	}	
	else if(cnt*cnt>=score)							// if he achieves the goal before before the last move .......NEED HELP HERE RAHUL CHATTER
	{												// GIVE ME ANY IDEA TO MAKE THIS FUNCTION LOOK LIKE A LITTLE ''SMART'''..
		lvl++;
		move = 10 + (lvl - 1)*5;
		score = (pow(2,lvl-1))*1000;
		fp = fopen("r","save.txt");
		fscanf(fp,"%d",&cur_scr);
		cur_scr = cur_scr + cnt*cnt;
		savedata(cur_scr);
		fclose fp;
	}
	else
	{
		fp = fopen("r","save.txt");					// normal case where happens nothing.....
		fscanf(fp,"%d",&cur_scr);
		cur_scr = cur_scr + cnt*cnt;
		move--;										// reducing the rem.. moves....
		score = score - cnt*cnt;					//incresing current score.......
		savedata(cur_scr);							//track it all......
	}	
}

void savedata(int scr)
{
	FILE *fp;
	int i,j;
	fp = fopen("rw+","save.txt");
	fprintf(fp,"%d",scr);
	fscanf(fp,"%d",i);
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			fprintf(fp,"%d",a[i][j]);
		}
		fprintf(fp,"\n");
	}
	fclose fp;
}











