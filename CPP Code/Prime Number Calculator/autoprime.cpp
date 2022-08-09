//Prime Number Finder
//By Josh Miller 4-23-01
//Finds if a number is prime

#include<iostream.h>
#include<fstream.h>

void main()
{
	int number;
	int count;
	ofstream writer;
	int prime=1;

	writer.open("Primes.txt");

	for(number=1;number<100000;number++)
	{
	for(count=(number-1);count>1;count--)
	{
		if(number%count==0)
		{
			prime=0;
			count=0;
		}
	}

	if(prime==1)
	writer<<number<<" is Prime.\n";

	prime=1;
	}

	writer.close();

	return;
}