//Bug Battle
//By Josh Miller
//4-30-01	- Started Work
//			- Created Game_Space Structure
//          - Created most of Spider Class
//          - Created Set_Up_Bugs()
//			- Created Show_Field (only displays Bugs)
//5-02-01	- Created Set_spiders
//			- Show_Field now shows Spiders as well (ny thier ID number)
//			- Added Move Spider

//NEXT: Spiders pick up other ID numbers when moving.  Fix this by either immidiately handling
//spider spider encounter, ensuring there is never more then one spider on a space or
//By adding multiple ID number to each space.

//Add encounters
//Add title
//Add Use status checking controls
//Add user control of a spider.

#include<iostream.h>
#include<time.h>
#include<stdlib.h>

struct Game_Space
{
	int numBugs;
	char BugType;
	int Spiders;
	int S_ID[5];
};

class Spider
{
private:
	int Strength;
	int P_Defense;
	int X_pos;
	int Y_pos;

public:
	Spider::Spider();
	int Get_STR();
	int Get_DEF();
	int Get_X();
	int Get_Y();
	void Kill_Spider();
	void Spider::Move_Spider(Game_Space Field[10][10], int count, Spider Spiders[]);
};

void Set_Up_Bugs(Game_Space Field[10][10]);
void Show_Field(Game_Space Field[10][10]);
void set_spiders(Game_Space Field[10][10], Spider Spiders[10]);
int Spider_Fight(Spider A, Spider B, int Anum, int Bnum);

void main()
{
	srand(time(0));

	int count;
	int breaker;

	Game_Space Field[10][10];
	Set_Up_Bugs(Field);
	Spider Spiders[10];
	set_spiders(Field, Spiders);

	do
	{
	Show_Field(Field);
	for(count=0;count<10;count++)
	{
		if(Spiders[count].Get_STR()>0)
			Spiders[count].Move_Spider(Field, count, Spiders);
	}
	cin>>breaker;
	}
	while(breaker);

	return;
}

//Sets up the Game field for bugs and type
void Set_Up_Bugs(Game_Space Field[10][10])
{
	int hori, vert;
	int count;

	for(hori=0;hori<10;hori++)
	{
		for(vert=0;vert<10;vert++)
		{
		if((rand()%100)<21)
		{
			if((rand()%100)>25)
			{
			Field[hori][vert].numBugs=((rand()%5)+3);
			Field[hori][vert].BugType='B';
			}
			else
			{
			Field[hori][vert].numBugs=((rand()%3)+1);
			Field[hori][vert].BugType='A';
			}
		}
		Field[hori][vert].Spiders=0;

		for(count=0;count<5;count++)
			Field[hori][vert].S_ID[count]=99;
		}
	}

	return;
}

//Displays the field to the screen
void Show_Field(Game_Space Field[10][10])
{
	int hori, vert;

	cout<<"     1   2   3   4   5   6   7   8   9   10\n";
	cout<<"  +------------------------------------------+\n";

	for(hori=0;hori<10;hori++)
	{
		if(hori<9)
			cout<<hori+1<<" |  ";
		else
			cout<<hori+1<<"|  ";

		for(vert=0;vert<10;vert++)
		{
		if(Field[hori][vert].numBugs>0)
//			cout<<"#   ";
			cout<<"    ";
		else if(Field[hori][vert].Spiders>0)
			cout<<Field[hori][vert].S_ID[0]<<"   ";
		else
			cout<<"    ";
//			cout<<Field[hori][vert].S_ID[0]<<"   ";
		}

		cout<<"|\n";

	}

	cout<<"  +------------------------------------------+\n";
	cout<<"# = Bug Colony   Numbers = Spiders\n";

	return;
}

//Set up the Spiders at the begining of the game on the field.
void set_spiders(Game_Space Field[10][10], Spider Spiders[10])
{
	int count;
	int spid1=0, spid2=0;

	for(spid1=0;spid1<10;spid1++)
	{
		for(spid2=(spid1+1);spid2<10;spid2++)
		{
			if(((Spiders[spid1].Get_X())==(Spiders[spid2].Get_X()))&&((Spiders[spid1].Get_Y())==(Spiders[spid2].Get_Y())))
			{
				cout<<"Spider "<<spid2<<" has not survived the release drop and has died.\n";
				Spiders[spid2].Kill_Spider();
			}
		}
	}
	cout<<endl;

	for(count=0;count<10;count++)
	{
	if(Spiders[count].Get_STR()>0)
	{
	Field[Spiders[count].Get_X()][Spiders[count].Get_Y()].Spiders=1;
	Field[Spiders[count].Get_X()][Spiders[count].Get_Y()].numBugs=0;
	Field[Spiders[count].Get_X()][Spiders[count].Get_Y()].S_ID[0]=count;
	}
	}

}

//Handles Spider Spider encounters
int Spider_Fight(Spider A, Spider B, int Anum, int Bnum)
{
	int rand_num;

	if(A.Get_STR()>B.Get_STR())
	{
	B.Kill_Spider();
	cout<<"Spider Number "<<Bnum<<" has been killed by Spider Number "<<Anum<<".\n";
	return Anum;
	}
	else if(B.Get_STR()>A.Get_STR())
	{
	A.Kill_Spider();
	cout<<"Spider Number "<<Anum<<" has been killed by Spider Number "<<Bnum<<".\n";
	return Bnum;
	}
	else
	{
		rand_num=(rand()%10)+1;
		if(rand_num<=5)
		{
			B.Kill_Spider();
			cout<<"Spider Number "<<Bnum<<" has been killed by Spider Number "<<Anum<<".\n";
			return Anum;
		}
		else
		{
			A.Kill_Spider();
			cout<<"Spider Number "<<Anum<<" has been killed by Spider Number "<<Bnum<<".\n";
			return Bnum;
		}
	}
}

//Contructor Function for Spiders
Spider::Spider()
{
	Strength=5;
	P_Defense=0;
	X_pos=(rand()%10);
	Y_pos=(rand()%10);
}
//Member Spider Functions
int Spider::Get_STR()
{return Strength;}

int Spider::Get_DEF()
{return P_Defense;}

int Spider::Get_X()
{return X_pos;}

int Spider::Get_Y()
{return Y_pos;}

void Spider::Kill_Spider()
{X_pos=-1; Y_pos=-1; Strength=0;}

void Spider::Move_Spider(Game_Space Field[10][10], int count, Spider Spiders[])
{
	int rand_move;

	cout<<Strength<<" ";

	rand_move=(rand()%4);

	Field[X_pos][Y_pos].Spiders=0;
	Field[X_pos][Y_pos].S_ID[0]=99;

	if(rand_move==0)
		{
		X_pos++;
		if(X_pos>9)
			X_pos=0;
		}
	else if(rand_move==1)
		{
		Y_pos++;
		if(Y_pos>9)
			Y_pos=0;
		}
	else if(rand_move==2)
		{
		X_pos--;
		if(X_pos<0)
			X_pos=9;
		}
	else
		{
		Y_pos--;
		if(Y_pos<0)
			Y_pos=9;
		}

		Field[X_pos][Y_pos].Spiders=1;

		if(Field[X_pos][Y_pos].S_ID[0]==99)
			Field[X_pos][Y_pos].S_ID[0]=count;
		else
		{
		Field[X_pos][Y_pos].S_ID[0]=Spider_Fight(Spiders[count], Spiders[Field[X_pos][Y_pos].S_ID[0]],
					 count, Field[X_pos][Y_pos].S_ID[0]);
		}
}

