// Tug of War Game - For 1 player.
//Written by Josh Miller 1/31/01
//1/31/01 - Started programming, added the Computer Brain
//2/07/01 - Worked on visual set up, worked on initial game workings
//2/08/01 - Initial Debugging

#include<iostream.h>
#include<stdlib.h>
#include<time.h>

int computer_brain(int location, int round_num, int pbank, int cbank);

int main()
{
	int location=0, pbank=50, cbank=50, cspend, round_num=1, pspend, check=1, check2=1;
	char again, inst_ask;
	int wins=0, score=0, rules=1, games=0;

	srand(time(0));

// The following creates the title screen.
// he program is set up so the game board will appear in the initial zero position at the title.

	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "                      Welcome to Tug of War\n";
	cout << "                   Programmed by Josh Miller\n";
	cout << "           Computer Brain created by Kirk Yenerall\n";

	do
	{
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "                           Round " << round_num << endl;
	cout << "\n";
	cout << "  CPU                                                   You\n";
	cout << "+-----+  +-----+  +-----+  +-----+  +-----+  +-----+  +-----+\n";

// This code is used to display the correct board position for where the game piece is.

	if(location==0)
		{
		cout << "|     |  |     |  |     |  |  *  |  |     |  |     |  |     |\n";
		cout << "| -3  |  | -2  |  | -1  |  | *** |  |  1  |  |  2  |  |  3  |\n";
		cout << "|     |  |     |  |     |  |  *  |  |     |  |     |  |     |\n";
		}
	else if(location==1)
		{
		cout << "|     |  |     |  |     |  |     |  |  *  |  |     |  |     |\n";
		cout << "| -3  |  | -2  |  | -1  |  |  0  |  | *** |  |  2  |  |  3  |\n";
		cout << "|     |  |     |  |     |  |     |  |  *  |  |     |  |     |\n";
		}
	else if(location==-1)
		{
		cout << "|     |  |     |  |  *  |  |     |  |     |  |     |  |     |\n";
		cout << "| -3  |  | -2  |  | *** |  |  0  |  |  1  |  |  2  |  |  3  |\n";
		cout << "|     |  |     |  |  *  |  |     |  |     |  |     |  |     |\n";
		}
	else if(location==2)
		{
		cout << "|     |  |     |  |     |  |     |  |     |  |  *  |  |     |\n";
		cout << "| -3  |  | -2  |  | -1  |  |  0  |  |  1  |  | *** |  |  3  |\n";
		cout << "|     |  |     |  |     |  |     |  |     |  |  *  |  |     |\n";
		}
	else if(location==-2)
		{
		cout << "|     |  |  *  |  |     |  |     |  |     |  |     |  |     |\n";
		cout << "| -3  |  | *** |  | -1  |  |  0  |  |  1  |  |  2  |  |  3  |\n";
		cout << "|     |  |  *  |  |     |  |     |  |     |  |     |  |     |\n";
		}
	else
		{
		cout << "\nOne of the game peramiters has become corupt...\n";
		return 0;
		}


	cout << "+-----+  +-----+  +-----+  +-----+  +-----+  +-----+  +-----+\n";
	cout << "  " << cbank << "                                   ";
	cout << "                  " << pbank << endl;
	cout << "Points                                                 Points\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";

// Checks the first time playing if the player wishes to read instructions for the game.

	if(rules==1)
		{
		cout << "\nDo you want instructions? (Y/N)\n";
		cin >> inst_ask;

		if((inst_ask=='Y')||(inst_ask=='y'))
			{
			cout << "\nHow to Play\n";
			cout << "The object of the game is to move the marker to your end of the board\n";
			cout << "before the computer moves the marker to it's end.  You move the marker\n";
			cout << "by betting points.  The player who bets the most points each round\n";
			cout << "wins the round and has the marker moved one space towards thier end of\n";
			cout << "the board.  Each player begins with 50 points to spend each game.  If\n";
			cout << "both players run out of points before the end of the game, the game is\n";
			cout << "a draw.  If you win you are awarded 50 points (score points not\n";
			cout << "spending points) plus the remaining points in your bank.\n";
		}
		
		rules=0;
		}
	

// Collects the numbe of points the player wished to spend and checks to
// ensure they don't spend more or less than allotocated.

		do
		{
		cout << "\nHow many points do you wish to spend?\n";
		cin >> pspend;

		if (pspend<0)
			{
			cout << "\nYou can't wager a negative value...\n";
			}
		else if(pspend>pbank)
			{
			cout << "\nYou can't spend more points than you have...\n";
			}

		}
		while((pspend<0)||(pspend>pbank));

	cspend=computer_brain(location, round_num, pbank, cbank);

	pbank=pbank-pspend;
	cbank=cbank-cspend;

	cout << "\nThe computer spends: " << cspend << " points.\n";

// Thsi checks to see who wins each round.
	
	if(pspend>=cspend)
		{
		cout << "\nYou have won this round.\n";
		location++;
		}
	else
		{
		cout << "\nYou loose this round.\n";
		location--;
		}

// This checks to see if either player has won the game.
// It also keeps track of the score of the game, 50 points for a win.
// Plus the remaining bank of points for each win.

	if(location==3)
		{
		cout << "\n\n\nCongratulations!  You have won the game!\n\n";
		score=score+pbank+50;
		wins++;
		check++;
		}
	else if(location==-3)
		{
		cout << "\n\n\nToo bad, you have lost this game.\n\n";
		check++;
		}
	else if((pbank==0)&&(cbank==0))
		{
		cout << "\n\n\nThe game is a draw, both players are out of points.\n\n";
		check++;
		}

	round_num++;

// This is used to see if the player wishes to go another round.
// It will reset the playing field if the player wishes to go on.

	if(check!=1)
		{
		games++;
		cout << "\nYour score so far is " << score << " points.";
		cout << "\nYou have " << wins << " wins.";
		cout << "\nYou have played " << games << " games.";
		cout << "\nDo you wish to play again? (Y/N)\n";
		cin >> again;

		if((again=='Y')||(again=='y'))
			{
			check=1;
			location=0;
			pbank=50;
			cbank=50;
			round_num=1;
			}
		else
			cout << "\nPlay again soon!\n";
			cout << "\nBe sure to see the Tug of War homepage at:";
			cout << "\nhttp://www.geocites.com/Tokyo/Pagoda/6098/Tugwar.\n\n";
		}

	}
	while(check==1);


	return 0;
}

int computer_brain(int location, int round_num, int pbank, int cbank)
{
	int allotment, strategy=rand() % 100;

	if((pbank==0)&&(cbank>0))
		return 1;

	if((location==-2)&&(cbank>pbank))
		return (pbank+1);

	if (strategy>75)
		allotment=pbank/2;
	else if(strategy>50)
		allotment=cbank/2;
	else if((strategy>25) && (round_num !=5))
		allotment=int(cbank/abs(5-round_num));
	else
		allotment=rand()%(cbank+1);

	allotment+= (rand() %3);

	if (allotment>cbank)
		allotment=cbank/2;

	return allotment;
}
