//Bug Battle v2.04
//By Josh Miller
//5-06-01 - Restarted coding
//		  - Added Spider Class
//        - Added Space Structure
//        - Added Board_Set_Up
//        - Added Add_ID

#include<iostream.h>
#include<time.h>
#include<stdlib.h>

struct Space
{
	int numBugs;
	char BugType;
	int NumSpiders;
	int S_IDs[4];
};

class Spider
{
private:
	int Strength;
	int Poison_Def;
	int X_coord;
	int Y_coord;
	int IDnum[2];
public:
	Spider::Spider();
	int GetSTR();
	int GetDEF();
	int GetXpos();
	int GetYpos();
	int GetIDnum();
	int GetIDpos();
	void setID(int count);
	void SetIDspace(int num);
};

void Board_Set_Up(Space Board[10][10], Spider Spdrs[10]);
int Add_ID(int Number, Space Cur_Space);

void main()
{
	srand(time(0));
	
	breaker should return to 1 for real running
	int count, hori, vert, breaker=0;
	Spider Spdrs[10];
	Space Board[10][10];

	for(count=0;count<10;count++)
		Spdrs[count].setID(count);

	Board_Set_Up(Board, Spdrs);

	do
	{
	for(hori=0;hori<10;hori++)
	{
		for(vert=0;vert<10;vert++)
		{
	//FIGHT SPIDERS
	//FIGHT BUGS
		}
	}
	//SHOW BOARD
	//MOVE BUGS
	}
	while(breaker);
}

void Board_Set_Up(Space Board[10][10], Spider Spdrs[10])
{
	int hori, vert;
	int count;

//For loops set up the bugs at random
	for(hori=0;hori<10;hori++)
	{
		for(vert=0;vert<10;vert++)
		{
			if((rand()%100)<21)
			{
				if((rand()%100)>25)
				{
				Board[hori][vert].numBugs=((rand()%5)+3);
				Board[hori][vert].BugType='B';
				}
				else
				{
				Board[hori][vert].numBugs=((rand()%3)+1);
				Board[hori][vert].BugType='A';
				}
			}
			else
			{
				Board[hori][vert].numBugs=0;
				Board[hori][vert].BugType='N';
			}
			Board[hori][vert].NumSpiders=0;
			
			for(count=0;count<4;count++)
			{
			Board[hori][vert].S_IDs[count]=99;
			}
		}
	}

//For loop sets up spiders on the board.
	for(count=0;count<10;count++)
	{
		Board[Spdrs[count].GetXpos()][Spdrs[count].GetXpos()].BugType='N';
		Board[Spdrs[count].GetXpos()][Spdrs[count].GetXpos()].numBugs=0;
		Board[Spdrs[count].GetXpos()][Spdrs[count].GetXpos()].NumSpiders++;
		Spdrs[count].SetIDspace(Add_ID(count, Board[Spdrs[count].GetXpos()][Spdrs[count].GetXpos()]));
	}
}

//Adds an ID number to a game square.  It cheks for an empty space and adds the spider.
int Add_ID(int Number, Space Cur_Space)
{
	int count;

	for(count=0;count<4;count++)
	{
		if(Cur_Space.S_IDs[count]==99)
		{
			Cur_Space.S_IDs[count]=Number;
			count=10;
		}
	}
	return count;
}

//spider Constructor Fucntion
Spider::Spider()
{
	Strength=5;
	Poison_Def=0;
	X_coord=(rand()%10);
	Y_coord=(rand()%10);
}

//Spider Accessor Functions
int Spider::GetSTR()
{return Strength;}
int Spider::GetDEF()
{return Poison_Def;}
int Spider::GetXpos()
{return X_coord;}
int Spider::GetYpos()
{return Y_coord;}
int Spider::GetIDnum()
{return IDnum[0];}
int Spider::GetIDpos()
{return IDnum[1];}
//Other Member Functions
void Spider::setID(int count)
{IDnum[0]=count;}
void Spider::SetIDspace(int num)
{IDnum[1]=num;}