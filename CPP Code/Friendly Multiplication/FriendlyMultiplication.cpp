//Friendly Multiplication Game
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

		a=rand()%11;
		b=rand()%11;

		cout << "What is " << a << " times " << b << " ?\n";
		cin >> guess;

		if(guess==(a*b))
		{
			cout << "\nCorrect!  Good Job!\n";
			num_cor++;
		}
		else
		{
			cout << "Sorry, that is not right, correct answer is: " << a*b << ".\n";
			num_incor++;
			cout << "Please try harder!  You can do it!";
		}
		
		cout << "\nYou have " << num_cor << " correct and " << num_incor << " missed.\n";
		cout << "Continue? (Y/N)\n";
		cin >> cont;

		if(cont=='N'||cont=='n')
			on_off=0;
	}

	return 0;
}