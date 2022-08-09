// Math Problem Generator
// by Josh Miller
// lameazoid@gmail.com
// Generates a text file containing randomly generated multiplication problems.
// 06.06.06

#include<iostream.h>
#include<fstream.h>
#include<math.h>

void main(void)
{

	ofstream writer("Math Problems.txt");
	int numeral;
	int looper;
	int looper2;


	looper==1;
	looper==2;


	for(looper2<8,looper2++)
	{
		for(looper<8,looper++)
		{
			writer<<"     ";
			numeral==rand*10;
			writer<<numeral;
		}

		writer<<"\n";

		for(looper<8,looper++)
		{
			writer<<"   + ";
			numeral==rand*10;
			writer<<numeral;
		}

		writer<<"\n";
		writer<<"   ---   ---   ---   ---   ---   ---   ---   ---\n \n \n \n \n";
		}
	}

	return;


}