//Brutal Multiplication Game
//By Josh Miller 2-03-01

#include<iostream.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int num_cor=0, num_incor=0;
	int on_off=1;
	int guess;
	int a,b;
	char cont;

	while(on_off==1)
	{
		srand(time(0));

		a=rand()%1000000;
		b=rand()%1000000;

		cout << "What is " << a << " times " << b << " ?\n";
		cin >> guess;

		if(guess==(a*b))
		{
			cout << "\nYou are clearly cheating...\n";
			num_cor++;
		}
		else
		{
			cout << "Sorry you worthless fuck, maybe if you had half a brain in\n";
			cout << "your head you would have even the slightest comprehension\n";
			cout << "of what multiplication even is.  Why don't you go do something\n";
			cout << "more your speed, like drool?\n";
			num_incor++;
		}
		
		cout << "\nYou have cheated " << num_cor << " times and missed " << num_incor << " times.\n";
		cout << "Continue? (Y/N)\n";
		cin >> cont;

		if(cont=='N'||cont=='n')
			on_off=0;
	}

	cout << "\n\n\n\nThat's right you worthless sack of shit, go off and run away, go cry\n";
	cout << "to your fucking mommy.  Mommy mommy the computer is yelling at me and\n";
	cout << "calling me dirty names.  Why mommy?  I'll tell you why, cause you suck,\n";
	cout << "you are a waste of rescources and a drain on scociety, even the lowest\n";
	cout << "stupidest fucking bum could probably multiply " << a << " times " << b << ".\n";
	cout << "Now why don't you do us all a favor and go off your worthless fucking self,\n";
	cout << "cause we don't need shit like you around bitch.\n\n";

	cout << "\n\n\n Program created by Ramen Junkie.";
	cout << "\nPress any key then return to end the program.";
	cin >> cont;

	return 0;
}